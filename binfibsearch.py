# Function to perform binary search
def binary_search(SE, key):
    """Search for an element using Binary Search."""
    low = 0
    high = len(SE) - 1

    while low <= high:
        mid = (low + high) // 2
        if SE[mid] == key:
            print("Element found at index", mid)
            return  # Exit the function after finding the element
        elif SE[mid] < key:
            low = mid + 1
        else:
            high = mid - 1

    print("Element not found")

# Function to perform Fibonacci search
def fibonacci_search(SE, key):
    """Search for an element using Fibonacci Search."""
    n = len(SE)
    fib_m2 = 0  # (m-2)th Fibonacci number
    fib_m1 = 1  # (m-1)th Fibonacci number
    fib_m = fib_m1 + fib_m2  # mth Fibonacci number

    # Find the smallest Fibonacci number greater than or equal to n
    while fib_m < n:
        fib_m2 = fib_m1
        fib_m1 = fib_m
        fib_m = fib_m1 + fib_m2

    # Marks the offset from the start of the array
    offset = -1

    # While there are elements to be inspected, check for the key
    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)

        if SE[i] < key:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        elif SE[i] > key:
            fib_m = fib_m2
            fib_m1 -= fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            print("Element found at index", i)
            return

    # Check the last element
    if fib_m1 and SE[offset + 1] == key:
        print("Element found at index", offset + 1)
        return

    print("Element not found")

# Main program
SE = []  # List to store roll numbers
n = int(input("\nEnter the number of students who attended the training program: "))
print("Enter the roll numbers of", n, "students (in sorted order):")

# Input roll numbers from the user and ensure they are in sorted order
for i in range(n):
    ele = int(input("Enter roll number: "))
    SE.append(ele)

# Sort the list (if necessary)
SE.sort()

print("\nRoll numbers of students who attended the training program (sorted):", SE)

# Take input from the user for searching
key = int(input("\nEnter the roll number to be searched: "))

# Perform Binary Search
print("\nPerforming Binary Search:")
binary_search(SE, key)

# Perform Fibonacci Search
print("\nPerforming Fibonacci Search:")
fibonacci_search(SE, key)

