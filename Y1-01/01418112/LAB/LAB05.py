import math
'''
Count = 0

while Count <= 10:
    iScore = float(input("Enter student's score: "))
    if iScore >= 0 and iScore <= 100:
        if Count == 0:
            mScore = iScore
            Count = Count + 1
            pass
        elif Count < 10:
            if iScore > mScore:
                mScore = iScore
                Count = Count + 1
        else:
            maxScore = mScore
            break
    else:
        print("Score is out of range.")
        Count = Count
print("Maximum Score: {}".format(maxScore))
'''

'''
i = input()
if float(i) >= 0:
    max = float(i)
    min = float(i)
    Ti = 0
    cnt = 0
    while bool(i):
        if not(bool(i)):
            i = 0
            break
        i = float(i)
        if i > max:
            max = i
        elif i < min:
            min = i
        Ti = Ti + i
        cnt = cnt + 1
        i = input()
    Av = Ti / cnt
    print("{:.2f} {:.2f}\n{:.2f} {:.2f}".format(max, min, Ti, Av))
else:
    pass
'''

'''
i = 1
while i <= 100:
    if i % 2 == 0:
        print(i)
        i = i + 1
    else:
        i = i + 1
'''

'''
n = int(input())
i = 0
while i <= n:
    if i % 3 == 0:
        print(i)
        i = i + 3
    else:
        i = i + 1
'''

'''
n = int(input())
i = 0
c = 0
while i <= n:
    if i % 3 != 0:
        c = c + 1
        i = i + 1
    else:
        i = i + 1
print(c)
'''

'''
n = int(input())
c = 1
Ti = 0
n40 = 0
while c <= n:
    i = float(input())
    c = c + 1
    Ti = Ti + i
    if i > 40:
        n40 = n40 + 1

Av = Ti / n
print("{:.2f} {}".format(Av, n40))
'''

#PB01
'''
p = int(input())
q = p // 10
r = p % 10
if p > 0:
    while q > 0:
        print(r)
        r = q % 10
        q = q // 10
        if q == 0:
            print(r)
            break
else:
    print("ERROR")
'''

#PB02
'''
hours = float(input("Enter number of hours: "))
minutes = float(input("Enter number of minutes: "))
buyAmt = int(input("Enter shopping amount: "))

oM = minutes + hours * 60
oH = (oM // 60) + math.ceil((oM % 60) / 60)
mH = oH

if hours <= 20 and hours >= 0 and minutes <= 59 and minutes >= 0 and mH <= 20:
    Charge = 0
    if buyAmt >= 3001:
        Charge = 0
    elif buyAmt <= 3000 and buyAmt >= 300:
        if mH >= 5:
            Charge = (mH - 4) * 50
        else:
            pass
    else:
        while mH > 0:
            if mH >= 5:
                Charge = (mH - 4) * 50
                mH = mH - (mH - 4)
            elif mH >= 3:
                Charge = Charge + (mH - 2) * 20
                mH = mH - (mH - 2)
            else:
                break
    if Charge == 0:
        print("No charge, thank you.")
    else:
        print("Total amount due is {} Baht, thank you.".format(int(Charge)))
else:
    print("Invalid time.")
'''

#PB03
'''
i = int(input("Enter number: "))
odd = 0
while i >= 0:
    if i % 2 != 0:
        odd = odd + 1
        i = int(input("Enter number: "))
    else:
        i = int(input("Enter number: "))
print("Received {} odd numbers".format(odd))
'''

#PB04
'''
n = int(input())
c = input()
l = 0
if n >= 0:
    while l <= n:
        l = l + 1
        print(c * l)
        if l == n:
            break
else:
    pass
'''

#PB05

n = int(input("Enter height: "))
s = "1"
sp = " "
l = 1
if n == 0:
    pass
else:
    print("{}{}".format(" " * (2 * (n - l)), s))
if n > 0:
    if n == 1:
        pass
    else:
        while l <= n:
            sp = " " * (1 + 2 * (1 + ((l - 1) * 2)))
            l = l + 1
            print("{}1{}1".format(" " * (2 * (n - l)), sp))
            if l == n:
                break
else:
    pass


#PB06
'''
num = int(input())
total = 0
while num > 0:
  d = num % 10
  num = num // 10
  total = d + total
  ans = total % 9
if ans == 0:
  print ("Yes", total)
else:
  print ("No", ans)
'''

a = "Q1JBVkFDQ0lORXwxNzE5OTAwNTY4NjA3fOC4meC4suC4onzguJ7guKjguKfguLHguJV84LiW4Li04LmI4LiZ4LiB4Liy4LiN4LiI4LiZ4LmM4Lin4Lix4LiS4LiZ4LiyfDIwMDExMDMxfDA5Njk2NDA0MDQ="
b = "Q1JBVkFDQ0lORXwzNzEwNjAwMjE0NjAzfOC4meC4suC4onzguKfguLTguIrguLHguKJ84LiW4Li04LmI4LiZ4LiB4Liy4LiN4LiI4LiZ4LmM4Lin4Lix4LiS4LiZ4LiyfDE5NjUwNDA0fDA4MTM1MzQxNDM="
print(a == b, 26 ** 255)