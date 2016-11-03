#include <iostream>
#include <cstring>
using namespace std;
const long long int MAX = 123456;
long long int fibArray[MAX];
long long int fibdyn(long long int n)
{
    fibArray[0] = 0;
    fibArray[1] = 1;
    fibArray[2] = 1;
    if(n == 0)
    {
        cout << "called n == 0 with n = " << n << endl;
                return fibArray[0];

    }
    if(n == 1)
    {
        cout << "called n == 1 with n = " << n << endl;
                return fibArray[1];
    }
    for(long long int i = 2; i < n + 1; i++)
    {
        cout << "called i = " << i << " and fibarray[" << i - 1 << "] = "<< fibArray[i-1]
        << " and fibarray[" << i-2 << "] = " << fibArray[i-2]<< endl;
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }

    return fibArray[n];

}
int main()
{
    long long int num;
    cout << "Get the fib of what number? ";
    cin >> num;
    cout << endl;

    memset(fibArray,-1, sizeof(long long int));
    cout << fibdyn(num) << endl;
    return 0;
}
