lst=[]
s=0
n=int(input("enter number of elements : "))
for i in range(n):
    num=int(input("Enter element : "))
    lst.append(num)
    s=s+num
print(lst,"\nSum = ",s)