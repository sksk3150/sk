s = int(input("Enter the number of students:"))
std = []
for i in range (0,s):
	print("Enter marks of student",i+1,":")
	marks= int(input())
	std.append(marks)
print(std)


def ssort(std):
    for i in range (len(std)):
        min_i=i
        for j in range(i+1,len(std)):
            if std[j]<std[min_i]:
                min_i=j
        std[i],std[min_i]=std[min_i],std[i]       
                
    print('The sorted list using selection sort:',std) 
    
    top=std[-5:][::-1]
    print("top five scores are:",top)
    
def bsort(std):
    for i in range(len(std)):
        for j in range(0, len(std) - i - 1):
            if std[j] > std[j + 1]:  # Compare adjacent elements
                # Swap if the current element is greater than the next
                std[j], std[j + 1] = std[j + 1], std[j]
    
    print("Sorted list using bubble sort:", std)

    top=std[-5:][::-1]
    print("top five scores are:",top)


flag=1
while flag==1:
 print("-----MENU-----")
 print("1.Selection sort")
 print("2.Bubble sort")
 print("3. EXIT ")
 ch=int(input("Enter your choice(from 1 to 5):"))
 
 if ch==1:
        ssort(std)
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

 elif ch==2:
        bsort(std)
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")
            
 elif ch==3:
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











