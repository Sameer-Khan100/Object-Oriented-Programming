#include<iostream>
#define max 100
using namespace std;
class myString
{
    public:
    char text[max];

    myString()
    {
        //default constructor
    }

    myString(char t[max])
    {
        for(int i=0; t[i]!='\0'; i++)
        {
            text[i]=t[i];
        }
    }

    myString(const myString &s)
    {
        for(int i=0; i<s.text[i]!='\0'; i++)
        {
            text[i]=s.text[i];
        }
    }

    void operator =(char t[max])
    {
        for(int i=0; t[i]!='\0'; i++)
        {
            text[i]=t[i];
        }
    }

    friend ostream & operator << (ostream &out, const myString &s);
    friend istream & operator >> (istream &in,  myString &s);
};
  
ostream & operator << (ostream &out, const myString &s)
{
    out << s.text;
    return out;
}
  
istream & operator >> (istream &in,  myString &s)
{
    cin.ignore();
    in.getline(s.text, max);
    return in;
}

class Date
{
    int day, month, year;
    public:
    Date()
    {
        day=0;
        month=0;
        year=0;
    }

    Date(int d, int m, int y)
    {
        day=d;
        month=m;
        year=y;
    }

    void strToIntDate(char t[max])
    {
        int counter=1;
        for(int i=0; t[i]!='\0'; i++)
        {
            switch (t[i])
            {
            case '-':
                counter++;
                break;
            default:
                    if(int(t[i])<=57 && int(t[i])>=48)
                    {
                        if(counter==1)
                        {
                            day = (day*10) + int(t[i])-'0'; 
                        }
                        else if(counter==2)
                        {
                            month = (month*10) + int(t[i]) - '0';
                        }
                        else 
                        {
                            year = (year*10) +int(t[i]) - '0';
                        }  
                    }
                break;
            }
        }
    }

    void operator =(char t[max])
    {
        strToIntDate(t);
    }

    friend istream & operator >> (istream &in, Date &d);
    friend ostream & operator << (ostream &out, const Date &d);
};

ostream & operator << (ostream &out, const Date &d)
{
    out << d.day << "-" << d.month << "-" << d.year;
    return out;
}
  
istream & operator >> (istream &in,  Date &d)
{
    cout<<"Day: ";
    in>>d.day;
    cout<<"Month: ";
    in>>d.month;
    cout<<"Year: ";
    in>>d.year;
    return in;
}

class Employee
{
    protected:
        myString name;
        Date joiningDate;
        float taxRate;  //e.g: 0.1, 0.08, 0.2

    public:
        Employee()
        {
            name="";
            joiningDate="00-00-0000";
            taxRate=0;
        }

        Employee(myString n, Date jD, float tR)
        {
            name=n;
            joiningDate=jD;
            taxRate=tR;
        }


        ~Employee()
        {
            
        }

        virtual void setName(myString n)
        {
            //implementation will take place in derived classes
        }

        virtual myString getName()
        {
            //implementation will take place in derived classes
        }

        virtual void input()
        {
            //implementation will take place in derived classes
        }

        virtual float calculateSallary()
        {
            //implementation will take place in derived classes
        }

        virtual void display()
        {
            //implementation will take place in derived classes
        }

};

class salariedEmployee: public Employee
{
    float sallary;

    public:
        salariedEmployee()
        {
            sallary=0;
        }

        salariedEmployee(myString n, Date jD, float tR, float s):Employee(n, jD, tR)
        {
            sallary=s;
        }

        ~salariedEmployee()
        {

        }

        void setName(myString n)
        {
            name=n;
        }

        myString getName()
        {
            return name;
        }

        void input()
        {
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Date of Joining..."<<endl;
            cin>>joiningDate;
            cout<<"Enter Tax Rate: ";
            cin>>taxRate;
            cout<<"Enter Gross Sallary: ";
            cin>>sallary;
        }

        float calculateSallary()
        {
            int netSallary=sallary - (sallary*taxRate);
            return netSallary;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Date of Joining: "<<joiningDate<<endl;
            cout<<"Tax Rate: "<<taxRate<<endl;
            cout<<"Gross Sallary: "<<sallary<<endl;
            cout<<"Net Sallary after Tax: "<<calculateSallary()<<endl;
        }

};

