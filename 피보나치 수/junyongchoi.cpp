#include <string>
#include <vector>

#define SIZE 2
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1234567;

matrix operator * (const matrix &a, const matrix &b){
    matrix c(SIZE, vector<ll>(SIZE));
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            for(int z = 0; z < SIZE; z++){
                c[i][j] += a[i][z] * b[z][j] ;
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}
int solution(int n) {
    matrix zero = {{1, 0}, {0, 1}};
    matrix base = {{1, 1}, {1, 0}};
    
    while(n > 0){ // 거듭제곱을 이용한 recursive(재귀) 알고리즘 으로 n승 구하기
        if(n % 2)
            zero = zero * base;
        base = base * base;
        n /= 2;
    }
    int answer = zero[0][1];
    return answer;
}
