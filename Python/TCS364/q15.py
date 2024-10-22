t1=()
n=int(input("Enter number of elements : "))
for i in range(n):
    t1+=(int(input("Enter element : ")),)
t2=()
c=0
for i in t1:
    c=c+1
    if c%2!=0:
        t2+=(i,)
print("Tuple 1 : ")
print(t1)
print("Tuple 2 : ")
print(t2)