#include <iostream>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

//vector<vector<set<string>>> power(set<set<string>> mySet, int setASize, int setBSize);

std::vector<std::vector<std::vector<string>>> getPowerSet(std::vector<std::vector<string>> myVec, int vecSize);

bool domainConsumption(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myA);
bool uniqueImage(std::vector<std::vector<std::vector<string>>> myPowerSet, int index);
std::vector<std::vector<string>> injection(std::vector<std::vector<std::vector<string>>> myPowerSet, int index);
std::vector<std::vector<string>> surjection(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myB);
std::vector<std::vector<string>> reflexive(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myA);
std::vector<std::vector<string>> symmetric(std::vector<std::vector<std::vector<string>>> myPowerSet, int index);
std::vector<std::vector<string>> transitive(std::vector<std::vector<std::vector<string>>> myPowerSet, int index);
std::vector<std::vector<string>> antiSymmetric(std::vector<std::vector<std::vector<string>>> myPowerSet, int index);
std::vector<int> findEquivalence(std::vector<std::vector<std::vector<string>>> myPowerSet, std::vector<string> myA);
std::vector<int> findPartial(std::vector<std::vector<std::vector<string>>> myPowerSet, std::vector<string> myA);

void q1(std::vector<string> myA, std::vector<string> myB);
void q2(std::vector<string> myA);
void q3(std::vector<std::vector<std::vector<string>>> myInj);
void q4(std::vector<std::vector<std::vector<string>>> myInj);
void q5(std::vector<std::vector<std::vector<string>>> mySur);
void q6(std::vector<std::vector<std::vector<string>>> mySur);
void q7(std::vector<int> myEquivalence, std::vector<std::vector<std::vector<string>>> myPowerSet);
void q8(std::vector<int> myPo, std::vector<std::vector<std::vector<string>>> myPowerSet);

int main()
{
	std::vector<string> setA;
	std::vector<string> setB;
	stringstream stream;
	string input;

	cout << "CS251 Assignment 2 - Neil Schlunegger" << endl;
	cout << "Enter elements for set A followed by <enter> (no trailing spaces): ";
	getline(cin, input);
	stream << input;
	while (stream.good())
	{
		int checkCount = 0;
		string buffer;
		getline(stream, buffer, ' ');
		for (auto check : setA)
		{
			if (check == buffer) // working with vector but still can't have repeated elements
			{
				checkCount++;
			}
		}
		if (checkCount == 0)
		{
			setA.push_back(buffer);
		}
	}
	stream.clear();
	cout << endl;

	cout << "Enter elements for set B followed by <enter> (no trailing spaces): ";
	getline(cin, input);
	stream << input;
	while (stream.good())
	{
		int checkCount = 0;
		string buffer;
		getline(stream, buffer, ' ');
		for (auto check : setB)
		{
			if (check == buffer)
			{
				checkCount++;
			}
		}
		if (checkCount == 0)
		{
			setB.push_back(buffer);
		}

	}
	stream.clear();
	cout << endl;

	//Populate cross products
	std::vector<std::vector<string>> aByA;
	for (auto a : setA)
	{
		for (auto aA : setA)
		{
			std::vector<string> tempVec;
			tempVec.push_back(a);
			tempVec.push_back(aA);
			aByA.push_back(tempVec);
		}
	}
	std::vector<std::vector<string>> aByB;
	for (auto a : setA)
	{
		for (auto b : setB)
		{
			std::vector<string> tempVec;
			tempVec.push_back(a);
			tempVec.push_back(b);
			aByB.push_back(tempVec);
		}
	}

	//Populate power sets
	std::vector<std::vector<std::vector<string>>> powerSet;
	std::vector<std::vector<std::vector<string>>> aaPowerSet;
	powerSet = getPowerSet(aByB, aByB.size());
	aaPowerSet = getPowerSet(aByA, aByA.size());

	//print sets
	cout << "\nSET A has elements: ";
	for (auto it = setA.begin(); it != setA.end(); it++)
	{
		cout << "{" << *it << "} ";
	}
	cout << "\nAnd size: " << setA.size();
	cout << "\nSET B has elements: ";
	for (auto it = setB.begin(); it != setB.end(); it++)
	{
		cout << "{" << *it << "}" << " ";
	}
	cout << "\nAnd size: " << setB.size();

	cout << "\nA X B has elements: { ";
	for (auto set1 : aByB)
	{
		cout << "(";
		unsigned int splitChk = 0;
		for (auto set2 : set1)
		{
			cout << set2;
			if (splitChk < set1.size() - 1)
			{
				cout << ",";
			}
			splitChk++;
		}
		cout << ") ";
	}
	cout << "}";
	cout << "\nAnd size: " << aByB.size();
	cout << endl;

	cout << "POWER SET of A X B has elements: {";
	for (auto pwr : powerSet)// vector
	{
		cout << " {";
		for (auto inside : pwr) // vector
		{
			unsigned int temp = 0;
			cout << "(";
			for (auto elements : inside) // strings
			{
				cout << elements;
				if (temp < (inside.size() - 1))
				{
					cout << ",";
				}
				temp++;
			}
			cout << ")";
		}
		cout << "} ";
	}
	cout << "}";
	cout << "\nAnd size: " << powerSet.size() << endl;

	// Populate injective, surjective
	std::vector<std::vector<string>> tempInjective;
	std::vector<std::vector<string>> tempSurjective;
	std::vector<std::vector<std::vector<string>>> injective;
	std::vector<std::vector<std::vector<string>>> surjective;
	for (unsigned int i = 0; i < powerSet.size(); i++)
	{
		bool hasDC = domainConsumption(powerSet, i, setA);
		
		if (hasDC)
		{
			bool hasUI = uniqueImage(powerSet, i);
			
			if (hasUI)
			{
				tempInjective = injection(powerSet, i);
				
				if (tempInjective.size() > 0)
				{
					injective.push_back(tempInjective);
				}
				
				tempSurjective = surjection(powerSet, i, setB);

				if (tempSurjective.size() > 0)
				{
					surjective.push_back(tempSurjective);
				}
			}
		}
	}

	//Populate equivalence, partial order
	std::vector<int> equivalence = findEquivalence(aaPowerSet, setA);
	std::vector<int> partialOrder = findPartial(aaPowerSet,setA);
	
	cout << "\nBEGIN HOMEWORK QUESTIONS\n" << endl;
	q1(setA, setB);
	q2(setA);
	q3(injective);
	q4(injective);
	q5(surjective);
	q6(surjective);
	q7(equivalence, aaPowerSet);
	q8(partialOrder, aaPowerSet);
	system("pause");
	return 0;
}

