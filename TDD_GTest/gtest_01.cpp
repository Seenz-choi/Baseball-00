#include "pch.h"
#include "../TDD/test_01.cpp"

class AccountFixture :  public testing::Test
{
public:
	Account account{ 10000 };
};

TEST_F(AccountFixture, CreateAccountInit10000) {
	EXPECT_EQ(10000, account.getBalance());
}

TEST_F(AccountFixture, Deposit) {
	account.depoist(500);
	EXPECT_EQ(10500, account.getBalance());
}

TEST_F(AccountFixture, Withdraw) {
	account.withdraw(600);
	EXPECT_EQ(9400, account.getBalance());
}

TEST_F(AccountFixture, setInterestCompound) {
	account.setInterestCompound();
	EXPECT_EQ(10500, account.getBalance());
}

TEST_F(AccountFixture, setInterest) {
	account.setInterest(3);
	account.setInterestCompound();
	EXPECT_EQ(10300, account.getBalance());
}

TEST_F(AccountFixture, checkNYearsAfter) {
	account.setInterest(10);
	account.checkNYearsAfter(3);
	account.setInterestCompound();
	EXPECT_EQ(13310, account.getBalance());
}