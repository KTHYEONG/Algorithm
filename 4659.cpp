#include <iostream>
#include <vector>

using namespace std;

// Pronounce Password
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string input;
	while (cin >> input)
	{
		if (input == "end")
		{
			break;
		}

		bool checkVowel = false, checkDup = false;
		int cntVowels = 0, cntCons = 0;
		char beforeChar;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o'
				|| input[i] == 'u')
			{
				checkVowel = true;
				cntVowels++;
				cntCons = 0;
			}
			else
			{
				cntCons++;
				cntVowels = 0;
			}

			if (cntVowels >= 3 || cntCons >= 3)
			{
				break;
			}

			if (i > 0)
			{
				if (beforeChar == input[i] && input[i] != 'e' && input[i] != 'o')
				{
					checkDup = true;
					break;
				}
			}
			beforeChar = input[i];
		}

		if (!checkVowel || checkDup || cntVowels >= 3 || cntCons >= 3)
		{
			cout << '<' << input << "> is not acceptable." << '\n';
		}
		else
		{
			cout << '<' << input << "> is acceptable." << '\n';
		}
	}

	return 0;
}