std::vector<std::vector<std::vector<string>>> getPowerSet(std::vector<std::vector<string>> myVec, int vecSize)
{
	std::vector<std::vector<std::vector<string>>> myPowerSet;
	std::vector<std::vector<string>> temp1;
	std::vector<std::vector<string>> temp2;
	std::vector<string> nullSet;

	for (auto itr : myVec) // put the cartesian product in temp1
	{
		temp1.push_back(itr);
	}
	temp2.push_back(nullSet); // put null into temp2
	myPowerSet.push_back(temp2); // put null (temp 2) into power set 
	temp2.clear();

	for (auto itr : temp1)
	{
		temp2.push_back(itr); // push 1st element (1st ordered pair of AxB) into temp2
		break;
	}
	myPowerSet.push_back(temp2); // put temp2 (1st ordered of AxB) into power set
	temp2.clear();

	int card = static_cast<int>(pow(2, vecSize)); // put rest of ordered pairs into power set...{(x1, y1)}{(x1,y2)}{(x1,y1),(x1,y2)}{(x2,y1)}..
	for (int i = 2; i < card; i++)
	{
		int num = i;

		int j = 0;
		while (num >= 1)
		{
			while ((num % 2) == 0)
			{
				num >>= 1;
				j++;
			}
			if ((num % 2) == 1)
			{
				temp2.push_back(temp1[j]); // put the elements of temp1(the original cross product) into temp2
				j++;
			}
			num >>= 1;
		}
		myPowerSet.push_back(temp2); // put temp 2 into the power set which we return
		temp2.clear();
	}

	return myPowerSet;
}

bool domainConsumption(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myA)
{
	int domainCount = 0;
	std::vector<std::vector<string>> fullRelation = myPowerSet[index];

	for (auto a : myA)
	{
		for (auto f : fullRelation)
		{
			bool found = false;
			for (auto elements : f)
			{
				if (elements == a)
				{
					domainCount++;
					found++;
				}
				break;
			}
			if (found)
			{
				break;
			}
		}
	}

	return (domainCount == myA.size());
}

