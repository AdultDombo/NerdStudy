#include <iostream>
using namespace std;

int solution(int n)
{
    // 이진수로 변환 후 1의 개수를 구한다.
    int ans = 0;
    while (n){
        ans += n%2;
        n /= 2;
    }
    return ans;
}
