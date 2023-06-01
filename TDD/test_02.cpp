#include <vector>
class PrimeFactor
{
public:
	std::vector<int> of(int number)
	{
		std::vector<int> result = {};
		for (int divisor = 2; number > 1; divisor++) {
			while (number % divisor == 0) {
				result.push_back(divisor);
				number /= divisor;
			}
		}
		return result;
	}
};


#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif