#include <iostream>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

void printArray(int* arr, size_t pSize)
{
        for(int i = 0; i < pSize; i++)
        {
            cout << arr[i] << " ";
        }
}
string maximumSubArray(int* arr, size_t passedSize) // or int[] arr?
{
    //cout << showpos;
    int maximum = 0;
    std::pair<int,int> myPair(0,0);
    for(int i = 0; i < passedSize; i++)
    {
        int current = 0;
        for(int j = i; j < passedSize; j++)
        {
            current += arr[j];
            cout << "current is " << current << ", when i = " << i << " and j = " << j << endl;
            if(current > maximum)
            {
                maximum = current;
                myPair.first = i;
                myPair.second = j;
            }
        }
        cout << "max at end of i = " << i << " is " << maximum << endl;
    }
    //cout << "i = " << myPair.first << "j = " << myPair.second << endl;
    std::stringstream ss;
    ss << myPair.first << " " << myPair.second << " " << maximum;
    string myValues = ss.str();
    return myValues;
}
int main()
{
    srand(time(0));
    int array[5];
    for(int i = 0; i < 5; i++)
    {
        array[i] = rand() % 10 + (-3);
    }
    size_t arraySize = sizeof(array)/sizeof(array[0]);
    printArray(array,arraySize);
    cout << endl;
    string answer = maximumSubArray(array, arraySize);
    stringstream ss;
    ss << answer;
    int index1, index2, maximum;
    ss >> index1 >> index2 >> maximum;
    cout << "The first index is " << index1 << endl;
    cout << "The second index is " << index2 << endl;
    cout << "The maximum subarray is " << maximum;


    return 0;
}
