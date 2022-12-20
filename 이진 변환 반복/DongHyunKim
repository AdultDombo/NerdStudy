#include <string>
#include <vector>
using namespace std;
vector<int> solution(string s) {
    vector<int> answer(2,0);
    //  nConvertCnt = 이진변환 횟수, nZeroCnt: 제거된 모든 0의 개수
    int nConvertCnt = 0, nZeroCnt = 0;
    // 1의 개수
    int nOneCnt;
    while (s != "1"){
        nConvertCnt++;
        nOneCnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '0')
                nZeroCnt++;
            else
                nOneCnt++;
        }
        s = "";
        // 1의 개수를 이진수로 변환
        while(nOneCnt > 0)
        {
            s += to_string(nOneCnt%2);
            nOneCnt /= 2;
        }
    }
    answer[0] = nConvertCnt;
    answer[1] = nZeroCnt;
    return answer;
}
