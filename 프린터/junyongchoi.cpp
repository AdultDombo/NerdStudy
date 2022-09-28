#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> CycleQue; // Cycle Queue처럼 사용 할것임
    stack<int> prioStack; // 큰수를 우선으로 담는 Stack
    for(int& nData : priorities)
        CycleQue.push(nData);
    sort(priorities.begin(), priorities.end()); // 오름차순정렬
    for(int& nData : priorities)
        prioStack.push(nData);
    while(CycleQue.empty() == false){
        int nTopPriority = prioStack.top();
        int nData = CycleQue.front();
        CycleQue.pop();
        if(nTopPriority > nData)
            CycleQue.push(nData);
        else{
            prioStack.pop();
            answer++;
            if(location == 0)
                break;
        }
        if(--location < 0)
            location = CycleQue.size() - 1;
    }
    return answer;
}
