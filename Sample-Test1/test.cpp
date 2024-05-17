#include "pch.h"
#include "../baseball/Baseball.cpp"
#include <string>

using namespace std;

TEST(Baseball, ThrowExceptionLengthError) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(Baseball, ThrowExceptionInputChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}