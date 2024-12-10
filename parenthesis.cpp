
#include<iostream>
using namespace std;
#define MAX 10

class Stack
{
	
	int top = -1;
	char arr[MAX];
	
	public:
	
	void push(char val)
	{
		if(top == MAX-1)
		{
			cout << "Stack Overflow - Element can't be inserted "<<endl;
		}
		else
		{
			top++;
			arr[top] = val;
		}
	}
	
	void pop()
	{
		if(top == -1)
		{
			cout << "Stack underflow - Element can't be deleted "<< endl;
		}
		
		else
		{
		
			top--;
		}
	}
	
	void display()
	{
		cout<<"Array is : "<<endl;
		for(int i=0;i<=top;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	
	int peek()
	{
		if(top != -1)
		{
			return arr[top];
		}
		return '\0';
	}
	
	bool isEmpty()
	{
		if(top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isMatching(char a,char b)
	{
		if(a == '(' && b == ')') 
			return true;
		else if(a == '{' && b == '}')
			return true;
		else if(a == '[' && b == ']')
			return true;
		return false;
	}
	

};

int main()
{
	Stack s1;
	string exp;
	cout << "Enter expression : ";
	cin>>exp;
	
	int flag = 0;
	
		
	for(int i=0; exp[i] != '\0'; i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
		{
			s1.push(exp[i]);
				
		}	
		
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			
		    if(s1.isMatching(s1.peek(),exp[i]))
			{
				s1.pop();
			}
			else
			{
				flag = 1;
			}
		}			
	}
	if(flag == 1 || !s1.isEmpty())
	{
		cout << "Invalid Parenthesis " << endl;
	}
	
	else if(s1.isEmpty())
	{
		cout << "Valid Parenthesis"<<endl;
	}
	
	
	return 0;

	
}