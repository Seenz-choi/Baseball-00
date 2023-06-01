
class Account
{
public:
	Account(int balance)
		: balance_(balance)
	{
	}
	int getBalance()
	{
		return balance_;
	}

	void depoist(int money)
	{
		balance_ += money;
	}

	void withdraw(int money)
	{
		balance_ -= money;
	}

	void setInterestCompound()
	{
		balance_ += balance_ * interest_ / 100;
	}

	void setInterest(int interest)
	{
		interest_ = interest;
	}

	void checkNYearsAfter(int year)
	{
		for (int i = 0; i < year; i++)
		{
			setInterestCompound();
		}
	}
private:
	int balance_ = 10000;
	int interest_ = 5;
};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif