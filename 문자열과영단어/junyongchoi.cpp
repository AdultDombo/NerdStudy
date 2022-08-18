#include <string>
#include <vector>
#include <map>
#include <regex>
#include <boost/lexical_cast.hpp>
using namespace std;
int solution(string s) {
    map<string, string> mapConpare = 
    {
        {"zero", "0"},
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };
    for(const auto& [key, value] : mapConpare)
        s = regex_replace(s, regex(key), value);
    return boost::lexical_cast<int>(s);
}
