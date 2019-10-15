#include <iostream>
using namespace std;

class complex
{
	int real,img;
public:
	complex()
	{
		real=0;
		img=0;
	}
	complex(int x,int y)
	{
		real=x;
		img=y;
	}
	friend istream& operator >> (istream &,complex &);
	friend ostream& operator << (ostream &,complex &);
	friend complex operator - (complex &,complex &);
	friend complex operator +(complex &,complex &);
	complex operator * (complex &);
	complex operator /(complex &);
};

istream& operator >> (istream &in, complex &c)
{
	cout<<"Complex no. 2:\n"<<"Enter real part:";
	in>>c.real;
	cout<<"Enter imaginary part:";
	in>>c.img;
}
ostream& operator << (ostream &out, complex &c)
{
	out<<c.real<<"+i"<<c.img;
}
complex operator +(complex &m1, complex &m2)
{
	complex z;
	z.real=m1.real+m2.real;
	z.img=m1.img+m2.img;
	return z;
}
complex operator -(complex &m1, complex &m2)
{
	complex z;
	z.real=m1.real-m2.real;
	z.img=m1.img-m2.img;
	return z;
}
complex complex::operator *(complex &c)
{
	complex z;
	z.real=real*c.real-img*c.img;
	z.img=real*c.img+img*c.real;
	return z;
}
complex complex::operator /(complex &c)
{
	complex z;
	z.real=real/c.real;
	z.img=img/c.img;
	return z;

}
int main()
{
	int r,i,ch,a;
	cout<<"Complex no. 1:\n"<<"Enter real part:";
	cin>>r;
	cout<<"Enter imaginary part:";
	cin>>i;
	complex c1(r,i);
	complex c2,c3;
	cin>>c2;
	do
	{
		cout<<"1. Addition\n"<<"2. Subtraction\n"<<"3. Multiplication\n"<<"4. Division\n";
		cin>>ch;

		switch(ch)
		{
			case 1:
				c3=c1+c2;
				cout<<"Addition:";
				cout<<c3;
				break;

			case 2:
				c3=c1-c2;
				cout<<"subtraction:";
				cout<<c3;
				break;

			case 3:
				c3=c1*c2;
				cout<<"Multiplication:";
				cout<<c3;
				break;

			case 4:
				c3=c1/c2;
				cout<<"Division:";
				cout<<c3;
				break;
		}

	}while (a!=5);
}



