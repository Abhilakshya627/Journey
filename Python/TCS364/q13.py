s=str(input("Enter a String : "))
uc=0
lc=0
for i in s:
    if(i.isupper()):
        uc+=1
    elif(i.islower()):
        lc+=1
print("Upper Case Letters : ",uc)
print("Lower Case Letters : ",lc)