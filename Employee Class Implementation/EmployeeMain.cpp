#include "Assignment1.h"
int main()
{
	//first object for class Employee
	//Defaault Constructor called
	Employee emp1;
	emp1.display();
	cout<<"---------------------------------------";
	
	//Second object for class Employee
	//Using cascading
	cout<<endl;
	Employee emp2;
	emp2.setName("Nazeer").setSallary(80000).setDes("Doctor");
	emp2.display();
	cout<<"----------------------------------------";
	
	//Third object for class Employee

	Employee emp3(54,"Bashir",150000,"Professor"); //parametrized constructor called
	cout<<endl;
	emp3.display();
	cout<<"---------------------------------------";
	
	//Fourth object for class Employee which is a copy of Third object
	cout<<endl;
	Employee emp4=emp3;
	emp4.display();
	cout<<"---------------------------------------";
	
	//finally displaying total number of objects
	cout<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"Total number of objects(Employees): "<<Employee::EmpO<<endl;
	cout<<"*****************************************"<<endl;
	system("pause");
	
	
}

