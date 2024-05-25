#include<iostream>
#include<iomanip>
#include<cmath> 
using namespace std;

class Point
{
	int a,b;
	public:
		Point()
		{
	    	a=0;
            a=b;
		}
		Point(int x,int y)
        {
	     a=x;
	     b=y;
        }
		void set_first_point(int xa)
		{
			a=xa;
		}
		void set_second_point(int xb)
		{
			b=xb;
		}
		int ge_first_point() const;
		int get_sec_point() const;
		~Point()
		{
			
		}
};




class Shape
{
	Point p;
	protected:
		string shapeType;
	public:
	
	Shape()
	{
		shapeType="";
	}
	Shape(string shape)
	{
		shapeType=shape;
	}
	
	float Cal_Area()const
	{
		return 0;
	}
	void draw()const
	{
		cout<<"Shape"<<endl;
	}

	void setShapeType(string shape)
	{
		shapeType=shape;
	}
	string getShapeType() const
	{
		return shapeType;
	}

~Shape(){}

};

class Line:public Shape
{
	Point p1,p2;
public:
	Line():p1(),p2()
	{
		shapeType="line";
	}	
	Line(Point ps,Point pf):p1(ps),p2(pf)
	{
		shapeType="line";
	}
	void draw()const
	{
		cout<<"Line"<<endl;
	}
	float Cal_Area()const
	{
		cout<<"No Area of Line"<<endl;
	}
~Line(){}

};

class Circle:public Shape
{
	float radius;
	float area;
	Point p1;
public:
		
	Circle():p1()
	{
		radius=0.0;
		shapeType="circle";
	}
	Circle(Point center,float r):p1(center)
	{
		radius=r;
		shapeType="circle";
	}

	float Cal_Area()
	{
		area=3.14*pow(radius,2);
		return area;
	}
	void draw()const
	{
		cout<<"Circle"<<endl;
	}

~Circle(){}	
};

class Triangle:public Shape
{
	float base,height;
	float area;
	Line l1,l2;
public:
	Triangle():l1(),l2()
	{
		base=0.0;
		height=0.0;
		shapeType="triangle";
	}
	Triangle(Line lx,Line ly,float b,float h):l1(lx),l2(ly)
	{
		base=b;
		height=h;
		shapeType="triangle";
	}
		

	float Cal_Area()
	{
		area=1/2.0*(base*height);
		return area;
	}
	void draw()const
	{
		cout<<"Triangle"<<endl;
	}
~Triangle() {}
		
};

void drawShapes(Shape *shape[],int size)
{
	
	cout<<setw(25)<<"***SHAPES***"<<endl;
	
	for(int i=0;i<size;i++)
	{
		if(shape[i]->getShapeType()=="line")
		{
			static_cast<Line*>(shape[i])->draw();
		}
		else if(shape[i]->getShapeType()=="circle")
		{
			static_cast<Circle*>(shape[i])->draw();
		}
		else if(shape[i]->getShapeType()=="triangle")
		{
			static_cast<Triangle*>(shape[i])->draw();
		}
		else
		{
			cout<<"Invalid Input."<<endl;
		}
				
	}
	
}
void Calculate_Area(Shape *shape[],int size)
{
	
	cout<<setw(25)<<"***AREA***"<<endl<<endl;
	
	for(int i=0;i<size;i++)
	{
		if(shape[i]->getShapeType()=="line")
		{
			static_cast<Line*>(shape[i])->Cal_Area();
		}
		else if(shape[i]->getShapeType()=="circle")
		{
			cout<<left<<setw(25)<<"Circle: "<<setw(10)<<static_cast<Circle*>(shape[i])->Cal_Area()<<endl;
		}
		else if(shape[i]->getShapeType()=="triangle")
		{
			cout<<left<<setw(25)<<"Traingle: "<<setw(10)<<static_cast<Triangle*>(shape[i])->Cal_Area()<<endl;
		}
		else
		{
			cout<<"Invalid Input."<<endl;
		}
		
	}
	
}
int main()
{
	Shape *obj[4];
	Point p1(5,5),p2(2,4),p3(6,9),p4(44,55);
	obj[0]=new Line(p1,p2);
	obj[1]=new Circle(p2,31.2);
	Line l1(p1,p2),l2(p3,p4);
	obj[2]=new Triangle(l1,l2,45,55.5);
	Point ps(9,9),pf(8,99);
	obj[3]=new Circle(pf,4);
	drawShapes(obj,4);
	Calculate_Area(obj,4);
}
