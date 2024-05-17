
#include <stdexcept>
#include <string>

#include "../packages/Microsoft.googletest.v140.windesktop.msvcstl.static.rt-dyn.1.8.1.7/build/native/include/gtest/internal/gtest-port.h"
using namespace std;


class GuessResult
{
public:
	bool solved;
	int strikes;
	int balls;
};

class Baseball
{
public:
	Baseball(string input) : answer(input) {};
	bool checkDuplicateNumber(const string& guessNumber)
	{
		return (guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[0] == guessNumber[2]);
	}

	void assertIllegalArgument(const string& guessNumber)
	{
		if (guessNumber.length() != 3)
		{
			throw length_error("Must be three letters!");
		}

		for (char ch : guessNumber)
		{
			if (ch < '0' || ch > '9')
			{
				throw invalid_argument("Must be three number!");
			}
		}

		if (checkDuplicateNumber(guessNumber))
		{
			throw invalid_argument("Must not have same number!");
		}
	}

	int checkStrikeCount(const string& guessNumber)
	{
		int count = 0;
		for(int i = 0; i < 3; i++)
		{
			if(guessNumber[i] == answer[i])
			{
				count++;
			}
		}
		return count;
	}

	int checkBallCount(const string& guessNumber)
	{
		int count = 0;
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				if (guessNumber[i] == answer[j])
					count++;
			}
		}
		return count;
	}

	GuessResult guess(const string& guessNumber)
	{
		assertIllegalArgument(guessNumber);
		GuessResult res;
		res.strikes = checkStrikeCount(guessNumber);
		if(res.strikes == 3)
		{
			res.balls = 0;
			res.solved = true;
			return res;
		}
		res.solved = false;
		res.balls = checkBallCount(guessNumber);
		return res;
	}

private :
	string answer;
};

