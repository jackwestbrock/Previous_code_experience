#Make 3 classes
#Circle, Triangle, Rectangle classes
#Circle-Radius, Triangle-3 sides, rectangle-2 sides
#A function to compute the area for each class
#Main body, make a circle, rectangle, and triangle manually, print the area

from cmath import pi
import math


class Circle:
    def __init__(self, r):
        self.r = r
    def area(self):
        area = (pi * self.r * self.r)
        print(area)

class Triangle:
    def __init__(self, sa, sb, sc ):
        self.sa = sa
        self.sb = sb
        self.sc = sc
    def area_T(self):
        semi_perimeter = (self.sa +self.sb + self.sc)/2
        area_Tri = math.sqrt(semi_perimeter * (semi_perimeter - self.sa) * (semi_perimeter - self.sb) * (semi_perimeter - self.sc))
        print(area_Tri)
    
class Rectangle:
    def __init__(self, l, w):
        self.l = l
        self.w = w
    def area_R(self):
        area_rect = self.l * self.w
        print(area_rect)
###########################

c = Circle(5)
c.area()
t = Triangle(3,4,5)
t.area_T()
r = Rectangle(5,4)
r.area_R()