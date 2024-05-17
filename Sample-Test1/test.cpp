#include "pch.h"
#include "../baseball/Baseball.cpp"
#include <string>

using namespace std;

class BaseballTexture : public testing::Test
{
public :
	Baseball game{"123"};
	void assertIllegalArgument(string guessNumber)
	{
		try
		{
			game.guess(guessNumber);
			FAIL();
		}
		catch(exception e)
		{
			//PASS;
		}
	}
};


TEST_F(BaseballTexture, ThrowExceptionInvalidInput) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballTexture, ReturnSolvedResultSuccess) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE( result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballTexture, ReturnSolvedResult2S0B) {
	GuessResult result = game.guess("124");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballTexture, ReturnSolvedResult1S2B) {
	GuessResult result = game.guess("321");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}

