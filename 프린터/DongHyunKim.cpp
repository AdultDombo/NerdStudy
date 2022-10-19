#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int nKey = 0;   // 첫번째 큐의 Key
    int nValue = 0; // 첫번째 큐의 Value
    queue<pair<int, int>> que;
    priority_queue <int> ptyque;
    for (int nSeq = 0; nSeq < priorities.size(); nSeq++){
        // 큐에 배열의 순서대로 중요도를 넣어준다.
        que.push(make_pair(nSeq, priorities[nSeq]));
        ptyque.push(priorities[nSeq]);
    }
    while (que.empty() == false && ptyque.empty() == false){
        nKey = que.front().first;
        nValue = que.front().second;
        que.pop();                                          // 일단 빼고
        if (ptyque.top() > nValue)                          // 우선순위가 가장 높지 않으면
            que.push({nKey, nValue});                       // 맨뒤에 다시 넣어줌.
        else{                                               // 우선순위가 같거나 크면
            answer++;                                       // 인쇄 순위 조절
            if (nKey == location)
                return answer;
            if (ptyque.top() == nValue)                     // 가장 높은값이면 우선순위 큐에서 뺀다.
                ptyque.pop();
        }
    }
    return answer;
}