bool uniqueImage(std::vector<std::vector<std::vector<string>>> myPowerSet, int index)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];

	for (auto r : relations)
	{
		string first = r[0];
		string second = r[1];

		for (auto elements : relations)
		{
			if (first == elements[0] && second == elements[1])
			{
				continue;
			}
			else if (first != elements[0])
			{
				continue;
			}
			else if (first == elements[0] && second != elements[1])
			{
				return false;
			}
		}
	}

	return true;
}

std::vector<std::vector<string>> injection(std::vector<std::vector<std::vector<string>>> myPowerSet, int index)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];
	std::vector<std::vector<string>> temp;

	for (auto r : relations)
	{
		string first = r[0];
		string second = r[1];

		for (auto elements : relations)
		{
			if (first == elements[0] && second == elements[1]) // look if
			{
				temp.push_back(elements);
				continue;
			}
			else if (first != elements[0] && second == elements[1]) // base case
			{
				temp.clear();
				return temp;
			}
		}
	}

	return temp;
}

std::vector<std::vector<string>> surjection(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myB)
{
	int sCount = 0;
	std::vector<std::vector<string>> fullRelation = myPowerSet[index];
	std::vector<std::vector<string>> temp;
	std::vector<std::vector<string>> temp2;

	for (auto b : myB)
	{
		for (auto f : fullRelation)
		{
			bool found = false;
			bool first = true;
			for (auto elements : f)
			{
				if ((elements == b && first != true))
				{
					temp.push_back(f);
					sCount++;
					found++;
				}
				first = false;
			}
			if (found)
			{
				break;
			}
		}
	}

	if (sCount == myB.size())
	{
		return temp;
	}

	temp.clear();
	return temp;
}
std::vector<std::vector<string>> reflexive(std::vector<std::vector<std::vector<string>>> myPowerSet, int index, std::vector<string> myA)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];
	std::vector<std::vector<string>> reflexives;
	reflexives.reserve(myA.size());

	int rCount = 0;
	bool first = false;

	for (unsigned int a = 0; a < myA.size(); a++)
	{
		for (auto r : relations)
		{
			if (r.size() == 0)
			{
				reflexives.clear();
				return reflexives;
			}
			if (!first)
			{
				reflexives.push_back(r);
			}
			if (r[0] == myA[a] && r[1] == myA[a])
			{
				rCount++;
				continue;
			}
			else
			{

				continue;
			}
		}
		first++;
	}
	if (rCount == myA.size())
	{
		return reflexives;
	}
	else
	{
		reflexives.clear(); // no
		return reflexives;
	}
}

std::vector<std::vector<string>> symmetric(std::vector<std::vector<std::vector<string>>> myPowerSet, int index)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];
	std::vector<std::vector<string>> symmetrics;

	int sCount = 0;

	for (auto r : relations)
	{
		if (r.size() == 0)
		{
			symmetrics.clear();
			return symmetrics;
		}
		string first = r[0];
		string second = r[1];

		for (auto q : relations)
		{
			if ((first == q[0] && second == q[1]) && (first == second))
			{
				symmetrics.push_back(r);
				sCount++;
				break;
			}
			else if (first == q[1] && second == q[0])
			{
				symmetrics.push_back(r);
				sCount++;
				break;
			}
		}
	}
	if (sCount == relations.size())
	{
		return symmetrics;
	}
	symmetrics.clear();
	return symmetrics;
}

std::vector<std::vector<string>> transitive(std::vector<std::vector<std::vector<string>>> myPowerSet, int index)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];
	std::vector<std::vector<string>> transitives;

	int tCount = 0;

	for (auto r : relations)
	{
		int countTest = 0;
		if (r.size() == 0)
		{
			transitives.clear();
			return transitives;
		}
		string first = r[0];
		string second = r[1];

		bool added = false;
		for (auto q : relations)
		{
			if (added)
			{
				break;
			}
			if ((first == q[0] && second == q[1]) && (first == second))
			{
				transitives.push_back(r);
				tCount++;
				break;
			}
			if (second == q[0])
			{
				string third = q[1];
				for (auto s : relations)
				{

					if (first == s[0] && third == s[1])
					{
						transitives.push_back(r);
						tCount++;
						added++;
						break;
					}
					continue;
				}
			}
		}
		countTest++;
		if (countTest > tCount)
		{
			transitives.clear();
			return transitives;
		}
	}

	if (tCount == relations.size())
	{
		return transitives;
	}
	transitives.clear();
	return transitives;
}

