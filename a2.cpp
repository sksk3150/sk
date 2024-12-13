#include<iostream>
#include<string>
using namespace std;

class StudData;

class Student{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

    public:
    Student() 
    {
        name="";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/mm/yyyy";
        bloodgroup=new char[2];
    }

    ~Student()
    {
        delete division;
        delete[]bloodgroup;
    }

    static int getCount()
    {
        return count;
    }

   inline void getData(StudData* st)
{
    cout<<"\nEnter Student Name: ";
    getline(cin,name);
    cout<<"Enter Roll Number: ";
    cin>>roll_no;
    cout<<"Enter Class: ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter Division: ";
    cin>>division;
    cout<<"Enter Date of Birth: ";
    cin.get();
    getline(cin,dob);
    cout<<"Enter Blood Group: ";
    cin>>bloodgroup;
    st->getStudData();
    count++;
}
};

int main()
{
    Student* stud1[100];
    StudData* stud2[100];
    int n=0;
    char ch;

    do
    {
        stud1[n]=new Student;
        stud2[n]=new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout<<"\nDo you want to add another student(y/n): ";
        cin>>ch;
        cin.get();
    } while (ch=='y' || ch=='Y');

    for(int i=0;i<n;i++)
    {
        stud1[i]->dispData(stud2[i]);
    }

    cout<<"\nTotal Students: "<<Student::getCount(); 

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
    return 0;
}