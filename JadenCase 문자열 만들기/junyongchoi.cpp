#include <string>
#include <cctype>
#include <boost/algorithm/string/join.hpp>
using namespace std;

string solution(string s) {
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    s[0] = toupper(s[0]);
    for(int i = 1; i < s.size(); i++){
        if(s[i-1] == ' ')
            s[i] = toupper(s[i]);
    }
    return s;
}