class hourlyEmployee: public Employee
{
    int hours;
    int hourlyRate;
    public:
        hourlyEmployee()
        {
            hours=0;
            hourlyRate=0;
        }

        hourlyEmployee(myString n, Date jD, float tR, int h, int hR):Employee(n, jD, tR)
        {
            hours=h;
            hourlyRate=hR;
        }

        ~hourlyEmployee()
        {

        }

        void setName(myString n)
        {
            name=n;
        }

        myString getName()
        {
            return name;
        }

        void input()
        {
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Date of Joining..."<<endl;
            cin>>joiningDate;
            cout<<"Enter Tax Rate: ";
            cin>>taxRate;
            cout<<"Enter Working Hours: ";
            cin>>hours;
            cout<<"Enter Hourly Rate: ";
            cin>>hourlyRate;
        }

        float calculateSallary()
        {
            int netSallary = (hours*hourlyRate) - ((hours*hourlyRate)*taxRate);
            return netSallary;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Date of Joining: "<<joiningDate<<endl;
            cout<<"Tax Rate: "<<taxRate<<endl;
            cout<<"Working Hours: "<<hours<<endl;
            cout<<"Hourly Rate: "<<hourlyRate<<endl;
            cout<<"Gross Sallary: "<<(hours*hourlyRate)<<endl;
            cout<<"Net Sallary after Tax: "<<calculateSallary()<<endl;
        }
};

class commisionedEmployee: public Employee
{
    int sales;
    int commisionRate;
    public:
        commisionedEmployee()
        {
            sales=0;
            commisionRate=0;
        }

        commisionedEmployee(myString n, Date jD, float tR, int s, int cR):Employee(n, jD, tR)
        {
            sales=s;
            commisionRate=cR;
        }

        ~commisionedEmployee()
        {

        }

        void setName(myString n)
        {
            name=n;
        }

        myString getName()
        {
            return name;
        }

        void input()
        {
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Date of Joining..."<<endl;
            cin>>joiningDate;
            cout<<"Enter Tax Rate: ";
            cin>>taxRate;
            cout<<"Enter sales: ";
            cin>>sales;
            cout<<"Enter Commision Rate: ";
            cin>>commisionRate;
        }

        float calculateSallary()
        {
            int netSallary = (sales*commisionRate) - ((sales*commisionRate)*taxRate);
            return netSallary;
        }

        void display()
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Date of Joining: "<<joiningDate<<endl;
            cout<<"Tax Rate: "<<taxRate<<endl;
            cout<<"Total Sales Done: "<<sales<<endl;
            cout<<"Commision Rate: "<<commisionRate<<endl;
            cout<<"Gross Sallary: "<<(sales*commisionRate)<<endl;
            cout<<"Net Sallary after Tax: "<<calculateSallary()<<endl;
        }
};

int main()
{
    Employee *emp[max];
    int choice;
    int NoOfEmp=0;

    for(int i=0; i<max; /*no need to increment here*/)
    {
        //              MENU

        cout<<"Welcome to Payroll Application"<<endl;
        cout<<"1- Salaried Employee"<<endl;
        cout<<"2- Hourly Employee"<<endl;
        cout<<"3- Commisioned Employee"<<endl;
        cout<<"0- Exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;

        //              CHECK
        switch (choice)
        {
        case 1: // Salaried Employee
            emp[i]=new salariedEmployee();
            emp[i]->input();
            emp[i]->calculateSallary();
            i++;
            NoOfEmp++;
            break;

        case 2: // Hourly Employee
            emp[i]=new hourlyEmployee();
            emp[i]->input();
            emp[i]->calculateSallary();
            i++;
            NoOfEmp++;
            break;

        case 3: // Commisioned Employee
            emp[i]=new commisionedEmployee();
            emp[i]->input();
            emp[i]->calculateSallary();
            i++;
            NoOfEmp++;
            break;

        case 0:
            i=max; //this will end the loop and program will exit
            break;

        default:
            cout<<"Invalid input"<<endl;
            break;
        }  
    }


    //                              GENERATING A REPORT
    for(int i=0; i<NoOfEmp; i++)
    {
        cout<<"------------------------------"<<endl;
        cout<<"Employee Number: "<<i+1<<endl;
        emp[i]->display();
        cout<<"------------------------------"<<endl;
        cout<<"\n\n";
    }
    

}
