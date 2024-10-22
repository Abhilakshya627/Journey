n=int(input("Enter a posetive number : "))
print("Numbers less than ",n," and divisible by both 3 and 5 are : ")
for i in range(n) :
    if(i%3==0 and i%5==0):
        print(i)