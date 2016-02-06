//GCD USING EUCLIDEAN ALGORITHM
#include <iostream>
#include <gmpxx.h>
using namespace std;
mpz_class gcd_iter(mpz_class u, mpz_class v)
 {
  mpz_class t;
  while (v) {
    t = u; 
    u = v; 
    v = t % v;
  }
  return u < 0 ? -u : u; /* abs(u) */
}
int main()
{
	mpz_class u, v;
	cout << "Enter two numbers separated by a space: ";
	cin >> u >> v;
	cout <<	"gcd is " << gcd_iter(u,v) << endl;
	return 0;
}

	//g++ -lgmpxx -lgmp -std=c++11 -o main.exe euclidean.cpp
