using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long sum = 0;
        for(int i = 1; i <= count; i++){
            sum += price * i;
        }
        long ReturnMoney = sum - money;
        if(ReturnMoney <= 0)
            ReturnMoney = 0;
        return ReturnMoney;
    }
}
