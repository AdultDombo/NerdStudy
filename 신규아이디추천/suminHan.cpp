#include <string>
#include <vector>

using namespace std;

string solution(string str) {
    
	for (int idx = 0; idx < str.size();)
	{
		char cID = str[idx];

    //6단계 16자리 이상
		if (idx >= 15)
		{
			str.erase(str.begin() + idx);
		}
		else if (cID >= 'A' && cID <= 'Z') // 1단계 대문자 이면 소문자로
		{
			str[idx] = tolower(cID);
			idx++;
		}
		else if(cID == '.') //3단계, 4단계 
		{
			if (idx==0)
			{
				str.erase(str.begin() + idx);
			}
			else if ( str[idx-1] == '.')
			{
				str.erase(str.begin() + idx);
			}
			else if (idx == str.back())
			{
				str.erase(str.begin() + idx);
			}
			else
			{
				idx++;
			}
		}
    //2단계 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.) <== 마침표는 위에서 검사
		else if((cID >= 'a' && cID <= 'z') || (cID >= '0' && cID <= '9') ||
                 cID == '-' || cID == '_')
		{
			idx++;
		}
		else
		{
			str.erase(str.begin() + idx);
		}
	}

  //5단계
	if (str.size() == 0)
	{
		str = "a";
	}

  //4단계 끝자리 .이면 제거
	if (str.back() == '.')
	{
		str.erase(str.end() -1);
	}

  //7단계 new_id의 길이가 2자 이하라면
	if (str.size() <= 2)
	{
		while (str.length() != 3)
        {
			str += str.back();
		}
	}
    
    return str;
}
