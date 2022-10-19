using System;
using System.Linq;
public class Solution {
    public string solution(string s) {
        string[] sArrNum = s.Split(" ");
        int[] nArrNum = Array.ConvertAll(sArrNum, sNum => Convert.ToInt32(sNum));
        return string.Format("{0} {1}", nArrNum.Min().ToString(), nArrNum.Max().ToString());
    }
}
