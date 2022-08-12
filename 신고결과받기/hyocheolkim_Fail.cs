using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
public class Solution {
    public int[] solution(string[] id_list, string[] report, int k) {
            ///유저아이디, 신고아이디
			Dictionary<string, string> WarningID = new Dictionary<string, string>();
			///유저아이디, 신고당한수
			Dictionary<string, int> WarningCount = new Dictionary<string, int>();
			//유저수만큼 배열 초기화
			int[] answer = new int[id_list.Length];
            foreach (string ID in id_list)
            {
                WarningID.Add(ID, "");
                WarningCount.Add(ID, 0);
            }
			///누굴 신고헸는지, 몇번 신고당헸는지
			foreach (string Report in report.Distinct())
			{
				string[] ReportID_WarningID = Report.Split(' ');
                WarningID[ReportID_WarningID[0]] += ReportID_WarningID[1];
                WarningCount[ReportID_WarningID[1]]++;
			}
			//신고 리미트 넘는 ID 확인
            KeyValuePair<string, int>[] StopUseIDList = WarningCount.Where(x => x.Value >= k).ToArray();
            foreach (KeyValuePair<string, string> pair in WarningID)
            {
                int nCount = StopUseIDList.Where(x => pair.Value.Contains(x.Key)).Count();
                if(nCount > 0){
                    int nIndex = Array.IndexOf(id_list, pair.Key);
                    answer[nIndex] = nCount;
                }
            }
			return answer;
    }
}
