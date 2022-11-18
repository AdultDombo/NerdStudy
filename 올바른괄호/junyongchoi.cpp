#include<string>
#include<iostream>
#include<stack>
using namespace std;

bool solution(string s)
{
    stack<char> stCheck;
    for(char& c : s){
        if(c == '(')
            stCheck.push(c);
        else
        {
            if(stCheck.empty())
                return false;
            stCheck.pop();
        }
    }
    return stCheck.empty();
}
