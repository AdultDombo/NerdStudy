using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        Queue<KeyValuePair<int, int>> printer = new Queue<KeyValuePair<int, int>>();
        
        for(int idx = 0; idx < priorities.Length; idx++)
        {
            printer.Enqueue(new KeyValuePair<int, int>(idx, priorities[idx]));
        }
        
        while(true)
        {
            int Max = printer.Max(x=>x.Value);
            KeyValuePair<int, int> document = printer.Dequeue();
            if (document.Value == Max)
            {
                if (document.Key == location)
                    return (answer + 1);
                else
                {
                    answer++;
                    continue;
                }
            }
            printer.Enqueue(document);
            
        }
    }
}
