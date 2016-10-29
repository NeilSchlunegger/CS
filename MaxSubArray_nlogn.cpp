#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>

const int MAX = 6;

using namespace std;

int FindMaxSumSubArray(int* array, int low, int high);

int main()
{
    srand(time(0));
    int array[MAX];
    for(int i = 0; i < MAX; i++)
    {
        array[i] = rand() % 9 - 3;
        cout << array[i];
        if (i != MAX-1)
            cout << ", ";
        else
            cout << endl;
    }
   int size = sizeof(array)/sizeof(array[0]);
   int sum = FindMaxSumSubArray(array, 0, size-1);
   cout << "Maximum contiguous sum is " << sum << endl;
   return 0;

}

int FindMaxSumSubArray(int* array, int low, int high)
{
     if (low > high)// no element left
        return 0;
     if (low == high) // one left
        return max(0, array[low]);

     int middle = (low + high) / 2;

     // find maximum sum of left cross
     int leftMax = 0;
     int sum = 0;
     for (int i = middle; i >= low; i--)
        {
        sum += array[i];
        if (sum > leftMax)
            leftMax = sum;
        }

// find maximum sum of right cross
     int rightMax = 0;
     sum = 0;
     for (int i = middle+1; i <= high; i++)
        {
        sum += array[i];
        if (sum > rightMax)
            rightMax = sum;
        }

     //highest of left, right, and middle crossing
     return max((leftMax + rightMax),
     max(FindMaxSumSubArray(array,low, middle), FindMaxSumSubArray(array, middle+1, high)));
 }
