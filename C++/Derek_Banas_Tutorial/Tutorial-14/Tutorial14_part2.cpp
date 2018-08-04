// ----- TEMPLATE FUNCTIONS TUTORIAL -----

#include <iostream>
#include <string>

// We use templates to create functions or classes that can work with many types.
// Templates differ from function overloading in that instead of having a function that does similar
// things with different objects, a template does the same thing with different objects

// This says this is a function template that generates functions that accept 1 parameter
// T represents an unknown type
template<typename T> 
void Times2(T value) {
    std::cout << value << " * 2 = " << value * 2 << "\n";
}

// Receive multiple parameters and return a value
// Both variables passed in must be the same type (type T)
template<typename T>
T Add(T val, T val2) {
    return val + val2;
}

// Work with chars and strings
template <typename T>
T Max(T val, T val2) {
    return (val < val2) ? val2 : val;
}

int main() {
    Times2(5);
    Times2(25.3);

    std::cout << "12 + 7 = " 
        << Add(12, 7) << "\n";
    std::string a = "face", b = "palm";
    std::cout << "\"face\" + \"palm\"  = \""
        << Add(a, b) << "\"\n";

    std::cout << "Max 3 or 9 : "
        << Max(3, 9) << "\n";
    std::cout << "Max \'a\' or \'g\' : \'"
        << Max('a', 'g') << "\'\n";
    std::cout << "Max \"Dog\" or \"Cat\" : \""
        << Max("Dog", "Cat") << "\"\n";

    return 0;
}

// ----- END TEMPLATE FUNCTIONS TUTORIAL -----