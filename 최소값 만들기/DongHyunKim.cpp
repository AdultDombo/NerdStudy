#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    for (int nIdx = 0; nIdx < A.size(); nIdx++)
        answer += A[nIdx] * B[nIdx];
    return answer;
}
