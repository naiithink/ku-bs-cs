#PB01: Guessing 2
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
        if i > target:
            pre = b
            fix = m
            log = 'too high'
            suf = z
        else:
            pre = b
            fix = m
            log = 'too low'
            suf = z
else:
    pre = b
    fix = ''
    log = 'out of range'
    suf = z
print('{},{} {}{}.'.format(pre, fix, log, suf))
'''

#PB02: Menu
'''
inv = 'Invalid '
mm = 'Main Menu '
sm = 'Sub Menu '
op = '---<< '
cl = '>>--- '
et = 'Enter your choice: '
ml = 'Meal '
b  = 'urger '
br = 'egular ''B'+b
bc = 'heese ''B'+b
bd = 'ouble Cheese ''B'+b
c  = 'hicken '
cf = 'ried ''C'+c
cg = 'rilled ''C'+c
cc = 'hef\'s ''C'+c
p  = 'asta '
ps = 'paghetti de Italiano '
pl = 'asagna Supreme '
pm = 'acaroni Special '

i1 = input('{}\n{}\n{}\n{}\n{}'.format(op+mm+cl, '    <B>'+b+ml, '    <C>'+c+ml, '    <P>'+p+ml, et))
if i1 == 'B' or i1 == 'b':
    i2 = input('{}\n{}\n{}\n{}\n{}'.format(op+'B'+b+sm+cl, '    <R>'+br, '    <C>'+bc, '    <D>'+bd, et))
    er = ''
    if i2 == 'R' or i2 == 'r':
        ch = 'R'+br
        o = 60
    elif i2 == 'C' or i2 == 'c':
        ch = 'C'+bc
        o = 75
    elif i2 == 'D' or i2 == 'd':
        ch = 'D'+bd
        o = 90
    else:
        er = 'sub '
elif i1 == 'C' or i1 == 'c':
    i2 = input('{}\n{}\n{}\n{}\n{}'.format(op+'C'+c+sm+cl, '    <F>'+cf, '    <G>'+cg, '    <C>'+cc, et))
    er = ''
    if i2 == 'F' or i2 == 'f':
        ch = 'F'+cf
        o = 120
    elif i2 == 'G' or i2 == 'g':
        ch = 'G'+cg
        o = 150
    elif i2 == 'C' or i2 == 'c':
        ch = 'C'+cc
        o = 180
    else:
        er = 'sub '
elif i1 == 'P' or i1 == 'p':
    i2 = input('{}\n{}\n{}\n{}\n{}'.format(op+'P'+p+sm+cl, '    <S>'+ps, '    <L>'+pl, '    <M>'+pm, et))
    er = ''
    if i2 == 'S' or i2 =='s':
        ch = 'S'+ps
        o = 90
    elif i2 == 'L' or i2 =='l':
        ch = 'L'+pl
        o = 120
    elif i2 == 'M' or i2 == 'm':
        ch = 'M'+pm
        o = 100
    else:
        er = 'sub '
else:
    er = 'main '

if bool(er):
    print('{}{}{}.'.format(inv, er, 'menu choice'))
else:
    print('Your', ch+'is', o, 'Baht.')
'''

#PB03: Electric Appliance Store
'''
TV = int(input('How many TVs? '))
CD = int(input('How many DVD players? '))
AS = int(input('How many Audio Systems? '))
if TV >= 0 and CD >= 0 and AS >= 0:
    t1 = TV * 6000
    t2 = CD * 1500
    t3 = AS * 3000
    totalt = t1 + t2 + t3
    if totalt >= 24000:
        discnt = totalt * 0.2
        pay    = totalt * 0.8
        suf1   = 'You\'ve got a discount of {:.2f} baht.\n'.format(discnt)
    else:
        suf1 = ''
        pay    = totalt
    suf = '{}Your payment is {:.2f} baht. Thank you!'.format(suf1, pay)
    print('Total price is {:.2f} baht.\n{}'.format(totalt, suf))
else:
    pass
'''

#PB04: Buffet
'''
kind = input('Enter your buffet choice: ')
qwed = 'Is today Wednesday (yes/no)? '
outp = 'Your payment is {:.2f} Baht.'
if kind == 'JAPANESE' or kind == 'Japanese' or kind == 'japanese':
    dsh = 1000
    wed = input(qwed)
    if wed == 'YES' or wed == 'Yes' or wed == 'yes':
        pay = dsh * 0.85
    else:
        pay = dsh
    print(outp.format(pay))
