#include <vector>
#include <map>
#include <numeric>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    map<int, bool> mapSum;
    int nSize = nums.size();
    for(int x = 0; x < nSize - 2; x++){
        for(int y = x + 1; y < nSize - 1; y++){
            for(int z = y + 1; z < nSize; z++){
                int nSum = nums[x] + nums[y]  + nums[z];
                if(mapSum.insert({nSum, true}).second) // 중복된 합 계산 안함
                { 
                    int nSqrt = sqrt(nSum); // 루트를 씌워서 계산해야할 숫자를 줄여줌
                    // 에라토스테네스의 체를 구현하기위한 array - 해당문제에서는 체 사용이 비효율적인것 같으나 체 알고리즘을 써보기위해 넣음
                    int arr[nSqrt];
                    std::iota(arr, arr + nSqrt, 1); 
                    for(int i = 2; i <= nSqrt; i++){
                        if(arr[i-1] == 0) // 먼저 계산된 숫자의 배수는 계산되지 않도록 Continue 
                            continue;
                        for (int j = 2 * i; j <= nSqrt; j += i) // 먼저 계산된 숫자의 배수를 찾아 0으로 바꿔주는 부분
                            arr[j-1] = 0; 
                        if(nSum % i == 0){
                            mapSum[nSum] = false;
                            break;
                        }
                    }
                }
                if(mapSum[nSum])
                    answer++;
            }
        }
    }

    return answer;
}
