s=input("Enter a string : ")
frq=0
for i in s:
    c=0
    for j in s:
        if i==j:
            c+=1
    print("Frequency of ",i," is : ",c)