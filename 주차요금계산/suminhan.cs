using System;
using System.Collections.Generic;
using System.Linq;
public class Solution {
    public int[] solution(int[] fees, string[] records) {
        Dictionary<string,ParkData> dicParkData = new Dictionary<string,ParkData>();
        foreach(string record in records)
        {
            string[] data = record.Split(' ');
            string sTime = data[0];
            string nCarNum = data[1];
            string sInOut = data[2];
            
            if(!dicParkData.ContainsKey(nCarNum))
                dicParkData[nCarNum] = new ParkData();
            dicParkData[nCarNum].setData(data[0], sInOut);
        }
        
        int nCount = 0;
        int[] answer = new int[dicParkData.Count];
        foreach (KeyValuePair<string, ParkData> data in dicParkData.OrderBy(i => i.Key)) //차량번호 정렬하여 계산
        {
            ParkData parkData = data.Value;
            answer[nCount++] = (GetTotalFee(parkData, fees));
        }
             
        return answer;
    }
    
    public int GetTotalFee(ParkData parkData, int[] fees)   //총 주차시간으로 요금계산한다
    {
        int nMinute = 0;
        int nInCount = parkData.nInMin.Count;
        int nOutCount = parkData.nOutMin.Count;
        if(nInCount != nOutCount)   //Out 출차를 안했을 때
        {
            for(int nIndex = 0; nIndex < nInCount; nIndex++)
            {
                if(nIndex < nOutCount) // Out 배열 인덱스를 벗어나면
                    nMinute += parkData.nOutMin[nIndex] - parkData.nInMin[nIndex];
                else
                    nMinute += 1439 - parkData.nInMin[nIndex];  //출차시간 23:59으로 계산
            }
        }
        else
        {
            for(int nIndex = 0; nIndex < nInCount; nIndex++)
            {
                nMinute += parkData.nOutMin[nIndex] - parkData.nInMin[nIndex];
            }
        }
        
        return GetFee(nMinute, fees);
    }
    
    public int GetFee(int nMinute, int[] fees)
    {        
        int nFee = fees[1];
        nMinute -= fees[0];

        if (nMinute > 0)
        {
            int a = (int)Math.Ceiling((double)nMinute / fees[2]);
            nFee += fees[3] * a;
        }
        return nFee;        
    }
}

public class ParkData   //주차데이터
{
    public List<int> nInMin;
    public List<int> nOutMin;
    
    public ParkData()   //생성자
    {
        nInMin = new List<int>();
        nOutMin = new List<int>();
    }
    
    public void setData(string sTime, string sInOut)    //주차시간(분으로 변환)을 저장한다
    {
        TimeSpan ts = TimeSpan.Parse(sTime);
         int nMinute = (ts.Hours * 60) + ts.Minutes;
        
        if(Equals(sInOut,"IN"))
            nInMin.Add(nMinute);
        else if(Equals(sInOut,"OUT"))
            nOutMin.Add(nMinute);       
    }  
}
