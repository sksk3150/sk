FDS=[]
n=int(input("Total number of student:"))
for i in range(0,n):
    a=int(input("Enter marks of student "+str(i+1)+":"))
    FDS.append(a)
print(FDS)

def avg(FDS):
   sum=0
   count=0
   for i in range(len(FDS)):
     if FDS[i]!=-11:
            sum+=FDS[i]
            count=count+1
     avg=sum/count
   return(avg)

def maximum(FDS):
   for i in range(len(FDS)):
        if FDS[i]!=-11:
             Max=FDS[0]
             break
   for i in range(1,len(FDS)):
        if FDS[i]>Max:
             Max=FDS[i]
   return(Max)


def minimum(FDS):
   for i in range(len(FDS)):
        if FDS[i]!=-11:
             Min=FDS[0]
             break
   for i in range(1,len(FDS)):
        if FDS[i]<Min:
             Min=FDS[i]
   return(Min)


def absent_count(FDS):
   count=0
   for i in range(len(FDS)):
        if FDS[i]==-11:
              count=count+1
   return(count)



def max_freq(FDS):
   i=0
   Max=0
   print("Marks|frequency")
   for j in FDS:
        if (FDS.index(j)==i):
              print(j,"|",FDS.count(j))
              if FDS.count(j)>Max:
                  Max=FDS.count(j)
                  mark=j
        i=i+1
   return(mark,Max)

flag=1
while flag==1:
    print("......MENU......")
    print("1.Average marks of the class")
    print("2.Maximum and Minimum marks in class")
    print("3.Number of absent students")
    print("4.Marks with maximum frequency")
    print("5.EXIT")
    ch=int(input("Enter your choice(from 1 to 5):"))

    if ch==1:
        print("Average score of class:",avg(FDS))
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

    elif ch==2:
        print("Highest score in class:",maximum(FDS))
        print("Lowest score in class:",minimum(FDS))
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thanks you.")

    elif ch==3:
        print("Number of students absent in the test:",absent_count(FDS))
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

    elif ch==4:
        mark,fr= max_freq(FDS)
        print("Highest frequency marks are {0}".format(mark,fr))
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

    elif ch==5:
        flag=0
        print("Thank you.")

    else:
        print("Wrong choice.Choose a number from 1 to 5:")
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")
