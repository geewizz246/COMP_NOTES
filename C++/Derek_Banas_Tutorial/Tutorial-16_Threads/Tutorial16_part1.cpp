// ************** TUTORIAL 16 **************
// https://youtu.be/IdwJdJw65tU
// In this tutorial we will be covering:
//  - Threads
//  - Time
//  - Protecting Shared Resources
//  - Calculating Primes with and without Threads
//
// ----- SIMPLE THREAD TUTORIAL ----- 
// DEFINITION 1:
// A thread is a set of instructions for a processor core to work on within a process. 
// When a process has more then one thread, it means that it has more then one set of instructions
// to be worked on in parallel.
//
// DEFINITION 2:
// A thread of execution is a sequence of instructions that can be executed concurrently with other 
// such sequences in multithreading environments, while sharing a same address space.

#include <iostream>
#include <ctime> // srand, rand(), std::ctime, std::time_t (var type)
#include <chrono> // std::chrono
#include <thread> // Needed for thread functions

// Random number generator
int GetRandom(int max) 
{
    srand(time(NULL));
    return rand() % max;
}

// Simple thread example.
// Displays the sleep time and awake time of the thread.
void ExecuteThread(int id) 
{
    // Get current time
    auto nowTime = std::chrono::system_clock::now();

    // Convert to a time we can output
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);
   
    // Convert to current time zone
    tm myLocalTime = *localtime(&sleepTime);

    // Print full time information
    std::cout << "Thread " << id
        << " Sleep Time : " << std::ctime(&sleepTime) << "\n";

    // Get separate pieces
    std::cout << "Month : " << myLocalTime.tm_mon + 1 << "\n" // tm_mon ====> months since January - [0, 11]
        << "Day : " << myLocalTime.tm_mday << "\n" // tm_mday ====> day of the month - [1, 31]
        << "Year : " << myLocalTime.tm_year + 1900 << "\n" // tm_year ====> years since 1900
        << "Hours : " << myLocalTime.tm_hour << "\n" // tm_hour ====> hours since midnight - [0, 23]
        << "Minutes : " << myLocalTime.tm_min << "\n" // tm_min ====> minutes after the hour - [0, 59]
        << "Seconds : " << myLocalTime.tm_sec << "\n\n"; // tm_sec ====> seconds after the minute - [0, 60] including leap second (dunno what that is)

    // Put the thread to sleep for up to 3 seconds
    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));
    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread " << id
        << " Awake Time : " << std::ctime(&sleepTime) << "\n";
}

// main() is an example of a thread
int main() {
    // Create a thread that calls function ExecuteThread and pass a parameter to the function
    std::thread th1(ExecuteThread, 1);

    // Join the thread to the main thread meaning main waits for this thread to
    // stop executing before continuing execution of code in main
    th1.join();

    std::thread th2(ExecuteThread, 2);
    th2.join(); // pause main thread until th2 finishes

    return 0;
}

// ----- END SIMPLE THREAD TUTORIAL -----