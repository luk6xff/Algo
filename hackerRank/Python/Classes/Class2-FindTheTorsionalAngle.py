#https://www.hackerrank.com/challenges/class-2-find-the-torsional-angle
import math

class Point():
    
    def __init__(self,x,y,z):
        self.x=x
        self.y=y
        self.z=z
    
    def __sub__(self, other):
        x= self.x-other.x
        y= self.y-other.y
        z= self.z-other.z
        return Point(x,y,z)
    
    def dot_product(self, other):
        x= self.x*other.x
        y= self.y*other.y
        z= self.z*other.z
        return x+y+z
    
    def cross_product(self,other):
        x = self.y*other.z - self.z*other.y
        y = self.z*other.x - self.x*other.z
        z = self.x*other.y - self.y*other.x
        return Point(x,y,z)
    
    def absolute_value(self):
        return pow((self.x**2+ self.y**2 + self.z**2), 0.5)
    
if __name__ == '__main__':
    
    A= Point(*map(float,input().split()))
    B= Point(*map(float,input().split()))
    C= Point(*map(float,input().split()))
    D= Point(*map(float,input().split()))
    
    #solution
    X= (B-A).cross_product(C-B)
    Y= (C-B).cross_product(D-C)
    phi= math.acos(X.dot_product(Y)/(X.absolute_value()*Y.absolute_value()))
    print("%.2f"%math.degrees(phi))