std::vector<std::vector<string>> antiSymmetric(std::vector<std::vector<std::vector<string>>> myPowerSet, int index)
{
	std::vector<std::vector<string>> relations = myPowerSet[index];
	std::vector<std::vector<string>> antiSymmetrics;

	int antiCount = 0;

	for (auto r : relations)
	{
		if (r.size() == 0)
		{
			antiSymmetrics.clear();
			return antiSymmetrics;
		}
		string first = r[0];
		string second = r[1];

		if ((relations.size() < 2) && (first != second))
		{
			antiSymmetrics.push_back(r);
			antiCount++;
			return antiSymmetrics;
		}
		else if (first == second)
		{
			antiSymmetrics.push_back(r);
			antiCount++;
			continue;
		}
		for (auto q : relations)
		{
			if (first == q[0] && second == q[1])
			{
				continue;
			}
			else if (first == q[1] && second == q[0])
			{
				antiSymmetrics.clear();
				return antiSymmetrics;
			}
			continue;
		}
		antiSymmetrics.push_back(r);
		antiCount++;
	}

	if (antiCount == relations.size())
	{
		return antiSymmetrics;
	}

	antiSymmetrics.clear();

	return antiSymmetrics;
}

std::vector<int> findEquivalence(std::vector<std::vector<std::vector<string>>> myPowerSet, std::vector<string> myA)
{
	std::vector<int> tempEq;
	std::vector<std::vector<std::string>> isReflexive;
	std::vector<std::vector<std::string>> isSymmetric;
	std::vector<std::vector<std::string>> isTransitive;

	for (unsigned int i = 0; i < myPowerSet.size(); i++)
	{
		isReflexive = reflexive(myPowerSet, i, myA);
		isSymmetric = symmetric(myPowerSet, i);
		isTransitive = transitive(myPowerSet, i);

		if (isReflexive.size() > 0 && isSymmetric.size() > 0 && isTransitive.size() > 0)
		{
			tempEq.push_back(i);// has to be reflexive, symmetric and transitive
		}
	}
	return tempEq;
}

std::vector<int> findPartial(std::vector<std::vector<std::vector<string>>> myPowerSet, std::vector<string> myA)
{
	std::vector<int> tempPo;
	std::vector<std::vector<std::string>> isReflexive;
	std::vector<std::vector<std::string>> isAnti;
	std::vector<std::vector<std::string>> isTransitive;

	for (unsigned int i = 0; i < myPowerSet.size(); i++)
	{
		isReflexive = reflexive(myPowerSet, i, myA);
		isAnti = antiSymmetric(myPowerSet, i);
		isTransitive = transitive(myPowerSet, i);

		if (isReflexive.size() > 0 && isAnti.size() > 0 && isTransitive.size() > 0)
		{
			tempPo.push_back(i);// has to be reflexive, antisymmetric and transitive
		}
	}
	return tempPo;
}

void q1(std::vector<string> myA, std::vector<string> myB)
{
	int relationsAB = myA.size() * myB.size();
	int num = static_cast<int>(pow(2, relationsAB));

	cout << "--a--\nNumber of relations from A to B: " << num << endl;
}
void q2(std::vector<string> myA)
{
	int relationsA = myA.size() * myA.size();
	int num = static_cast<int>(pow(2, relationsA));

	cout << "--b--\nNumber of relations from A to A: " << num << endl;
}
void q3(std::vector<std::vector<std::vector<string>>> myInj)
{
	cout << "--c--\nNumber of injective functions from A to B: " << myInj.size() << endl;
}
void q4(std::vector<std::vector<std::vector<string>>> myInj)
{
	cout << "--d--\nThe set form of these injective functions is: { ";
	for (auto inj : myInj)
	{
		cout << "{";
		for (auto inside : inj)
		{
			cout << "(";
			unsigned int temp = 0;
			for (auto elements : inside)
			{
				cout << elements;
				if (temp < inside.size() - 1)
				{
					cout << ",";
				}
				temp++;
			}
			cout << ")";
		}
		cout << "} ";
	}
	cout << "}" << endl;
}

