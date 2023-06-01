#include <iostream>
#include <exception>

int go(int a, int b)
{
	if (a < 0 || b < 0)
		throw std::invalid_argument("Is not available.");
	if (a > 10 || b > 10)
		throw std::out_of_range("Is not available.");

	return a + b;
}


int main(int argc, char* argv[])
{
	try
	{
		go(10, 20);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << "invalid: " << e.what() << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cout << "out of range: " << e.what() << std::endl;
	}
	return 0;
}
