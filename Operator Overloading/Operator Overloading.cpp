#include<iostream>
#include <cstdlib>
using namespace std;

//array class
class Array
{   
	const int size;
	int * ptr;
	int local_average;
	static int global_count;
	static int global_size;
	static int global_average;
						
	public:
		Array():size(100)
		{
			
		}
		
		Array(int a):size(a=a<0?1:a)
		{
			ptr = new int[size];
			global_count++;
			global_size+=size;
			local_average=0;	
		}
		
		Array(int a, bool flag):size(a=a<0?1:a)
		{
			ptr = new int[size];	
		}
		
		//average calculation
		void average()
		{
			int sum=0;
			for(int i=0; i<size; i++)
			{
				sum+=ptr[i];
			}
			
			local_average=(int)sum/size;
			global_average+=local_average;
			cout<<"Local Average: "<<local_average<<endl;
			cout<<"Global Average: "<<global_average<<endl;
		}                    
		
		//Streams
		//insertion stream
		friend ostream & operator << (ostream &out, const Array &obj)
		{
			out<<"Integers: ";
			for(int i=0; i<obj.size; i++)
			{
				out<<obj.ptr[i]<<"   ";		
			}
			return out;
		} 
		//extraction stream          
		friend istream & operator >> (istream &in, const Array &obj)
		{
			for(int i=0; i<obj.size; i++)
			{
				cout<<"integer "<<i+1<<": ";
				in>>obj.ptr[i];
			}	
			return in;
		}
		
		//+ and - operators overloading
		void operator + (Array &obj)
		{
			if(obj.size!=size)
			{
				 cout<<"Array Size Mis-matched"<<endl;
				 return;
			}
			  
			for(int i=0; i<obj.size; i++)
			{
				cout<<ptr[i]+obj.ptr[i]<<"   "; 	
			}
			
			cout<<endl;
		}
		
		void operator - (Array &obj)
		{
			if(obj.size!=size)
			{
				 cout<<"Array Size Mis-matched"<<endl;
				 return;
			}
			  
			for(int i=0; i<obj.size; i++)
			{
				cout<<ptr[i]-obj.ptr[i]<<"   "; 	
			}
			
			cout<<endl;
		}
		
		//subscript [] operator overloading
		 int &operator [] (int index)
		 {
		 	return ptr[index];
		 }
		
		//function operator () overloading
		Array &operator () (const int a, const int b)
		{
			Array temp((b-a) +1, false);
			
			for(int i=0, j= a; i<=b-a; i++,j++)
			{
				 temp.ptr[i]=ptr[j];
				 
			}
			
			return temp;
		}
		
		//increment and decrement
		void operator ++ ()
		{
			for(int i=0; i<size; i++)
			{
				ptr[i]++;
			}
		}
		void operator -- ()
		{
			for(int i=0; i<size; i++)
			{
				ptr[i]--;
			}
		}
};

//initialization of static variables
int Array::global_count=0;
int Array::global_size=0;
int Array::global_average=0;

int main()
{
	int n;
	cout<<"How many instances you want to create? : ";
	cin>>n;
	Array** arptr;
	arptr=(Array**)malloc(n*sizeof(Array*));
	int arsize;
	for(int i=0; i<n; i++)
	{
		cout<<"Enter the size of Array#"<<i+1<<" : ";
		cin>>arsize;
		arptr[i]=new Array(arsize);
		cout<<"Input of object "<<i+1<<endl;
		cin>>*arptr[i];
		arptr[i]->average();
		cout<<endl;
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<"\nObject "<<i+1<<": "<<endl;
		cout<<*arptr[i]<<endl;
	}

	//addition and subtraction
	cout<<endl<<"Addition and substraction"<<endl;
	cout<<"Addition: ";
	*arptr[0]+*arptr[1];
	cout<<"\nSubstraction: ";
	*arptr[0]-*arptr[1];
	
	//substring 
	cout<<endl<<endl<<"Value at first index: "<<(*arptr[0])[1]<<endl<<endl;

	cout<<"Enter value for 3rd element : ";
	cin>>(*arptr[0])[2];
	cout<<*arptr[0]<<endl;
	cout<<"range from index 0 to 2 "<<(*arptr[0])(0,2)<<endl;
	
	//increment decrement
	cout<<endl<<endl;
	cout<<*arptr[0]<<endl;
	++(*arptr[0]);
	cout<<"after increment: "<<*arptr[0]<<endl;
	--(*arptr[0]);
	--(*arptr[0]);
	cout<<"after decrement: "<<*arptr[0]<<endl;
	
	return 0;
}
