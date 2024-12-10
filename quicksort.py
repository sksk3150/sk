arr = []
n = int(input("Total number of students: "))
for i in range(0, n):
    a = int(input("Enter marks of student " + str(i + 1) + ": "))
    arr.append(a)
print("Original array:", arr)

def qsort(arr,low,high):
    if low<high:
        pivot=partition(arr,low,high)
        qsort(arr,low,pivot-1)
        qsort(arr,pivot+1,high)

        
def partition(arr,low,high):
    pivot=arr[low]
    i=low+1
    j=high
    while i<=j:
        while i<=high and arr[i]<=pivot:
            i=i+1
        while i>=low and arr[j]>pivot:
            j=j-1 
        if i<j:
         arr[i],arr[j]=arr[j],arr[i]   
    arr[low],arr[j]=arr[j],arr[low]
    
    return j
    
qsort(arr,0,n-1)
print(arr)