#include "pch.h"
#include "../TDD/test_04.cpp"

TEST(BaseballGame, test00) {
	Baseball baseball("123");
	EXPECT_THROW(baseball.guess(""), std::invalid_argument);
	EXPECT_THROW(baseball.guess("12345"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("1v3"), std::invalid_argument);
	EXPECT_THROW(baseball.guess("133"), std::invalid_argument);
}

TEST(BaseballGame, test01) {
	Baseball baseball("123");
	Result result = baseball.guess("123");
	EXPECT_EQ(true, result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST(BaseballGame, test02) {
	Baseball baseball("123");
	Result result = baseball.guess("789");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(0, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST(BaseballGame, test03) {
	Baseball baseball("123");
	Result result = baseball.guess("132");
	EXPECT_EQ(false, result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}