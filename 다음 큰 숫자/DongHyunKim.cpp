// 1의 개수 찾기
int nNumCount(int n){
    int nRet = 0;
    while(n > 2){
        if (n % 2)
            nRet++;
        n /= 2;
    }
    return nRet++;
}
// 다음 큰 수 찾기
int solution(int n) {
    int answer = n + 1;
    int nCondition = nNumCount(n);  // n의 1 개수
    // n보다 큰 값중에 n과 1개수가 같은걸 찾는다.
    while (nCondition != nNumCount(answer))
        answer++;
    return answer;
}
