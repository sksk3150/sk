#include <iostream>
using namespace std;

class Complex{
	float r,i;
public:
	Complex(){
		r=0;
		i=0;
	}
	Complex(float real,float imag){
		r=real;
		i=imag;
	}

	Complex operator+(Complex);
	Complex operator*(Complex);
	friend istream &operator>>(istream &input,Complex &c);
	friend ostream &operator<<(ostream &output,Complex &c);
};

Complex Complex::operator+(Complex c){
	Complex temp;
	temp.r=temp.r+c.r;
	temp.i=temp.i+c.i;
	return temp;
}

Complex Complex::operator*(Complex c){
	Complex temp;
	temp.r=(r*c.r)-(i*c.i);
	temp.i=(i*c.r)+(r*c.i);
	return temp;
}

istream &operator>>(istream &input,Complex &a){
	cout<<"Enter real part:";
	cin>>a.r;
	cout<<"Enter imaginary part:";
	cin>>a.i;
	return cin;
}

ostream &operator<<(ostream &output,Complex &a){
	cout<<a.r<<"+i"<<a.i;
	return cout;
}

int main(){
	Complex c1, c2, c3, c4;
	cout<<"\nDefault constructor value:"<<c1<<endl;
	cout<<"\nEnter the first number"<<endl;
	cin>>c1;
	cout<<"\nEnter the second number"<<endl;
	cin>>c2;
	cout<<"\nThe first number is "<<c1<<endl;
    cout<<"The second number is "<<c2<<endl;
	c3=c1+c2;
	c4=c1*c2;
	cout<<"\nThe addition is "<<c3<<endl;
	cout<<"The multiplication is "<<c4<<endl;
 return 0;	
} 