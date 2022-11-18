using System;
using System.Linq;
public class Solution {
    public int solution(int[] A, int[] B) {
        int answer = 0;
        Array.Sort(A);                              // A배열, 작은 숫자 순서로 정렬
        B = B.OrderByDescending(x => x).ToArray();  // B배열, 큰 숫자 순서로 정렬
        for(int i=0; i<A.Length; i++)
        {
            answer += (A[i]*B[i]);
        }
        return answer;
    }
}
