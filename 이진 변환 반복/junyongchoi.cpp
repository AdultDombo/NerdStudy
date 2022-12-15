#include <string>
#include <vector>
#include <bitset>
#include <sstream>
#include <iostream>
using namespace std;

// 속도는 잘 안나옴
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while(s != "1")
    {
        char c;
        stringstream ss(s);
        int nOneLength = 0;
        while(ss >> c)
        {
            if(c == '1')
                nOneLength++;
        }
        answer[0]++;
        answer[1] += s.length() - nOneLength;
        bitset<sizof(int)> bs(nOneLength);
        string sTemp = bs.to_string();
        cout << sTemp << endl;
        int nFind = sTemp.find('1');
        s = sTemp.substr(nFind);
    }
    
    return answer;
}
