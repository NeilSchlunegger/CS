#include <iostream> 
#include <iomanip>                               
#include <gmpxx.h>                             
#include <algorithm>    
#include <cmath>
#include <set>

using namespace std;

void problem1();
void problem2();
void bigNums();
unsigned long int factorial(unsigned long int n);
mpz_class fact(unsigned int n)
{
	mpz_class result(n);
	while(n --> 1) result *= n;
	return result;
}

int main()
{
//problem1();
//	problem2();
bigNums();
return 0;
}

unsigned long int factorial(unsigned long int n)
{
	if(n==0)
		return 1;
	else
		return n * factorial(n-1);
}

void problem1()
{
/*	mpz_class count = 0;
	mpz_class y = 0;
	mpz_class max = pow(2,50) - 1;
	mpz_class temp = 1;

	for(mpz_class i = 1; i <= 99999999; i++)
	{
		y = (3*pow(i,3)); // need a GMP power function of some sort

		if(y <= max)
		{
			temp = y;
			count++;
		}
	}
	*/unsigned long long int count = 0;
	unsigned long long int y = 0;
	unsigned long long int max = pow(2,50) - 1;
	unsigned long long int temp = 1;
	for(int i = 1; i <= 99999999; i++)
	{
		y = ((3 * pow(i, 3)) + (pow(i,2)) - (2 * i) + 4) / (3 * i + 4);

		if(y <= max)
		{	
			temp = y;
			count++;}
		}
	cout << "the biggest value was " << temp << " (may have overflowed, 112...192? Yep)" << endl;
	// count goes from 1 to max. So you have to include (-max + 1) to -1 b/c of absolute value, and 0, which means times by 2
	cout << "set cardinality: " << count * 2 << " elements" << endl;
}

void problem2()
{
	set<unsigned long int> summationSet; // Xn
	set<unsigned long int> bigPiSet; // Yn
	set<unsigned long int> theIntersection;
	set<unsigned long int>::iterator it;
	unsigned long int sum = 0;
	unsigned long int bigPi = 1;
	// populate sets
	for (unsigned long int i = 1; i <= 13; i++)
	{
		sum += factorial(i);
		summationSet.insert(sum);
	}
	for(unsigned long int i = 1; i <= 6; i++)
	{
		bigPi*= factorial(i);
		bigPiSet.insert(bigPi);
	}
	//print elements before merging
	cout << "summation set has elements { ";
	for (auto it = summationSet.begin(); it != summationSet.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "}" << endl << endl;

	cout << "big pi set has elements { ";
	for (auto it = bigPiSet.begin(); it != bigPiSet.end(); it++)
	{
	cout << *it << " ";
	}
	cout << "}" << endl << endl;
	
	// merge sets
	set_intersection(summationSet.begin(), summationSet.end(), bigPiSet.begin(), bigPiSet.end(), insert_iterator<set<unsigned long int> >(theIntersection, theIntersection.begin()));
	
	cout << "merged intersection has elements { ";
	for (auto it = theIntersection.begin(); it != theIntersection.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "}" << endl << endl;

}

void bigNums()
{
	int n;
	cout << "Get the big pi factorial of what number? ";
	cin >> n;
	
	mpz_class bigPiNum = 1;

	for(int i = 1; i <= n; i++)
	{
		bigPiNum *= fact(i);
	}
	cout << bigPiNum.get_str(10) << endl;

	int m;
	cout << "Get the summation of factorials of what number? ";
	cin >> m;

	mpz_class summation = 0;

	for(int j = 1; j <= m; j++)
	{
		summation += fact(j);
	}
	cout << summation.get_str(10) << endl;
}

