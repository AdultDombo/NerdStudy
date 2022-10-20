using System;
using System.Text.RegularExpressions;

class Solution
{
    public int solution(int n)
    {
        return Regex.Matches(Convert.ToString(n, 2),"1").Count;
    }
}
