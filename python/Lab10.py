#Evens and odds 

def EvensAndOdds(l):
    print('Evens: \n')
    for i in l:
        if i % 2 == 0:
          print(i)
    print('Odds: \n')
    for i in l:
        if i % 2 == 1:
            print(i)
#Between nums

def BetweenNums(x,y,z):
    print("Numbers inbetween and not divisible")
    for i in range(min(x,y), max(x,y)):
        if i % z != 0:
            print(i)
#Bank

class BankAccount():
    def __init__(self,n):
        self.number = n
        self.balance = 100
        self.fee = 0

    def Check(self, number):
        if number == self.number:
            print('Balance: {}'.format(self.balance))
            print('Fee: {}'.format(self.fee))
        else:
            print("Wrong number")


    
#################################

L = [1,2,3,4,5,6,7,8,9,10]

EvensAndOdds(L)
x =10
y =20
z =4
BetweenNums(x,y,z)

s = BankAccount(12345)

s.Check(12345)
