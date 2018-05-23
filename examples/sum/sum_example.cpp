#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;


int nListLenght = 20;

void SumExample()
{
	cout << "Sum Example";
	//Populate the list
	list<int> lstInteger;
	for (int i = 1; i < nListLenght; i++)
		lstInteger.push_back(std::rand() % i * 3);

	//Display values
	cout << "List values:" << endl;
	for (auto item : lstInteger)
		cout << item << endl;

	//Get the sum of the values
	int nSum = from(lstInteger)
		>> sum();
	cout << "Sum: " << std::to_string(nSum) << endl;
}

int main()
{
	SumExample();
  do
  {
    cout << '\n' << "Press enter to continue...";
  } while (cin.get() != '\n');
}