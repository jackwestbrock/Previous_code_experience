#file 1
#if statement lab
#ask the user for 2 numbers
#then ask if they want to add, subtract, multiple, or divide
#perform operation on the 2 numbers, print out the output
user_num1 = int(input(("Please type in a number: ")))
user_num2 = int(input(("Please type in a number: ")))
operation = input(("Which operation would you like: add, subtract, multiply or divide? "))
if operation == 'add' :
    print(user_num1 +user_num2)
elif operation == 'subtract':
    print(user_num1 - user_num2)
elif operation == "multiply" :
    print(user_num1 * user_num2)
elif operation == "divide" :
    print(user_num1 / user_num2)
