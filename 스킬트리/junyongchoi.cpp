#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int nPriority = skill.length();
    for(string& sTrees : skill_trees){
        bool bDisalbe = false;
        int nPrevFind = sTrees.find(skill[0]); // 첫번째는 그냥 검색해줌 
        for(int idxPri = 1; idxPri < nPriority; idxPri++){
            int nCurrentFind = sTrees.find(skill[idxPri]);
            if(nCurrentFind != string::npos) { //찾았을때
                bDisalbe = nPrevFind == string::npos || nPrevFind > nCurrentFind;// 이전걸 못 찾거나 더 오래된거면 
                if(bDisalbe)
                    break; // 더는 볼 필요도 없음 Count 안해 
            }
            nPrevFind = nCurrentFind; // 끝가지 볼 필요가 있다
        }
        if(bDisalbe == false)
            answer++;
    }
    return answer;
}
