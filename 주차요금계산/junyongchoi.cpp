#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
#include <cmath>
using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
    vector<string> result;
    while (getline(iss, buffer, Delimiter)) // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    return result;
}
int TimeToInt(string sH, string sM){
    int nH = stoi(sH);
    int nM = stoi(sM);
    return nH * 60 + nM;
}
vector<int> solution(vector<int> fees, vector<string> records) {
    
    vector<int> answer;
    unordered_map<string, int> MapParkData;
    map<string, int> MapTotalTime;
    for(string record : records)
    {
        // 데이터 나누기
        vector<string> data = split(record, ' ');
        string sTime = data[0];
        string sNumber = data[1];
        string sState = data[2];
        // 시간을 int 값으로 변환
        vector<string> vTimes = split(sTime, ':');
        int nTime = TimeToInt(vTimes[0], vTimes[1]);
        if(sState == "IN")
            MapParkData.insert(make_pair(sNumber, nTime));
        else
        {
            int nSubTime = nTime - MapParkData[sNumber];
            MapParkData.erase(sNumber);
            if(MapTotalTime.find(sNumber) != MapTotalTime.end())
                MapTotalTime[sNumber] += nSubTime;
            else
                MapTotalTime.insert(make_pair(sNumber, nSubTime));
        }
    }
    const int nLastTime = 23 * 60 + 59;
    // 출차안한 애들 
    for(pair<string, int> vPair : MapParkData){
        int nSubTime = nLastTime - vPair.second;
        if(MapTotalTime.find(vPair.first) != MapTotalTime.end())
            MapTotalTime[vPair.first] += nSubTime;
        else
            MapTotalTime.insert(make_pair(vPair.first, nSubTime));
    }
    
    for(pair<string, int> vPair : MapTotalTime){ // map이니 자동으로 오츰차순 정렬 됨
        string sNum = vPair.first;
        int nTime = vPair.second;
        // 기본요금 
        int nTotal = fees[1];
        if(nTime > fees[0])
            nTotal += ceil((double)(nTime - fees[0]) / fees[2]) * fees[3];
        answer.push_back(nTotal);
    }
    return answer;
}
