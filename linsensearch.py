SE = []
n = int(input("\nEnter number of students in SE COMP: "))
print("Enter the roll numbers of", n, "students:")
for i in range(0, n):
    ele = input()
    SE.append(ele)

print("Roll numbers of students in SE COMP:", SE)

def linear_search(SE, key):
    """Search for an element using Linear Search."""
    for i in range(0, len(SE)):
        if SE[i] == key:
            print("Element found at index", i)
            return  # Exit the function after finding the element
    print("Element not found")
    
def sentinel_search(SE, key):
    """Search for an element using Sentinel Search."""
    n = len(SE)
    last = SE[-1]  # Save the last element
    SE[-1] = key  # Set the last element as the sentinel

    i = 0
    while SE[i] != key:
        i += 1

    SE[-1] = last  # Restore the last element

    # Check if the key was found (either in the original array or as the sentinel)
    if i < n - 1 or SE[-1] == key:
        print("Element found at index", i)
    else:
        print("Element not found")

# Menu-driven program using a flag
flag = 1
while flag == 1:
    print("\n--- Menu ---")
    print("1. Perform Linear Search")
    print("2. Perform Sentinel Search")
    print("3. Exit")

    choice = input("Enter your choice (1-3): ")

    if choice == '1':
        key = input("Enter the element to be searched using Linear Search: ")
        linear_search(SE, key)

    elif choice == '2':
        key = input("Enter the element to be searched using Sentinel Search: ")
        sentinel_search(SE, key)

    elif choice == '3':
        print("Exiting program. Goodbye!")
        flag = 0  # Set flag to 0 to break the loop

    else:
        print("Invalid choice. Please try again.")