void q5(std::vector<std::vector<std::vector<string>>> mySur)
{
	cout << "--e--\nNumber of surjective functions from A to B: " << mySur.size() << endl;
}
void q6(std::vector<std::vector<std::vector<string>>> mySur)
{
	cout << "--f--\nThe set form of these surjective functions is: { ";
	for (auto sur : mySur)
	{
		cout << "{";
		for (auto inside : sur)
		{
			cout << "(";
			unsigned int temp = 0;
			for (auto elements : inside)
			{
				cout << elements;
				if (temp < inside.size() - 1)
				{
					cout << ",";
				}
				temp++;
			}
			cout << ")";
		}
		cout << "} ";
	}
	cout << "}" << endl;
}

void q7(std::vector<int> myEquivalence, std::vector<std::vector<std::vector<string>>> myPowerSet)
{
	cout << "--g--" << endl;
	cout << "The equivalence relations on set A in set form: { ";
	for (auto eq : myEquivalence)
	{
		cout << "{";
		for (auto inside : myPowerSet[eq])
		{
			unsigned int temp = 0;
			cout << "(";
			for (auto elements : inside)
			{
				cout << elements;
				if (temp < inside.size() - 1)
				{
					cout << ",";
				}
				temp++;
			}
			cout << ")";
		}
		cout << "} ";
	}
	cout << "}" << endl;
	cout << "Which has size: " << myEquivalence.size() << endl;
}

void q8(std::vector<int> myPo, std::vector<std::vector<std::vector<string>>> myPowerSet)
{
	cout << "--h--" << endl;
	cout << "The partial order relations on set A in set form: { ";
	
	for (auto po : myPo)
	{
		cout << "{";
		for (auto inside : myPowerSet[po])
		{
			unsigned int temp = 0;
			cout << "(";
			for (auto elements : inside)
			{
				cout << elements;
				if (temp < inside.size() - 1)
				{
					cout << ",";
				}
				temp++;
			}
			cout << ")";
		}
		cout << "} ";
	}
	cout << "}" << endl;
	cout << "Which has size: " << myPo.size() << endl;
}
/*
set<set<string>> *power(const set<string> *passedSetString, size_t passedSetStringSize)
{
	set<set<string>> *result = new set<set<string>>;

	if (passedSetStringSize > 0)
	{
		set<set<string>> *temp = power(passedSetString, passedSetStringSize - 1);
		for (auto itr1 = temp->begin(); itr1 != temp->end(); itr1++)
		{
			for (auto itr2 = passedSetString->begin(); itr2 != passedSetString->end(); itr2++)
			{
				set<string> temp2(*itr1);
				temp2.insert(*itr2);
				result->insert(temp2);
			}
			result->insert(temp->begin(), temp->end());
		}
	}
	else
	{
		result->insert(set<string>()); // base case - insert null element
	}

	return result;
}*/
// experimental iterative solution
/*std::vector<std::vector<std::vector<string>>> getPowerSet(std::vector<std::vector<string>> myVec, int vecSize)
{
	std::vector<std::vector<std::vector<string>>> myPowerSet;
	std::vector<std::vector<string>> temp1;
	std::vector<std::vector<string>> temp2;
	std::vector<string> nullSet;

	for (auto itr : myVec) // put the cartesian product in temp1
	{
		temp1.push_back(itr);
	}
	temp2.push_back(nullSet); // put null into temp2
	myPowerSet.push_back(temp2); // put null (temp 2) into power set 
	temp2.clear();

	for (auto itr : temp1)
	{
		temp2.push_back(itr); // push 1st element (1st ordered pair of AxB) into temp2
		break;
	}
	myPowerSet.push_back(temp2); // put temp2 (1st ordered of AxB) into power set
	temp2.clear();

	int card = static_cast<int>(pow(2, vecSize)); // put rest of ordered pairs into power set...{(x1, y1)}{(x1,y2)}{(x1,y1),(x1,y2)}{(x2,y1)}..
	for (int i = 2; i < card; i++)
	{
		int num = i;

		int j = 0;
		while (num >= 1)
		{
			while ((num % 2) == 0)
			{
				num >>= 1;
				j++;
			}
			if ((num % 2) == 1)
			{
				temp2.push_back(temp1[j]); // put the elements of temp1(the original cross product) into temp2
				j++;
			}
			num >>= 1;
		}
		myPowerSet.push_back(temp2); // put temp 2 into the power set which we return
		temp2.clear();
	}

	return myPowerSet;
}*/
