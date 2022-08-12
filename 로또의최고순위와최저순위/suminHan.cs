using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        //로또 번호에서 0제거
        lottos = lottos.Where(val => val != 0).ToArray();
        
        int matchCnt = 0;
        int zeroCnt = 6-lottos.Length;
        
        foreach(int num in lottos)
        {
            foreach(int wNum in win_nums)
            {
                if(num == wNum)
                {
                    matchCnt++;
                    break;
                }
            }
        }
        
        answer[0] = checkNum(matchCnt + zeroCnt);
        answer[1] = checkNum(matchCnt);
        
        return answer;
    }
    
    //등수 체크
    int checkNum(int num)
    {
        int rank = 6;
        switch(num)
        {
            case 6: 
                rank = 1;
                break;
            case 5:
                rank = 2;
                break;
            case 4:
                rank = 3;
                break;
            case 3:
                rank = 4;
                break;
            case 2:
                rank = 5;
                break;
            default:
                rank = 6;
                break;
        }
        return rank;
    }
}
