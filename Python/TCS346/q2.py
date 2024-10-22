def even_or_odd(x):
    if(x%2==0):
        return True
    else:
        return False

n=int(input("Enter number of elements in list : "))
lst=[]
for i in range(n):
    ele=int(input("Enter element : "))
    lst.append(ele)
for i in lst:
    if(even_or_odd(i)):
        print(i,"is even")
    else:
        print(i,"is odd")