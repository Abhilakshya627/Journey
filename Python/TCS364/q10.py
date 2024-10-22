i=1
list=[]
while(i):
    print("Do you want to continue :\n1. Yes\t0. No\n")
    i=int(input("Enter answer : "))
    if(i==1):
        n=input("Enter value : ")
        list.append(n)
    elif(i==0):
        break
print(list)