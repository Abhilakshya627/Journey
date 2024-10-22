n=int(input("Enter value of n : "))
for i in range(2,n):
    prime=True
    for j in range(2,i//2):
        if(i%j==0):
         prime=False
    if(prime==True):
       print(i)
    