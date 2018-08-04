#include <iostream>
#include <vector>

// #----- FUNCTION PROTOTYPES -----#

std::vector<int> Range(int start, int max, int step);

// #----- FUNCTION PROTOTYPES ------#

int main() {
    // ----- PROBLEM DRAW A PINE TREE -----
    // For this problem I want you to draw a pine 
    // tree after asking the user for the number 
    // of rows. Here is the sample program

    /*
    How tall is the tree : 5
        #
       ###
      #####
     #######
    #########
        #
    */

    /*
    I know that this is the number of spaces
    and hashes for the tree
    4 - 1
    3 - 3
    2 - 5
    1 - 7
    0 - 9
    Spaces before stump = Spaces before top

    So I need to
    1. Decrement spaces by one each time through
    the loop
    2. Increment the hashes by 2 each time through
    the loop
    3. Save spaces to the stump by calculating
    tree treeHeight - 1
    4. Decrement from tree treeHeight until it equals 0
    5. Print spaces and then hashes for each row
    6. Print stump spaces and then 1 hash
    */

    int treeHeight = 0, hashes = 1, spaces = 0,
        stumpSpaces = 0;

    std::cout << "How tall is the tree : ";
    std::cin >> treeHeight;

    spaces = treeHeight - 1; // Starting spaces
    stumpSpaces = treeHeight - 1; // Spaces before stump

    while (treeHeight != 0)
    {
        // Print spaces before hashes
        for (auto x : Range(1, spaces, 1))
            std::cout << " ";

        // Print the hashes
        for (auto x : Range(1, hashes, 1))
            std::cout << "#";

        // Newline after each row
        std::cout << "\n";

        // Hashes incremented by 2 each time
        hashes += 2;

        // Spaces decremented by 1 each time
        spaces--;

        // Decrement treeHeight so loop ends
        treeHeight--;
    }

    // Print spaces before stump
    for (auto x : Range(1, stumpSpaces, 1))
        std::cout << " ";

    // Print stump
    std::cout << "#\n\n";

    // ----- END PROBLEM DRAW A PINE TREE -----
   
    
    return 0;
}

// #----- FUNCTION IMPLEMENTATIONS -----#

std::vector<int> Range(int start, int max, int step) {
    std::vector<int> range;
    for (int i = start; i <= max; i += step) {
        range.push_back(i);
    }

    return range;
}

// #----- FUNCTION IMPLEMENTATIONS ------#