#include <string>
#include <stdexcept>

struct Result
{
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(std::string number)
		: answer_(number) {}

	bool isRightAnswer(const std::string& guessNumber)
	{
		return answer_ == guessNumber;
	}

	Result guess(const std::string& guessNumber)
	{
		assertIllegalNumber(guessNumber);
		if (isRightAnswer(guessNumber)) return Result{ true, 3, 0 };

		int scnt = getStrikeCount(guessNumber);
		int bcnt = getBallCount(guessNumber);
		return Result{ false, scnt, bcnt };
	}
private:
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isOnlyNumbers(std::string guessNumber)
	{
		for (char ch : guessNumber) {
			if (ch > '9' || ch < '0') return false;
		}
		return true;
	}

	void assertIllegalNumber(const std::string& guessNumber)
	{
		if (guessNumber == "") {
			throw std::invalid_argument("needs three numbers");
		}
		if (guessNumber.length() != 3) {
			throw std::invalid_argument("needs three numbers");
		}
		if (!isOnlyNumbers(guessNumber)) {
			throw std::invalid_argument("needs three numbers only");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("is duplicated number");
		}
	}

	int getStrikeCount(const std::string& guessNumber)
	{
		int scount = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = answer_.find(guessNumber[i]);
			if (index == -1) continue;
			if (index == i) scount++;
		}
		return scount;
	}
	int getBallCount(const std::string& guessNumber)
	{
		int bcount = 0;
		for (int i = 0; i < 3; i++)
		{
			int index = answer_.find(guessNumber[i]);
			if (index == -1) continue;
			if (index != i) bcount++;
		}
		return bcount;
	}
private:
	std::string answer_;
};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif