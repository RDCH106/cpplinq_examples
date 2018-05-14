#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "cpplinq.hpp"

using namespace std;
using namespace cpplinq;


class Student
{
public:
  Student(std::string Name, int ID, int Age)
  {
    m_name = Name;
    m_id = ID;
    m_age = Age;
  }
  std::string GetName() { return m_name; }
  int GetID() { return m_id; }
  int GetAge() { return m_age; }
private:
  int m_id;
  std::string m_name;
  int m_age;
};

void SelectExample()
{
  //This example get a sub collection  order by Age where Age is in range
  int nMinAge = 18;
  int nMaxAge = 60;

  cout << "Select Example";
  //Populate the list
  list<Student> lstStudents;
  int nGenerateID = 0;
  lstStudents.push_back(Student("Jorge Turrado", nGenerateID++, 26));
  lstStudents.push_back(Student("David Abad", nGenerateID++, 56));
  lstStudents.push_back(Student("Andres Garcia", nGenerateID++, 18));
  lstStudents.push_back(Student("Markel Morkuende", nGenerateID++, 45));
  lstStudents.push_back(Student("Pedro Amurrio", nGenerateID++, 33));

  //Display values
  cout << "List values:" << endl;
  for (auto item : lstStudents)
    cout << "Name: " << item.GetName() << " Age: " << item.GetAge() << " ID: " << item.GetID() << endl;

  //From
  auto lstSubList = from(lstStudents)
    //Where condition
    >> where([nMinAge, nMaxAge](Student g) {	return g.GetAge() > nMinAge && g.GetAge() < nMaxAge; })
    //What select
    >> select([](Student g) { return g; })
    //Order rule
    >> orderby_ascending([](Student g) {return g.GetAge(); })
    //Output
    >> to_list();

  cout << "Selected values:" << endl;
  for (auto item : lstSubList)
    cout << "Name: " << item.GetName() << " Age: " << item.GetAge() << " ID: " << item.GetID() << endl;
}

int main()
{
  SelectExample();
  do
  {
    cout << '\n' << "Press enter to continue...";
  } while (cin.get() != '\n');
}