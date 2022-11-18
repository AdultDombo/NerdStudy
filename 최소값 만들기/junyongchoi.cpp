#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    for(int i; i < A.size(); i++) // A, B size가 같으므로
        answer += A[i] * B[i];
    //inner_product(A.begin(), A.end(), B.begin(), 0) -> 스칼라 곱을 사용해도 됨
    return answer;
}