elif kind == 'KOREAN' or kind == 'Korean' or kind == 'korean':
    dsh = 1500
    wed = input(qwed)
    if wed == 'YES' or wed == 'Yes' or wed == 'yes':
        pay = dsh * 0.85
    else:
        pay = dsh
    print(outp.format(pay))
else:
    print('Sorry, there is no {} buffet.'.format(kind))
'''

#PB05: Negative Income Tax
'''
age = float(input('Enter your age: '))
inc = float(input('Enter your net income: '))
if age < 15 or age > 60:
    error = 'Invalid age.'
elif inc > 79999 or inc < 1:
    error = 'Invalid income.'
else:
    error = ''
if bool(error) == 1:
    print(error)
else:
    if  inc > 30000:
        back = (79999 - inc + 1) * 0.12
    else:
        back = inc * 0.2
    print('Your negative income tax is {:.2f} Baht.'.format(back))
'''

#PB06: Leap Year
'''
i = int(input('Enter year: '))
if i <= 0:
    print('Invalid year.')
else:   
    if i % 4 == 0:
        if i % 100 != 0 or i % 400 == 0:
                o = ' '
        else:
            o = ' not '
    else:
        o = ' not '
    print('{} is{}a leap year.'.format(i, o))
'''

#PB07: Pokemon
'''
I = int(input('Enter level pokemon: '))
Q = input('Enter level pokeball: ')
d = int(input('Enter distance: '))                  #cm
if Q == 'H' or Q == 'h':
    x = 0.01
elif Q == 'M' or Q == 'm':
    if I <= 40:
        x = 0.03
    elif I >= 61:
        x = 0.08
    else:
        x = 0.05
elif Q == 'L' or Q == 'l':
    if I <= 40:
        x = 0.05
    elif I >= 61:
        x = 0.1
    else:
        x = 0.03
s = 100 - (I * d * x)
if s < 0:
    s = 0
elif s > 100:
    s = 100
print('{:.2f} percent.'.format(s))
'''

#PB08: DO or DONT
'''
iM = int(input('Minutes before due: '))
iT = float(input('Temperature: '))
iW = input('Is it raining (y/n)? ')
iD = (iM + 720) // 1440
print('>>> {} days before due.'.format(iD))
if iD < 2 and (iT <= 40 or ((iT > 25 and iW == 'N') or (iT > 25 and iW == 'n'))):
    oD = ' '
elif iD > 5 or iT > 40 or ((iT > 25 and iW == 'Y') or (iT > 25 and iW == 'y')):
    oD = ' not '
else:
    oD = ' '
print('>>> I will{}do the assignment.'.format(oD))
'''

#RB01 ???
'''
m = int(input('Minutes before due: '))
t = float(input('Temperature: '))
r = input('Is it raining (y/n)? ')
day = (m / 60) / 24
if m < 720:
    cal = round(day)
    print('>>> {} days before due.'.format(cal))
    print('>>> I will do the assignment.')
else:
    cal = round(day + 0.01)
    print('>>> {} days before due.'.format(cal))
    if (r == 'y' and t > 25) or (r == 'Y' and t > 25):
        print('>>> I will not do the assignment.')
    elif t > 40:
        print('>>> I will not do the assignment.')
    elif cal > 5:
        print('>>> I will not do the assignment.')
    elif cal < 2:
        print('>>> I will do the assignment.')
    else:
        print('>>> I will do the assignment.')
'''

#RB02
'''
#input
time = int(input("Minutes before due: "))
tem = float(input("Temperature: "))
rain = input("Is it raining (y/n)? ")

#process
day = (time+720) // 1440
print(">>> {} days before due.".format(day))

if day < 2 and (tem <= 40 or (tem > 40 and rain == 'N' or rain == 'n')):
    print(">>> I will do the assignment.")

elif tem > 40:
    print(">>> I will not do the assignment.")

elif tem > 25 and rain == "y" or rain == "Y":
    print(">>> I will not do the assignment.")
    
elif day > 5:
    print(">>> I will not do the assignment.")
    
else:
    print(">>> I will do the assignment.")
'''