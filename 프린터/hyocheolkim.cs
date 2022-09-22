using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
            int Position = 0;
            bool Print = false;
            Queue<int> q = new Queue<int>();
            for (int i = 0; i < priorities.Length; i++)
            {
                q.Enqueue(priorities[i]);
            }
            while (q.Count > 0)
            {
                if (q.Max() <= q.Peek())
                {
                    answer++;
                    Print = true;
                    q.Dequeue();
                }
                else
                {
                    Print = false;
                    q.Enqueue(q.Dequeue());
                }
                Position++;
                if (location == (Position - 1) && Print)
                {
                    break;
                }
                else if (location == (Position - 1) && Print == false)
                {
                    Position = 0;
                    location = q.Count - 1;
                }
            }
            return answer;
    }
}
