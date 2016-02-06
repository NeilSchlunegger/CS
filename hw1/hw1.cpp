#include <iostream>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <ctime>

using namespace std;

const int MAX_ELEMENTS = 1000;

void display(set<string> aStringSet, string name);
void cardinality(set<string> aStringSet, string name);
int cardPower(set<string> aStringSet);

int main()
{
	set<string> setA, setB;
	set<string> intersection, aUnionB, aRelativeB, bRelativeA, aSymmB;
	set<pair<string, string>> aBinB2;
	string input;
	istringstream inputStream;
	string buffer[MAX_ELEMENTS];

	int aBinBPowerSet = 0, aSymmBPowerSet = 0;
	int i = 0, j = 0;

	cout << "CS251 HW1 - Neil Schlunegger" << endl;
	// user input to populate set A & set B
	cout << "1) Enter terms for SET A separated by a space (Do not enter a space after your last term): ";
	getline(cin, input);
	inputStream.str(input);

	while(!inputStream.eof())
	{
		inputStream >> buffer[i];
		setA.insert(buffer[i]);
		i++;
	}

	inputStream.clear();
	cout << "2) Enter terms for SET B separated by a space (Do not enter a space after your last term): ";
	getline(cin, input);
	inputStream.str(input);
	
	while(!inputStream.eof())
	{
		inputStream >> buffer[j];
		setB.insert(buffer[j]);
		j++;
	}

	// Calculate sets
	set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), insert_iterator<set<string> >(intersection, intersection.begin()));
	set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), insert_iterator<set<string> >(aUnionB, aUnionB.begin()));
	set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), insert_iterator<set<string> >(aRelativeB, aRelativeB.begin()));
	set_difference(setB.begin(), setB.end(), setA.begin(), setA.end(), insert_iterator<set<string> >(bRelativeA, bRelativeA.begin()));
	set_symmetric_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), insert_iterator<set<string> >(aSymmB, aSymmB.begin()));
	for(auto a : setA) // populate the binary product
	{
		for(auto b : setB)
		{
			pair<string, string> temp;
			temp.first = a;
			temp.second = b;
			aBinB2.insert(temp);
		}
	}

	// Display what's in set A & set B for verification
 	display(setA, "SET A");
	cardinality(setA, "SET A");
	display(setB, "SET B");
	cardinality(setB, "SET B");
	cout << endl;
	// Display the problem numbers and their answers
	cout << "\n3a:";
	cardinality(intersection, "A \u2229 B");
	display(intersection, "A \u2229 B");
	cout << endl;

	cout << "\n3b:";
	cardinality(aUnionB, "A \u222A B");
	display(aUnionB, "A \u222A B");
	cout << endl;

	cout << "\n3c:";
	cardinality(aRelativeB, "A - B");
	display(aRelativeB, "A - B");
	cout << endl;

	cout << "\n3d:";
	cardinality(bRelativeA, "B - A");
	display(bRelativeA, "B - A");
	cout << endl;

	cout << "\n3e:";
	cardinality(aSymmB, "A \u0394 B");
	display(aSymmB, "A \u0394 B");
	cout << endl;
	
	cout << "\n3f: \nCardinality of A binary product B is " << aBinB2.size() << endl;
	cout << "Roster of A binary product B { ";
	for( auto val : aBinB2)
	{
		cout << "(" << val.first << "," << val.second << ")";
	}
	cout << " }" << endl;

	cout << "\n3g: \nCardinality of Power Set(A binary product B): ";
	int tempSize = aBinB2.size();
	aBinBPowerSet = pow(2, tempSize);
	cout << aBinBPowerSet << endl;
	
	aSymmBPowerSet = cardPower(aSymmB);
	cout << "\n3h:\nCardinality of Power Set(A \u0394 B): " << aSymmBPowerSet << endl;

	cout << endl;

	return 0;
}

void display(set<string> aStringSet, string name)
{
	set<string>::iterator it;

	cout << "\nRoster of " << name << ": { ";
	for(auto it = aStringSet.begin(); it != aStringSet.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "}";
}

void cardinality(set<string> aStringSet, string name)
{
	cout << "\nCardinality of " << name << " is " << aStringSet.size();
}

int cardPower(set<string> aStringSet)
{
	int size = aStringSet.size();
	int card = pow(2, size);

	return card;
}	


