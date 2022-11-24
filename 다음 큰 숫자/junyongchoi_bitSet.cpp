#include <bitset>
using namespace std;
int solution(int n) {
    // 제일 효율 좋음 공유를 위해 작성 bitset<최대bit>
    int num = bitset<20>(n).count(); 
    while (bitset<20>(++n).count() != num);
    return n;
}
