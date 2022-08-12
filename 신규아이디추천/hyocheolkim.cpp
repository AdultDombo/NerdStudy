#include <string>
#include <vector>
#include <regex>

using namespace std;

string solution(string new_id) {
    //문자
    new_id = regex_replace(new_id, regex("[^0-9a-zA-Z-_.]+"), "");
    new_id = regex_replace(new_id, regex("[..]+"), ".");
    //앞에.지우기
    if (new_id.find(".") == 0)
        new_id.erase(0, 1);
    //소문자로 변환
    for (int i = 0; i < new_id.size(); i++)
        new_id[i] = tolower(new_id[i]);
    //길이 15보다 크면 짜르기
    if (15 < new_id.size())
        new_id = new_id.substr(0, 15);
    //뒤에.지우기
    if (new_id.size() > 0 && new_id.rfind(".") == new_id.size() - 1)
        new_id.resize(new_id.rfind(".")); 
    //길이 3보다 작으면 문자열추가
    int nIDsize = new_id.size();
    if (nIDsize < 3) {
        for (int i = 0; i < 3 - nIDsize; i++) {
            if (nIDsize == 0)
                new_id += "a";
            else
                new_id += new_id.substr(nIDsize -1, 1);
        }
    }
    return new_id;
}
