def duplicate(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst
    
SE=[]
a=int(input("enter number of students in SE:"))
for i in range(0,a):
    s=input("Enter student name:")
    SE.append(s)
print("Students in SE are:",SE)    
    
C=[]
a=int(input("enter number of students in c:"))
print("Enter student name:")
for i in range(0,a):
    s=input()
    C.append(s)   
C=duplicate(C)    
print("Students palying cricket:",C)

B=[]
a=int(input("enter number of students in B:"))
for i in range(0,a):
    s=input("Enter student name:")
    B.append(s)   
B=duplicate(B)    
print("Students palying cricket:",B)


F=[]
a=int(input("enter number of students in F:"))
for i in range(0,a):
    s=input("Enter student name:")
    F.append(s)   
F=duplicate(F)    
print("Students palying cricket:",F)


def diff(lst1,lst2):
 lst3=[]
 for i in lst1:
    if i not in lst2:
        lst3.append(i)
 return lst3
    
    
def union(lst1,lst2):
 lst3=lst1.copy()
 for i in lst2:
    if i not in lst3:
        lst3.append(i)
 return lst3    


def inter(lst1,lst2):
 lst3=[]
 for i in lst1:
    if i in lst2:
        lst3.append(i)
 return lst3

def symmdiff(lst1,lst2):
 lst3=[]
 D1=diff(lst1,lst2)
 print("Differnece between criclet and badminton:",D1)
 D2=diff(lst2,lst1)
 print("Differnece between badminton and cricket:",D2)
 lst3=union(D1,D2)
 return lst3


flag=1
while flag==1:
    print("\n\n--------------------MENU--------------------\n")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. List of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit\n")
    ch=int(input("Enter your Choice (from 1 to 5) :"))

    if ch==1:
        print("List of students who play both cricket and badminton : ",inter(C,B))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

    elif ch==2:
        print("\nList of students who play either cricket or badminton but not both is : ",symmdiff(C, B))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

    elif ch==3:
        print("\n\nList of students who play neither cricket nor badminton is :",diff(SE,union(B,C)))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

    elif ch==4:
        print("Number of students who play cricket and football but not badminton : ",diff(B,inter(C,F)))
        a = input("\n\nDo you want to continue (yes/no) :")
        if a == "yes":
            flag = 1
        else:
            flag = 0
            print("Thanks for using this program!")

    elif ch==5:
        flag=0
        print("Thanks for using this program!")

    else:
        print("!!Wrong Choice!! ")
        a=input("\n\nDo you want to continue (yes/no) :")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thanks for using this program!")
			
			
			
			
