// ----- TEMPLATE CLASSES TUTORIAL -----
// Template classes are classes that can work with different data types

// You can define that you may receive parameters with different types, but they don't have to be different
template<typename T, typename U>
class Person {
public:
    T height;
    U weight;
    static int numOfPeople;

    Person(T h, U w)
    {
        height = h, weight = w;
        numOfPeople++;
    }

    void GetData()
    {
        std::cout << "Height : " << height
            << " and Weight : " << weight << "\n";
    }
};

// You have to initialise static class members
template<typename T, typename U> int Person<T, U>::numOfPeople = 0;

#include <iostream>

int main() {
    Person<double, int> MikeTyson(5.83, 216);
    MikeTyson.GetData();

    // You access static values using the object and not the class
    std::cout << "Number of People : " << MikeTyson.numOfPeople << "\n";

    return 0;
}

// ----- END TEMPLATE CLASSES TUTORIAL -----