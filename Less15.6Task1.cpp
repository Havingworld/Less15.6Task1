/*
Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве,
что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

Пример:

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> a{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int nI = 0, nJ = 1, /* nBigger = 0,*/ nCalc = a[0] + a[1], nCalcTemp = 0;
    bool incRight = true;
    for (int i = 0, j = 1; j < a.size() && i<j;)
    {
        if (incRight)
        {
            nCalcTemp += a[j++];
        }
        else
        {
            nCalcTemp -= a[i++];
        }

        if (nCalcTemp > nCalc)
        {
            nCalc = nCalcTemp;
            nI = i;
            nJ = j;
            incRight = !incRight;
        }
            
    }

   
    /*
   for (int i = 0; i < a.size() - 1; i++)
    {
        int nCalc = a[i];
        for (int j = i + 1; j < a.size(); j++) 
        {
            nCalc += a[j];
            if (nCalc > nBigger) 
            {
                nBigger = nCalc;
                nI = i;
                nJ = j;
            }
        }
    }
   */ 
    
    cout << nI << " " << nJ;
}
