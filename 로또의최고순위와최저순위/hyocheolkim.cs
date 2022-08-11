using System.Linq;

namespace programmers
{
	public class Solution
	{
		public int[] solution(int[] lottos, int[] win_nums)
		{
			int[] answer = new int[2];
			int Sum = 0;
			int Zero = 0;
			foreach (int CheckNo in lottos)
			{
				if (win_nums.Contains(CheckNo))
					Sum++;
				else if (CheckNo == 0)
					Zero++;
			}

			answer[0] = RankCheck((Sum + Zero));
			answer[1] = RankCheck(Sum);

			return answer;
		}
		private int RankCheck(int WinNo)
		{
			int Rank = 6;

			switch (WinNo)
			{
				case 6:
					Rank = 1;
					break;
				case 5:
					Rank = 2;
					break;
				case 4:
					Rank = 3;
					break;
				case 3:
					Rank = 4;
					break;
				case 2:
					Rank = 5;
					break;
			}
			return Rank;
		}
	}
}
