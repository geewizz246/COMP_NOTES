// ----- CALCULATE PRIMES WITHOUT THREADS -----

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <mutex>

std::vector<unsigned int> primeVect;

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
                primeVect.push_back(x);
        }
    }
}

int main() {

    // Get time before code starts executing
    int startTime = clock();

    FindPrimes(1, 100000);
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

// ----- END CALCULATE PRIMES WITHOUT THREADS -----