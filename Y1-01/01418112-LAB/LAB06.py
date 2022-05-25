#NestedLoop
'''
x = int(input())
i = 2
while (i <= x):
    j = 1
    while (j <= 12):
        print("%d x %d = %d" % (i, j, i*j))
        j += 1
    print('-' * 16)
    i += 1
'''

#PB01
"""
digits = 4
i1 = int(input("Enter a target (4-digit integer): "))
i2 = int(input("Enter your guess (4-digit integer): "))
posi = 0
digi = 0
car = i2
rnd = 0
cnt = 0
cln = digits
clncnt = 0
chki1 = i1
chki2 = i2

while True:
    chki1 = chki1 // 10
    clncnt += 1
    if chki1 == 0:
        if clncnt == digits:
            clncnt = 0
            while True:
                chki2 = chki2 // 10
                clncnt += 1
                if chki2 == 0:
                    if clncnt == digits:
                        chk = True
                        break
                    else:
                        chk = False
                        break
            break
        else:
            chk = False
            break

if chk:
    if i1 != i2:
        while True:
            rem1 = i1 % 10
            i1 = i1 // 10
            radix = 10 ** cnt
            act1 = rem1 * radix
            while True:
                rem2 = car % 10
                car = car // 10
                radix = 10 ** rnd
                act2 = rem2 * radix
                if act1 == act2:
                    posi += 1
                    break
                elif rem1 == rem2:
                    digi += 1
                    break
                elif car == 0 and rem1 != rem2:
                    break
                rnd += 1
            rnd = 0
            car = i2
            cnt += 1
            if i1 == 0:
                break

        if posi > 1 or posi == 0:
            sposi = "s"
        else:
            sposi = ""
        if digi > 1 or digi == 0:
            sdigi = "s"
        else:
            sdigi = ""

        if posi == 0:
            posi = "No"
        elif posi == 1:
            posi = "One"
        elif posi == 2:
            posi = "Two"
        elif posi == 3:
            posi = "Three"

        if digi == 0:
            digi = "no"
        elif digi == 1:
            digi = "one"
        elif digi == 2:
            digi = "two"
        elif digi == 3:
            digi = "three"

        print("{} position{} correct, {} digit{} correct".format(posi, sposi, digi, sdigi))
    else:
        print("Congratulations, you just mastered my mind!!")
else:
    pass
"""

#ทบทวนก่อนสอบ 1
'''
x = float(input(""))
if (x).is_integer() == True :
    print (int(x),"is an integer.")
else:
    print (x,"is not an integer.")
'''
############################################### ข้อ 5 เด้อข้างล้าง ไม่ผ้านตรงนึง น่าจะเป็นที่ Clean ไม่ครอบคุมพอ
n = (int(input('Enter a number: ')))
x = (int(input('Enter a digit: ')))
if n >= 0 and x >= 0 and x <= 9:
    nc = str(n)
    xc = str(x)     
    found = (nc.count(xc))
    if found == 1:
        time = ""
    else:
        time = "s"
    print("Digit {} occurs {} time{}.".format(x, found, time))
else:
    if n < 0:
        print("Invalid number.")
    if x < 0 or x > 9:
        print("Invalid digit.")

"""
elif n < 0 and x < 0:
    print('Invalid number.')
    print('Invalid digit.')
elif n < 0 and x > 9:
    print('Invalid number.')
    print('Invalid digit.')    
elif n < 0:
    print('Invalid number.')
elif x < 0 or x > 9 :
    print('Invalid digit.')   
"""

#PB02
"""
target = 72
gn = int(input("Enter your guess: "))
gc = 0

if gn == target:
        gc += 1
        print("Congratulations, your guess is correct.")
        print("Total number of guesses is {}.".format(gc))
else:
    while gn != target:
        if gn >= 0 and gn <= 100:
            if gn > target:
                print("Sorry, your guess is too high.")
                gc += 1
            elif gn < target:
                print("Sorry, your guess is too low.")
                gc += 1
        else:
            print("Sorry, your guess is out of range.")
            gc += 1
        gn = int(input("Enter your guess: "))
        if gn == target:
            gc += 1
            print("Congratulations, your guess is correct.")
            print("Total number of guesses is {}.".format(gc))
"""

#PB03
"""
number1 = int(input("Enter the first number: "))
number2 = int(input("Enter the second number: "))
tt = 0
th = 0

if number1 > 0 and number2 > 0:
    if (number1 - number2) > 0:
        tt = number1
        th = number2
    elif (number1 - number2) < 0:
        tt = number2
        th = number1
    else:
        tt = number1
        th = number2
    while True:
        rem = tt % th
        tt = th
        th = rem
        if th == 0:
            break
    pk = number1 * number2
    lcm = pk / tt
    print("  >> gcd({}, {}) = {:6d}\n  >> lcm({}, {}) = {:6d}".format(number1, number2, int(tt), number1, number2, int(lcm)))
else:
    pass
"""

#PB04
"""
frame = 1
pins = int(input("Frame # 1\n  Number of pins down: "))
score = 0
framernd = 2

while frame <= 10:
    if pins >= 0 and pins <= 10:
        if framernd != 2 and pins > rest:
            pass
        else:
            if pins == 10:
                score += 10
                if frame == 10:
                    break
                frame += 1
                framernd = 2
            elif pins < 10 and framernd != 0:
                score += pins
                framernd -= 1
            if framernd == 0:
                if frame == 10:
                    break
                else:
                    frame += 1
                    framernd = 2
            if framernd != 2:
                rest = 10 - pins
                rnge = " (0-{})".format(rest)
            else:
                rnge = ""
        pins = int(input("Frame # {}\n  Number of pins down{}: ".format(frame, rnge)))
    else:
        pass
print("Total score is {}".format(score))
"""

#PB04
"""
ih = float(input())
car = 0
her = 0
bld = 0

while ih != -1:
    if ih == -1:
        break
    elif ih < car:
        pass
    elif ih > her:
        bld += 1
    if ih > her:
        her = ih
    car = ih
    ih = float(input())
print(int(bld))
"""

#PB06
"""
number = int(input())
digchkcnt = 0
rem = 0
total = 0

while True:
    rem = number % 10
    number = number // 10
    total += rem
    if number == 0:
        if total // 10 == 0:
            break
        elif total <= 9:
            break
        elif total > 9:
            number = total
            total = 0
            rem = 0
print(total)
"""