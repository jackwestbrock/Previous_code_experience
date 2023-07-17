"""Write a program with 3 functions:

RectPerimeter, TriPerimeter, and CirclePerimeter

Each of these functions should ask the user for the sides or radius of the shape and compute the perimeter of it.

In the main body you should ask the user what shape they are computing, then call the appropriate function. 
"""



def rect_perimeter(length, width):
    perimeter = length*2 + width*2
    print(perimeter)

def circ_perimeter(diameter):
    perimeter = 3.14*diameter
    print(perimeter)

def tri_perimeter(side1, side2, side3):
    perimeter = side1 + side2 + side3
    print(perimeter)





##########################
shape = input('What shape are you computing? ')

if shape == 'rectangle':
    length = int(input('What is the length? '))
    width = int(input('What is the width? '))
    rect_perimeter(length, width)

elif shape == 'circle':
    diameter = int(input('What is the diameter? '))
    circ_perimeter(diameter)
elif shape == 'triangle':
    side1 = int(input('What is the first side? '))
    side2 = int(input('What is the second side? '))
    side3 = int(input('What is the third side? '))
    tri_perimeter(side1, side2, side3)
