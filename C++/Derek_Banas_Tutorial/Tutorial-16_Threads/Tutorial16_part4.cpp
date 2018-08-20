// ----- CALCULATE PRIMES WITH THREADS -----

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <mutex>

std::mutex vectLock; // Used to protect writing to the vectors
std::vector<unsigned int> primeVect;

// Function to create a vector of primes between a range of values
void FindPrimes(unsigned int start, unsigned int end)
{
    // Cycle through numbers while ignoring evens
    for (unsigned int x = start; x <= end; x += 2)
    {
        // If a modulus is 0 we know it isn't prime
        for (unsigned int y = 2; y < x; y++)
        {
            if ((x % y) == 0)
                break;
            else if ((y + 1) == x) 
            {
                vectLock.lock();
                primeVect.push_back(x);
                vectLock.unlock();
            }
        }
    }
}

// Function to create a vector of primes between a range of values with threads
// This is only faster for a very large number of values, as there is a degree 
// of overhead involved in creating threads. Machine time is devoted to creating
// threads
void FindPrimesWithThreads(unsigned int start, unsigned int end, 
    unsigned int numThreads)
{
    std::vector<std::thread> threadVect;

    // Divide up the calculation so each thread operates on different primes
    unsigned int threadSpread = end / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    // Create prime list for each thread
    for (unsigned int x = 0; x < numThreads; x++)
    {
        threadVect.emplace_back(FindPrimes, start, newEnd);
        start += threadSpread;
        newEnd += threadSpread;
    }
    
    for (auto& t : threadVect) {
        t.join();
    }

}

int main() {

    // Get time before code starts executing
    int startTime = clock();

    FindPrimesWithThreads(1, 100000, 3);
    /*for (auto i : primeVect)
    std::cout << i << "\n";*/

    // Get time after execution
    int endTime = clock();

    // Print out the number of seconds by taking the difference and dividing by the 
    // clock ticks per second
    std::cout << "Execution Time : "
        << (endTime - startTime) / double(CLOCKS_PER_SEC) << std::endl;


    return 0;
}

// ----- END CALCULATE PRIMES WITH THREADS -----