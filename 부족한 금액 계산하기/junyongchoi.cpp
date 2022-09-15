#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long nLastPrice = price * count;
    long long nSumPrice = (price + nLastPrice) * count / 2;
    return nSumPrice >= money ? nSumPrice - money : 0;
}
