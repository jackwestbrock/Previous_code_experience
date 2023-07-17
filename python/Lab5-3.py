#file 3
#ask the user for a number
#do not let them type in a number outside of the range of 1 to 10
# set up a list, ask the user for numbers equal to the amount they typed in 
#put those in the list, print the list

user_num = int(input("Please input a number ranged 1-10: "))
while user_num > 10 :
    user_num = int(input("Input a number in the range please : "))

array = []
for i in range(0,user_num) :
    array.append(int(input("Please enter a number ")))

print(array)

