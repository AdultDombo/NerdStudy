#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

	int left = 10;	//*
	int right = 12;	//#

	for (int idx=0; idx<numbers.size(); idx++)
	{
		int number = numbers[idx];

		if (number ==1 || number == 4 || number == 7)
		{
			answer += "L";
			left = number;
		}
		else if (number == 3 || number == 6 || number == 9)
		{
			answer += "R";
			right = number;
		}
		else
		{
			if (number == 0)
			{
				number = 11;
			}

			int nLDiff = abs(left - number);
			int nRDiff = abs(right - number);

			int nLDis = (nLDiff / 3) + (nLDiff % 3);
			int nRDis = (nRDiff / 3) + (nRDiff % 3);

			if (nLDis == nRDis)
			{
				if (hand == "left")
				{
					answer += "L";
					left = number;
				}
				else
				{
					answer += "R";
					right = number;
				}
			}
			else if (nLDis < nRDis)
			{
				answer += "L";
				left = number;
			}
			else
			{
				answer += "R";
				right = number;
			}
		}
	}
	
	return answer;
}
