#PB01
"""
n = int(input("Enter a number: "))
i = 65
I = ""

if n > 0 and n <= 26:
    for i in range(i, i + n):
        list(range(i, i + n))
        I = I + chr(i)
        print(I)
else:
    print("Invalid input, program terminates.")
"""

"""
n = int(input("Enter a number: "))
count = 1
if n > 0 and n <= 26:
    while count<=n:
        i = 0
        I = 0
        while i<count:
            print(chr(ord('A') + I), end='')
            i += 1k
            I += 1
        print()
        count += 1
else:
    print("Invalid input, program terminates.")
"""

#PB02
"""
n = int(input("Enter a number: "))
i = 65
I = ""

if n > 0 and n <= 26:
    while True:
        for i in range(i, i + n):
            list(range(i, i + n))
            I = I + chr(i)
            if len(I) == n:
                print(I)
                I = ""
                break
        i = 65
        n -= 1
        if n == 0:
            break
else:
    print("Invalid input, program terminates.")
"""

'''
n = int(input("Enter a number: "))
count = 1
if n > 0 and n <= 26:
    while count<=n:
        i = n
        I = 0
        while i>=count:
            print(chr(ord('A') + I), end='')
            i -= 1
            I += 1
        print()
        count += 1
else:
    print("Invalid input, program terminates.")
    '''

#PB03

'''
n = int(input("Enter a number: "))
count = 1
if n > 0 and n <= 26:
    while count<=n:
        i = 0
        I = 0
        while i<count:
            print(chr(ord('A') + I), end='')
            i += 1
            I += 1     
        print()
        count += 1
    count = 1
    n -= 1
    while count<=n:
        i = n
        I = 0
        while i>=count:
            print(chr(ord('A') + I), end='')
            i -= 1
            I += 1
        print()
        count += 1    
else:
    print("Invalid input, program terminates.")
'''
"""
n = int(input("Enter a number: "))
i = 65
I = ""

if n > 0 and n <= 26:
    for i in range(i, i + n):
        list(range(i, i + n))
        I = I + chr(i)
        print(I)
    n -= 1
    if len(I) == n:
        while True:
            for i in range(i, i + n):
                list(range(i, i + n))
                I = I + chr(i)
                if len(I) == n:
                    print(I)
                    I = ""
                    break
            i = 65
            n -= 1
            if n == 0:
                break
else:
    print("Invalid input, program terminates.")
"""

#PB04
"""
a = int(input("Enter a number: "))
result = 1
i = 1
S = -1
nMiddle = 0

if a == 0:
    pass
else:
    print("0! = 1 = 1")
    while S <= a:
        S = 0
        xMax = list(range(1, a + 1))
        index = ""
        print(xMax)
        S = S + 1
        pmid = 
        mid = "{} x ".format(S) + "1"
        output = "{}! = {} = {}".format(S, mid, result)
        print(output)
        if S == a:
            break
if a == 0:
    print("0! = 1 = 1")
"""
#2 โดยคุณตี้
""" 
x = int(input("Enter a number: ")) 
if x < 0 :
  print("Invalid input, program terminates.")
else :
  c = 0
  while c <= x :
     total = 1
     d = c
     y = ''
     if c == 0 :
        print("0! = 1 = 1")
     else :
        while d >= 1 :
          if d == 1 :
            y = y + '1'  
          else :
            y += str(d) + " x "
            total *= d  
          d -= 1
        print("{}! = {} = {}".format(c,y,total))
     c += 1

"""

"""
while(i <= a):
    result = i*result
    print((result))
    i = i+1
"""

#PB05
"""
number = int(input("Enter a number: "))
div = 2
pref = ""

while number != 0:
    if number > 1:
        if number == 2:
            print("{} is a prime number.".format(number))
        else:
            while True:
                rem = number % div
                if rem == 0:
                    pref = "not "
                    break
                div += 1
                if div == number:
                    break
            print("{} is {}a prime number.".format(number, pref))
    else:
        print("Invalid input, try again.")
    number = int(input("Enter a number: "))
    div = 2
    pref = ""
if number == 0:
    print("End of program, goodbye.")
"""

#PB06
"""
ih = int(input("Enter height: "))
iw = int(input("Enter width: "))
line = 0
s = 0

if ih > 0 and iw > 0:
    while line <= ih:
        #print("while1")
        line += 1
        OorE = line % 2
        if OorE != 0:
            while s <= iw:
                #print("while2")
                print('* ',end='')
                s += 1
                if s == iw:
                    break
        else:
            while s <= iw:
                #print("while3")
                print(' *',end='')
                s += 1
                if s == iw:
                    break
        print()
        s = 0
        if line == ih:
            break
else:
    print("Invalid input, program terminates.")
"""

#PB07
"""
number = int(input("Enter positive integer: "))
prime = 2

if number >= 1:
    while number > 1:
        while True:
            rem = number % prime
            if rem == 0:
                print(prime)
                number = number / prime
                prime = 2
                break
            prime += 1
    prime = 2
else:
    print("Invalid number.")
"""

#PB08
'''
import math
number = int(input())
angle = 1
carry = 1
cnt = 0
a = 0
b = 0
c = number

if number >= 1:
    while a < c:
        a += 1
        while b < c:
            b += 1
            if c == math.sqrt((a ** 2) + (b ** 2)):
                cnt += 1
                break
            elif a == b:
                break
        b = 0
        if a == c:
            break
    print(cnt)
else:
    pass
'''