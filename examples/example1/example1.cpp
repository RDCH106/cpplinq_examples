#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "CppLinq\cpplinq.hpp"

using namespace std;
using namespace cpplinq;


int nListLenght = 20;

void SumExample()
{
	cout << "Sum Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the sum of the values
	int nSum = from(lstInteger)
		>> sum();
	cout << "Sum: " << std::to_string(nSum) << endl;
}

void AverageExample()
{
	cout << "Average Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the average of the values
	int nAvg = from(lstInteger)
		>> avg();
	cout << "Avg: " << std::to_string(nAvg) << endl;
}

void WhereExample1()
{
	//The numbers must be bigger than this to be counted
	int nMinValue = 10;

	cout << "Average Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the count of values whose are bigger than 20
	int nCount = from(lstInteger)
		>> where([&, nMinValue](int const & g) {	return g > nMinValue; })
		>> select([](int const & g) {return g; })
		>> count();

	cout << "Numbes bigger than "<< nMinValue << " Cont: " << std::to_string(nCount) << endl;
}

int main()
{
	SumExample();
	AverageExample();
	WhereExample1();
	char letter;
	cin >> letter;
}