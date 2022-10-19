#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    istringstream ssSet(s);
    vector<int> vs;
    string sTemp;
    while(getline(ssSet, sTemp, ' '))   // 공백으로 나누는 법 참고 - https://chbuljumeok1997.tistory.com/42
        vs.push_back(std::stoi(sTemp)); // stoi -> stringToInt C++11 부터 지원 
    sort(vs.begin(), vs.end());
    ostringstream ssGet;
    ssGet << vs.front() << " " << vs.back();  // 문자열 연결 참고 - https://www.techiedelight.com/ko/concatenate-multiple-strings-in-cpp/
    return ssGet.str();
}
