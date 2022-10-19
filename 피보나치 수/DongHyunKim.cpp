#include <string>
#include <vector>
int solution(int n) {    
    int fibo_mem[n];
    fibo_mem[0] = 0;
    fibo_mem[1] = 1;
    // 수가 너무 커서 여기서 나머지 구하고 넣어준다.
    for (int nIdx = 2; nIdx <= n; nIdx++){
        fibo_mem[nIdx] = (fibo_mem[nIdx-1] + fibo_mem[nIdx-2]) % 1234567;
    }
    return fibo_mem[n];
}
