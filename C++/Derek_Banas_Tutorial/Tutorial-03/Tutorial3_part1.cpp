// ************** TUTORIAL 3 **************
// https://www.youtube.com/watch?v=7pLldfZunJI
// In this tutorial we will be covering:
//  - additional vectors and loops
//  - pointers
//  - functions
//
// Additional Vectors and Loops

#include <iostream>
#include <vector> // std::begin, std::end
#include <numeric> // std::iota

int main() 
{
    std::vector<int> myVec(10); // create an empty int vector myVec with size 10

    // std::iota(ForwardIterator first, ForwardIterator last, T val) ===> assigns to every element in the range [first,last) 
    // successive values of val, as if incremented with ++val after each element is written 
    // std::begin ===> points at the first index in vector/sequence
    // std::end ===> points at the last index in vector/sequence
    std::iota(std::begin(myVec), std::end(myVec), 0); // populates myVec with incremental values starting at 0

    for (int i = 0; i < myVec.size(); ++i)
        std::cout << myVec[i] << "\n";

    // An abbreviated for loop is also available
    // auto determines the data type based on the value
    // y is assigned each value in the vector incrementing
    // the index by 1 each time through the loop
    for (auto y : myVec)
        std::cout << y << "\n";

    
    return 0;
}