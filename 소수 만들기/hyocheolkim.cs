using System;

class Solution
{
    public int solution(int[] nums)
    {
        int answer = 0;
        for (int one = 0; one< nums.Length; one++)
        {
            for (int two = one + 1; two< nums.Length; two++)
            {
                for (int three = two + 1; three < nums.Length; three++)
                {
                    int sum = nums[one] + nums[two] + nums[three];
                        if (PrimeNumberCheck(sum))
                            answer++;
                }
            }
        }
        return answer;
    }
    private bool PrimeNumberCheck(int num)
    {
        for (int i = 2; i * i <= num; i++)//루트 대신 제곱
            if (num % i == 0)
                return false;
        return true;
    }
}
