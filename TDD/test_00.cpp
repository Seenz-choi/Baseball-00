
class Fibo
{
public:
	int fibo(int n)
	{
		if (n == 0) return 0;
		if (n < 3) return 1;
		return fibo(n - 2) + fibo(n - 1);
	}
};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif