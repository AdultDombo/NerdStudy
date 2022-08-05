#include <string>
#include <vector>
#include <algorithm>
#define MIN(A,B) (A > B ? B : A)
using namespace std;
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);
    int nCertain = 0;
    int nUncertain = 0;
    for(int idx = 0; idx < lottos.size(); idx++)
    {
        if(lottos[idx] == 0)
            nUncertain++;
        else if(find(win_nums.begin(), win_nums.end(), lottos[idx]) != win_nums.end())
            nCertain++;
    }
    int nMinPlace = 7 - nCertain;
    int nMaxPlace = nMinPlace - nUncertain;
    answer[0] = MIN(nMaxPlace, 6);
    answer[1] = MIN(nMinPlace, 6);
    return answer;
}
