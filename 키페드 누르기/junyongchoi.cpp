#include <string>
#include <vector>
#include <utility>
#include <iostream>

#define ABS(X) ((X > 0) ? X : (-X))

#define Print(Type,X,Y,Z) printf(#Type " DialNum : %d, Col : %d, Row : %d \n", X, Y, Z) // Test용
using namespace std;
void getIdx(int nDial, int& nCol, int& nRow){
    nDial--;
    nCol = nDial % 3;
    nRow = nDial / 3;
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int arrCurrent[2] ={10, 12}; // * #은 편의상 위치가 10 12위치 // idx = 0->왼손 번호 위치, idx = 1->오른손 번호 위치
    int i = 0;
    for(int& dial : numbers)
    {
        switch(dial)
        {
            case 1:
            case 4:
            case 7:
                answer += "L";
                arrCurrent[0] = dial;
                break;
            case 3:
            case 6:
            case 9:
                answer += "R";
                arrCurrent[1] = dial;
                break;
            default:
                int nDicimal = dial == 0 ? 11 : dial;
                int nDialCol, nDialRow;
                getIdx(nDicimal, nDialCol, nDialRow);
                
                int nLeftCol, nLeftRow;
                getIdx(arrCurrent[0], nLeftCol, nLeftRow);
                
                int nRightCol, nRightRow;
                getIdx(arrCurrent[1], nRightCol, nRightRow);
                
                int nLeftDist = ABS((nDialCol - nLeftCol)) + ABS((nDialRow - nLeftRow));
                int nRightDist = ABS((nDialCol - nRightCol)) + ABS((nDialRow - nRightRow));
                
                char cHand;
                if(nLeftDist < nRightDist)
                    cHand = 'L';
                else if(nLeftDist > nRightDist)
                    cHand = 'R';
                else
                    cHand = toupper(hand[0]);
                arrCurrent[cHand == 'L' ? 0 : 1] = nDicimal;
                answer += cHand;
                break;
        }
    }
    
    return answer;
}
