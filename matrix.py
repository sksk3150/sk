def addition():
	result = []

	for i in range (0,r):
		row = []
		for j in range (0,c):
			val = matA[i][j] + matB[i][j]
			row.append(val)
		result.append(row)
		
	print("The matrix after addition is:"+ str(result) )
	

def substraction():
	result = []

	for i in range (0,r):
		row = []
		for j in range (0,c):
			val = matA[i][j] - matB[i][j]
			row.append(val)
		result.append(row)
		
	print("The matrix after substraction is:"+ str(result) )

def transpose():
	result1 = []
	
	for i in range (0,r):
		row = []
		for j in range (0,c):
			val = matA[j][i]
			row.append(val)
		result1.append(row)
	print("Transpose of matrix A is:" + str(result1))

	result2 = []
	
	for i in range (0,r):
		row = []
		for j in range (0,c):
			val = matB[j][i]
			row.append(val)
		result2.append(row)
	print("Transpose of matrix B is:" + str(result2))
	

def multiplication():
    # Initialize the result matrix with zeros
    result = []
    for i in range(r):
        row = []
        for j in range(c):
            row.append(0)
        result.append(row)

    # Perform matrix multiplication
    for i in range(r):
        for j in range(c):
            for k in range(c):
                result[i][j] += matA[i][k] * matB[k][j]

    print("The matrix after multiplication is:", result)

	

matA = []
r = int(input("Enter the number of rows in the matrix:"))
c = int(input("Enter the number of columns in the matrix:"))

for i in range (0,r):
	row = []
	for j in range (0,c):
		val = int(input("Enter the value:"))
		row.append(val)
	matA.append(row)
	
print("The elements of the matrix A are"+ str(matA) )


 
matB = []
r = int(input("Enter the number of rows in the matrix:"))
c = int(input("Enter the number of columns in the matrix:"))

for i in range (0,r):
	row = []
	for j in range (0,c):
		val = int(input("Enter the value:"))
		row.append(val)
	matB.append(row)
	
print("The elements of the matrix B are"+ str(matB) )




flag=1
while flag==1:
 print("-----MENU-----")
 print("1. ADDITION")
 print("2. SUBSTRACTION")
 print("3. TRANSPOSE")
 print("4. MULTIPLICATION")
 print("5. EXIT ")
 ch=int(input("Enter your choice(from 1 to 5):"))
 
 if ch==1:
        addition()
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

 elif ch==2:
        substraction()
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thanks you.")

 elif ch==3:
        transpose()
        a=input("Do you want to continue(yes/no):")
        if a=="yes":
            flag=1
        else:
            flag=0
            print("Thank you.")

 elif ch==4:
        multiplication()
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




