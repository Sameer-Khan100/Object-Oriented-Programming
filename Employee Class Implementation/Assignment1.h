 
#include<iostream>
#include<string.h>

using namespace std;
class Employee
{
	private:
		const int empN;
		char *n;
		int s;
		char* d;
		
	public:
    	static int EmpO;
	  	Employee();
	  	Employee(int ,char* ,int ,char*);
	  	Employee(const Employee &obj);
	  	~Employee();

	  	Employee &setName(char* a);
	  	Employee &setSallary(int s);
	  	Employee &setDes(char* des);
	  	int getEmpN() const;
	  	char* getName() const;
	  	int getSalary() const;
	  	char* getDes() const;
	  	void display();
};

//Default Constructor
Employee::Employee():empN(EmpO){
	EmpO++;
	n=new char[50];
	strcpy(n,"NULL");
	s=0;
	d=new char[50];
	strcpy(d,"NULL");
}

//Parameteized Constructor
Employee::Employee(int En,char* N,int S,char* D):empN(En){
	EmpO++;
	n=new char[strlen(N)+1];
	strcpy(n,N);
	s=S;
	d=new char[strlen(D)+1];
	strcpy(d,D);
}
//Copy Constructor
Employee::Employee(const Employee &obj):empN(obj.empN){
	EmpO++;
	n=new char[strlen(obj.n)+1];
	strcpy(n,obj.n);
	s=obj.s;
	d=new char[strlen(obj.d)+1];
	strcpy(d,obj.d);
}
//Destructor
Employee::~Employee()
{
	cout<<"Destructor called!!!"<<endl;
}
//Setters
Employee &Employee::setName(char* a){
    strcpy(n,a);
    return *this;
}
Employee &Employee::setSallary(int S){
	s=S;
	return *this;
}
Employee &Employee::setDes(char* des){
    strcpy(d,des);
    return *this;
}

//Getters
int Employee::getEmpN() const{
	return empN;
}
char* Employee::getName() const{
    return n;
}
int Employee::getSalary() const{
    return s;
}
char* Employee::getDes() const{
    return d;
}

void Employee::display(){
	cout<<"Employee Number: "<<empN<<endl;
	cout<<"Name: "<<n<<endl;	
	cout<<"Designation: "<<d<<endl;
	cout<<"Salary: "<<s<<endl;
}
int Employee::EmpO=0;

