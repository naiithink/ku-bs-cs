import math
#hello
#note
#NOTE

#note: print(bool('False')) -> True //non empty string

#print(4 => 3)

#a = 17
#print(a % 3 == a % 5)

#import math
#x = int(input())
#b = math.pow(x, 2)-6*x+9
#print(b == 0)

#and, or ,not //4 Boolean type

#print(2 + 3 == 5 and bool(0))

#ch = input()
#print(ch == 'a' or ch == 'b' or ch == 'c')

#EX04
'''
C = float(input())
U = input()
if U == 'F' or U == 'f':
    print(9 * C / 5 + 32)
elif U == 'K' or U == 'k':
    print(C + 273.15)
else:
    print('ERROR')
'''

#PB01
'''
W = float(input('Weight (kg): '))
H = float(input('Height (m): '))
BMI = W * H ** -2
print('BMI is {:.1f}'.format(BMI))
if BMI < 18.5:
    print('Underweight')
elif BMI < 25:
    print('Normal weight')
elif BMI < 30:
    print('Overweight')
else:
    print('Obesity')
'''

#PB02
'''
Amt = float(input('Enter buying amount: '))
if Amt >= 1000:
    if Amt < 3000:
        tAmt = Amt * 0.9
    else:
        tAmt = Amt * 0.85
else:
    tAmt = Amt
print ('Amount due after discount is {:.2f} baht.'.format(tAmt))
'''

#PB03
'''
H = float(input('Enter number of hours: '))
M = float(input('Enter number of minutes: '))
if H >= 0 and M >= 0 and M != 60:
    H2M = H * 60
    Tme = H2M + M
    if Tme <= 15:
        totalCharge = 'No charge, thanks.'
        print(totalCharge)
    elif Tme <= 120:
        totalCharge = 10
        print('Total amount due is', int(totalCharge), 'Bahts.')
    else:
        Charge4_2 = 10
        rate_from3 = 10
        RmnTme = Tme - 120
        RmnTme_H = RmnTme // 60
        Charge_H = RmnTme_H * rate_from3
        if RmnTme % 60 > 0:
            Charge_M = 10
            totalCharge = Charge4_2 + Charge_H + Charge_M
        else:
            totalCharge = Charge4_2 + Charge_H
        print('Total amount due is', int(totalCharge), 'Bahts.')
else:
    print('Input Error!')
'''

#PB04
'''
tPrice = float(input('Total Price: '))
if tPrice >= 50:
    n = tPrice // 50
else:
    n = 0
print('You got:', int(n))
'''

#PB05
'''
target = 72
i = int(input('Enter your guess (0 - 100): '))
a = 'Congratulations'
b = 'Sorry'
m = ' your guess is'
z = ', try again later'
if i >= 0 and i <= 100:
    if i == target:
        pre = a
        fix = m
        log = 'correct'
        suf = ''
    else:
        pre = b
        fix = m
        log = 'wrong'
        suf = z
else:
    pre = b
    fix = ''
    log = 'out of range'
    suf = z
print('{},{} {}{}.'.format(pre, fix, log, suf))
'''

#PB06
'''
ADMIN_USERNAME = 'admin'
ADMIN_PASSWORD = 'Ad31n15Tr@t012'
U = input('Username: ')
P = input('Password: ')
if U == ADMIN_USERNAME and P == ADMIN_PASSWORD:
    print('Welcome, admin.')
else:
    print('You are not admin.')
'''

#PB07
'''
x = float(input('Enter x : '))
if x <= 99:
    if x > 0:
        y = 3 * x ** 2 - (1 - x) ** 2
    elif x == 0:
        y = x
    else:
        y = ((x ** 2) + 1) ** 0.5
else:
    y = 2 * x ** 3 - x * (x + 1) ** -0.5
print('f({:.2f}) = {}'.format(x, math.ceil(y)))
'''

#ROB01
'''
hour = int(input('Enter number of hours: '))
mins = int(input('Enter number of minutes: '))
if hour < 0 or mins < 0 or mins >= 60:
    print('Input Error!')
else:
    raw = math.ceil(mins / 60)
    price = 10
    if hour == 0 and mins <= 15:
        print('No charge, thanks.')
    elif hour == 0 and mins <= 60:
        print('Total amount due is {} Bahts.'.format(price))
    elif hour >= 1 and hour <= 2 and mins == 0:
        print('Total amount due is {} Bahts.'.format(price))
    elif hour >= 1 and hour <= 2 and mins > 0:
        print('Total amount due is {} Bahts.'.format(price * 2))
    else:
        if hour > 2 and hour >= 3 and mins == 0:
            print('Total amount due is {} Bahts.'.format(price + (hour - 2) * 10))
        elif hour > 2 and hour >= 3 and mins > 0:
            print('Total amount due is {} Bahts.'.format(price + ((hour - 2) + raw) * 10))
        else:
            print('No charge, thanks.')
'''