#include "pch.h"
#include "../baseball/Baseball.cpp"
#include <string>

using namespace std;

TEST(Baseball, ThrowExceptionLengthError) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}