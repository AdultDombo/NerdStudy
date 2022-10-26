#include<string>
#include <iostream>
using namespace std;
bool solution(string s)
{
    // 괄호 갯수 (처음에 열고 시작하니 1부터 시작)
    int nCnt = 1;
    // 처음엔 무조건 괄호 열어줘야함.
    if (s[0] != '(')
        return false;
    for (int nIdx = 1; nIdx < s.size(); nIdx++){
        if (s[nIdx] == '(')
            nCnt++;
        else if (s[nIdx] == ')'){
            nCnt--;
            // 효율성 예외처리. 중간부터 틀린건 바로 false 처리.
            if (nCnt < 0)
                return false;
        }
    }
    return nCnt == 0;
}
