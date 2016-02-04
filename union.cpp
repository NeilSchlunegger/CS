#include <iostream>
#include <set>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	for(int i = 0; i < argc; i++)
	{
		cout << "Arg[" << i << "]=" << argv[i] << endl;
	}

	set<string> setA;
	set<string> setB;
	string buffer;
	vector<string> result;

	cout << "Enter set a: ";
	while(cin.peek() != '\n')
	{
		cin >> buffer;
		setA.insert(setA.begin(),buffer);
	}
	cin.ignore(9812,'\n');

	cout << "Enter set b: ";
	while(cin.peek() != '\n')
	{
		cin >> buffer;
		setB.insert(setB.begin(),buffer);
	}
	cin.ignore(9812,'\n');

	// b/c biggest it can be is size of a + size of b (for a union), it's the size of the biggest it can be
	result.resize(setA.size() + setB.size());
	auto itr = set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), result.begin());
	result.resize(itr - result.begin()); // shrinking vector down to its smallest size it can be
	cout << "a union b has " << result.size() << " elements: ";
	for(auto itm : result)
	{		
		cout << itm << " ";
	}
	cout << endl;
	result.clear();
	
	return 0;
}
