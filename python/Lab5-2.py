#File2
#for loop lab
#ask the user for a number
#print a triangle using the * symbol
#if the user types in 3, the program should printout
#*
#**
#**
user_num = int(input("Please input a number: "))
triangle = ""
for i in range(user_num):
    triangle += "*"
    print(triangle)

