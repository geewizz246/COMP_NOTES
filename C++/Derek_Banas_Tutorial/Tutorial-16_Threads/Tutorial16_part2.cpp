// ----- THREAD TUTORIAL CONTINUED ----- 

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <mutex> // std::mutex

// Get the current time
std::string GetTime() 
{
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);

    return std::ctime(&sleepTime);
}

double acctBalance = 100;

// Protects shared data from being accessed simultaneously by multiple threads.
// Note: mutex is short for "mutual exclusion"
std::mutex acctLock;

// Access account and withdraw money
void GetMoney(int id, double withdrawal)
{
    // There are two different ways to lock your code
    
    // METHOD 1 (exception safe)
    // The exception safe way to protect access to code within its scope. The lock 
    // is released after execution leaves this scope.
    // Basically, it restricts access to the entire scope of this function once 
    // another thread enters and tries to execute this code.
    std::lock_guard<std::mutex> lock(acctLock);

    // METHOD 2 (not exception safe)
    // Blocks access between lock and unlock until execution completes.
    // However, this isn't good to use if an error occurs between lock and unlock.
    // acctLock.lock();
   
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout << id << " tries to withdraw $"
        << withdrawal << " on " << GetTime();

    if ((acctBalance - withdrawal) >= 0)  {
        acctBalance -= withdrawal;
        std::cout << "New Account Balance is $"
            << acctBalance << "\n\n";

    }
    else {
        std::cout << "Not enough money in account\n"
            << "Current balance is $" << acctBalance << "\n\n";
    }

    // acctLock.unlock();
}

int main() {
    // We will create a pool of threads that will access a bank account in no particular order
    std::thread threads[10];

    for (int i = 0; i < 10; ++i)
        threads[i] = std::thread(GetMoney, i, 15);

    for (int i = 0; i < 10; ++i)
        threads[i].join();

    return 0;
}

// ----- END THREAD TUTORIAL ----- 