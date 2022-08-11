#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <regex>
#include <iostream>
using namespace std;
string solution(string new_id) {
    boost::to_lower(new_id); // 1단계 소문자로
    new_id = regex_replace(new_id, regex("[^a-z0-9-._]"), ""); // 2단계 알파뱃 소문자, 숫자 빼기 밑줄 마침표 빼고 제거
    new_id = regex_replace(new_id, regex("\\.+"), "."); // 3단계 마침표 중복된거 1개로 바꾸기
    new_id = regex_replace(new_id, regex("^\\.|\\.$"), ""); // 4단계 양끝 . 제거
    if(new_id.empty()) new_id = "aaa"; // 5단계 비어있을 경우 a대입 (어짜피 비어있을경우는 aaa들어가는게 추호 7단계 조건이므로 aaa넣어준다)
    else if(new_id.size() > 15) new_id = regex_replace(new_id.substr(0, 15), regex("\\.$"), ""); // 6단계
    while(new_id.size() < 3) new_id += new_id.back();
    return new_id;
}
