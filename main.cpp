#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to Physicist's Toolbox.\n" << "Enter the field of Physics you need help with: ";
	std::string inputField{};
	std::getline(std::cin, inputField);

	return 0;
}