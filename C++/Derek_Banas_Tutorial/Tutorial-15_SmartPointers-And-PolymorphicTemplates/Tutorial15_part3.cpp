// ----- POLYMORPHIC TEMPLATES TUTORIAL -----

#include <iostream>
#include <string>
#include <vector>

// Base class all pizzas inherit along with MakePizza which will be overridden
class Pizza {
public:
    virtual void MakePizza() = 0;
};


// ++++ LAST templates to be called ++++

class NYStyleCrust {
public:
    std::string AddIngredient()
    {
        return "Crust so thin you can see through it\n\n";
    }
};

class DeepDishCrust {
public:
    std::string AddIngredient()
    {
        return "Super awesome Chicago Deep Dish\n\n";
    }
};

// ++++ End of LAST templates to be called ++++


// ++++ MIDDLE templates to be called ++++

template<typename T>
class LotsOfMeat : public T {
public:
    std::string AddIngredient()
    {
        return "Lots of Random Meat, " + T::AddIngredient();
    }
};

template <typename T>
class Vegan : public T {
public:
    std::string AddIngredient()
    {
        return "VeganCheese, Veggies, " + T::AddIngredient();
    }
};

// ++++ End of MIDDLE templates to be called ++++


// ++++ FIRST templates to be called ++++

// We inherit from Pizza as well as the initial next template
template <typename T>
class MeatNYStyle : public T, public Pizza {
public:
    void MakePizza()
    {
        std::cout << "Meat NY Style Pizza : "
            << T::AddIngredient();
    }
};

template <typename T>
class VeganDeepDish : public T, public Pizza {
public:
    void MakePizza() 
    {
        std::cout << "Vegan Deep Dish : "
            << T::AddIngredient();
    }
};

// ++++ End of FIRST templates to be called ++++

int main() {
    std::vector<std::unique_ptr<Pizza>> pizzaOrders;

    // Generate Pizza types and place them at the end of the vector
    pizzaOrders.emplace_back(new MeatNYStyle<LotsOfMeat<NYStyleCrust>>());
    pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

    // Call the pizzas and execute the directions for making them
    for (auto &pizza : pizzaOrders)
        pizza->MakePizza();

    return 0;
}

// ----- END POLYMORPHIC TEMPLATES TUTORIAL -----