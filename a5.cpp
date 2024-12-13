#include <iostream>
using namespace std;
#define size 30
int n;
template <class T>
void sort(T A[size]){
    int i,j,min;
    T temp;
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nThe Sorted numbers are: ";
    for(i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
cout<<"\n";
}

int main(){
    int A[size];
    float B[size];
    int i,ch;
 do{ 
        cout<<"\n----------MENU-----------";
        cout<<"\n1.Integer Values";
        cout<<"\n2.Float Values";
        cout<<"\n3.Exit";
        cout<<"\nEnter your Choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
               cout<<"\nEnter the number of values to be sorted: ";
               cin>>n;
               cout<<"\nEnter Integer Values: "<<endl;
               for(i=0; i<n; i++){
                   cin>>A[i];
               }
               sort(A);
               break;
            
            case 2:
               cout<<"\nEnter the number of values to be sorted: ";
               cin>>n;
               cout<<"\nEnter Float Values: "<<endl;
               for(i=0; i<n; i++){
                   cin>>B[i];
               }
               sort(B);
               break;
            
            case 3:
               exit(0);
            
            default:
             cout<<"\nInvalid choice!\n";
        }
    }
    while(ch!=3); 
    return 0;
}