#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;


int nListLenght = 20;

void AverageExample()
{
	cout << "Average Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(std::rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the average of the values
	int nAvg = from(lstInteger)
		>> avg();
	cout << "Avg: " << std::to_string(nAvg) << endl;
}

int main()
{
	AverageExample();
  do
  {
    cout << '\n' << "Press enter to continue...";
  } while (cin.get() != '\n');
}