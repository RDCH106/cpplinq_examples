#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;


int nListLenght = 20;

void WhereExample()
{
	//The numbers must be bigger than this to be counted
	int nMinValue = 10;

	cout << "Average Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(std::rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the count of values whose are bigger than 20
	int nCount = from(lstInteger)
		>> where([&, nMinValue](int const & g) {	return g > nMinValue; })
		>> count();

	cout << "Numbes bigger than " << nMinValue << " Cont: " << std::to_string(nCount) << endl;
}

int main()
{
	WhereExample();
	do
	{
		cout << '\n' << "Press enter to continue...";
	} while (cin.get() != '\n');
}