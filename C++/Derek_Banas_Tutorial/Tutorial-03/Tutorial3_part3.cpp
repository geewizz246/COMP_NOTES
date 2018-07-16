// Functions continued
//
// Program changes age of person

#include <iostream>

// FUNCTION PROTOTYPES

// Assign age but do not return
void AssignAge(int);

// Assign age and return
int AssignAge2(int);

// END FUNCTION PROTOTYPES

int main() {
    int age = 43;
    AssignAge(age);
    std::cout << "New Age = " << age << "\n";

    age = AssignAge2(age);
    std::cout << "Returned Age = " << age << "\n";

    
    return 0;
}

// FUNCTION IMPLEMENTATIONS

void AssignAge(int age) {
    age = 24;
}

int AssignAge2(int age) {
    age = 24;
    return age;
}

// END FUNCTION IMPLEMENTATIONS