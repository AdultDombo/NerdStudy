using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long sum = 0;
        
        for(int idx=1; idx<=count; idx++)
        {
            sum += (idx * price);
        }    
        
        return (money > sum) ? 0 : Math.Abs(sum - money);
    }
}
