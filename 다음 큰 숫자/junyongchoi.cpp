#include <string>
#include <vector>
#define INTBITSIZE sizeof(int) * 8
using namespace std;

int GetBinaryCount(int n)
{
    int nResult = 0;
    ///////////////////////////////////// 첫번째 한거
    // for(int i = 0; i < INTBITSIZE; i++)
    // {
    //     if(n & 1 << i)
    //         nResult++;
    // }
    /////////////////////////////////////
    ///////////////////////////////////// 두번째 한거 좀더 효율이 좋음 (비트 카운트 세는데 반복을 적게 )
    while(n)
    {
        n &= (n-1);
        nResult++;
    }
    /////////////////////////////////////
    return nResult;
}
int solution(int n) {
    int nBaseBinaryCount = GetBinaryCount(n);
    while(nBaseBinaryCount != GetBinaryCount(++n)){}
    return n;
}
