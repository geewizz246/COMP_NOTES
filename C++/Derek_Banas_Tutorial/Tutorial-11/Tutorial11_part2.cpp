// ----- FRIEND CLASSES TUTORIAL -----

#include <iostream>
#include <string>

// Private members of a class are not accessable to outside 
// code unless a class is marked as a friend
class Customer {
private:
	friend class GetCustomerData;
	std::string name;

public:
	Customer(std::string name)
	{
		this->name = name;
	}
};

class GetCustomerData {
public:
	static std::string GetName(Customer& customer)
	{
		return customer.name;
	}
};

int main() {
	Customer Tom("Tom");
	GetCustomerData getName;
	std::cout << "Name : " << getName.GetName(Tom) << "\n";


	return 0;
}

// ----- END FRIEND CLASSES TUTORIAL -----