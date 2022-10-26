#include <string>
#include <vector>
using namespace std;
string solution(string s) {
    string answer = "";
    // 대문자로 시작
    answer += toupper(s[0]);
    // 공백 다음은 대문자 나머지는 소문자
    for (int nIdx = 1; nIdx < s.size();nIdx++)
        s[nIdx-1] == ' ' ? answer += toupper(s[nIdx]) : answer += tolower(s[nIdx]);
    return answer;
}
