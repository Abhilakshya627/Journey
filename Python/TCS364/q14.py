def find_min(lst):
    a = lst[0]
    for i in lst:
        if a > i:
            a = i
    return a

def find_max(lst):
    a = lst[0]
    for i in lst:
        if a < i:
            a = i
    return a

elements = []
n = int(input("Enter number of list elements: "))
for i in range(n):
    c = int(input(f"Enter element {i + 1}: "))  
    elements.append(c)

print("The list is:")
for i in elements:
    print(i)

print("Maximum =", find_max(elements), "Minimum =", find_min(elements))