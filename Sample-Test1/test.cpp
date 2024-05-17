#include "pch.h"
#include "../baseball/Baseball.cpp"
#include <string>

using namespace std;

class BaseballTexture : public testing::Test
{
public :
	Baseball game;
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
}
