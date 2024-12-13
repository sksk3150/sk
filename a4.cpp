#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name;
    int roll_no;

    ofstream outfile;
    outfile.open("data.txt");
    
    cout<<"----Writing to the file----"<<endl;

    cout<<"\nEnter Your name: ";
    getline(cin,name);
    outfile<<name<<endl;

    cout<<"Enter roll no: ";
    cin>>roll_no;
    outfile<<roll_no<<endl;
    cin.ignore();
    
    outfile.close(); 

    ifstream infile;
    infile.open("data.txt");

    cout<<"\n----Reading from the file----"<<endl;

    getline(infile,name); 
    infile>>roll_no; 

    cout<<"\nName: "<<name<<endl;
    cout<<"Roll No: "<<roll_no<<endl;

    infile.close(); 

    return 0;
}