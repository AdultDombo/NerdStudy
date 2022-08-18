#include <string>
#include <vector>

using namespace std;

void erase(string *str, int idx, int count);
int solution(string str) {
   for (int idx = 0; idx < str.size();)
	{
		char cID = str[idx];

        // 숫자면 넘어감
		if ((cID >= '0' && cID <= '9'))
		{
			idx++;
		}
        //숫자가 아니면 앞자리 구분하여 첫글자는 숫자로 바꾸고 나머지 글자는 지운다
		else
		{
			if (cID == 'z')
			{
				str[idx] = '0';
				erase(&str, idx, 3);
			}
			else if (cID == 'o')
			{
				str[idx] = '1';
				erase(&str, idx, 2);
			}
			else if (cID == 't')
			{
				if (str[idx + 1] == 'w')
				{
					str[idx] = '2';
					erase(&str, idx, 2);

				}
				else
				{
					str[idx] = '3';
					erase(&str, idx, 4);
				}
			}
			else if (cID == 'f')
			{
				if (str[idx + 1] == 'o')
				{
					str[idx] = '4';
					erase(&str, idx, 3);

				}
				else
				{
					str[idx] = '5';
					erase(&str, idx, 3);
				}
			}
			else if (cID == 's')
			{
				if (str[idx + 1] == 'i')
				{
					str[idx] = '6';
					erase(&str, idx, 2);

				}
				else
				{
					str[idx] = '7';
					erase(&str, idx, 4);
				}
			}
			else if (cID == 'e')
			{
				str[idx] = '8';
				erase(&str, idx, 4);
			}
			else if (cID == 'n')
			{
				str[idx] = '9';
				erase(&str, idx, 3);
			}
		}
	}

	return stoi(str);
}
//글자의 뒷자리부터 지움
//ex) six이면 6ix로 바꾸고 뒤에서 부터 x지우고 i지움
//s.erase(s.begin() + index + 2);
//s.erase(s.begin() + index + 1);
void erase(std::string *str, int index, int count)
{
	std::string s = *str;
	for (int idx= count; idx>0; idx--)
	{
		s.erase(s.begin() + index + idx);
	}
	*str = s;
}
