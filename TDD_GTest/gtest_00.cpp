#include "pch.h"
#include "../TDD/test_00.cpp"


TEST(FiboTC, fibo_00) {
	std::vector<std::vector<int>> cases = {
		{0, 0}, {1, 1}, {2, 1}, {3, 2}
	};
	for (auto v : cases) {
		EXPECT_EQ(v[1], Fibo().fibo(v[0]));
	}
}
