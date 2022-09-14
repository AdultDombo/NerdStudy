using System;

class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        int nLength = nums.Length;
         for (int i = 0; i < nLength; i++)
         {
            for (int j = i + 1; j < nLength; j++)
            {
                for (int k = j + 1; k < nLength; k++)
                {
                    if (checkNumber(nums[i] + nums[j] + nums[k]))
                        answer++;
                }
            }
         }
        
        return answer;
    }
    
    public bool checkNumber(int num)
    {
        for(int i=2; i< num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return num > 1;
    }
}
