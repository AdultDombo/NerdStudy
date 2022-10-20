using System.Linq;
using System;
using System.Collections.Generic;
public class Solution {
    public string solution(string s) {
        string[] arrS = s.Split(" ");
        int[] nArr = Array.ConvertAll(arrS, ( e ) => int.Parse(e));
        
        return string.Format("{0} {1}",nArr.Min(),nArr.Max());
    }
}
