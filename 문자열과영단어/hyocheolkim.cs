public class Solution {
    string[] Pattern = new string[] { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        public int solution(string s)
        {
            for(int i = 0; i < 10; i++)
                s = s.Replace(Pattern[i], i.ToString());
            return int.Parse(s);
        }
}
