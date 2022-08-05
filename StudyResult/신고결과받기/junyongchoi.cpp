#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int nIDSize = id_list.size();
    vector<int> answer(nIDSize);
    map<string, int> mapIDIndx;
    map<string, set<string>> mapReportSet;
    for(int i =0; i < nIDSize; i++){
        mapIDIndx[id_list[i]] = i;
    }
    
    for (auto& value : report) {
        stringstream s2(value);
        string sUser, sTarget;
        s2 >> sUser >> sTarget;
        mapReportSet[sTarget].insert(sUser);
    }
    for (auto& [key, value] : mapReportSet){
        if(value.size() >= k){
            for(auto& sUser : value){
                answer[mapIDIndx[sUser]]++;
            }
        }
    }
    return answer;
}
