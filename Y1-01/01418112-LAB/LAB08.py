"""
def f1(a, b):
    if a >= 0 and b >= 0 and b <= 9:
        rnd = len(str(a))
        cnt = 0
        while rnd != 0:
            rem = a % 10
            a = a // 10
            if rem >= b:
                cnt += 1
            rnd -= 1
    else:
        cnt = 0
    return cnt

input1 = int(input())
input2 = int(input())
print(f1(input2, input1))
"""


# PB01
"""
def circle(r):
    area = math.pi * r ** 2
    return area

def circumference(r):
    circ = math.pi * 2 * r
    return circ

def sphere(r):
    sphr = (4 / 3) * math.pi * r ** 3
    return sphr

r = float(input("Enter a radius: "))

print('Area of a circle with radius %.2f is %.2f.' % (r, circle(r)))
print('Circumference of a circle with radius %.2f is %.2f.' % (r, circumference(r)))
print('Volume of sphere with radius %.2f is %.2f.' % (r, sphere(r)))
"""

# PB02
"""
def digit(num):
    rad1 = num % 10
    return rad1

def tens(num):
    num = num // 10
    rad2 = num % 10
    return rad2

def hundreds(num):
    num = num // 10 ** 2
    rad3 = num % 10
    return rad3

def thousands(num):
    num = num // 10 ** 3
    rad4 = num % 10
    return rad4

def sum_digits(num):
    sum = digit(num) + tens(num) + hundreds(num) + thousands(num)
    return sum

num = int(input("Enter a number (0 to 9999): "))

print('Digit place is %d.' % (digit(num)))
print('Tens place is %d.' % (tens(num)))
print('Hundreds place is %d.' % (hundreds(num)))
print('Thousands place is %d.' % (thousands(num)))
print('Sum of all digits is %d.' % sum_digits(num))
"""

# PB03
"""
def in_percent(number):
    exact_value = number / 100
    return exact_value

def simple_interest(x, y, z):
    rates = x * y * z
    total = x + rates
    return total

def compound_interest(x, y, z):
    back = x * (1 + y) ** z
    return back

p = float(input("Enter principle: "))
r = in_percent(float(input("Enter interest rate: ")))
t = float(input("Enter time: "))

print('Return money for simple interest calculation is %.2f Baht.' % (simple_interest(p, r, t)))
print('Return money for compound interest calculation is %.2f Baht.' % (compound_interest(p, r, t)))
"""

# PB04
"""
def read_hour():
    h = int(input('Enter hour: '))
    if h >= 0 and h <= 23:
        return h


def read_minute():
    m = int(input('Enter minute: '))
    if m >= 0 and m <= 59:
        return m


def read_second():
    s = int(input('Enter second: '))
    if s >= 0 and s <= 59:
        return s


def to_seconds(h, m, s):
    in_sec = h * 3600 + m * 60 + s
    return in_sec


def time_elapsed(start_time, finish_time):
    elapse = abs(finish_time - start_time)
    if elapse // 3600 != 0:
        hours = elapse // 3600
        elapse = elapse - hours * 3600
    else:
        hours = 0
    if elapse // 60 != 0:
        minutes = elapse // 60
        elapse = elapse - minutes * 60
    else:
        minutes = 0
    seconds = elapse
    display = '{} hours {} minutes {} seconds.'.format(hours, minutes, seconds)
    return display

#
def read_time():
    print('>> ', end='')
    hour = read_hour()
    print('>> ', end='')
    minute = read_minute()
    print('>> ', end='')
    second = read_second()
    return to_seconds(hour, minute, second)

print('Start time:')
start_time = read_time()
print('Finish time:')
finish_time = read_time()
print('Elapsed time is', time_elapsed(start_time, finish_time))
"""

# PB05
"""
def change(amount, note):
    changed = 0
    if amount >= note:
        changed = amount // note
    return changed

money = int(input("Enter total money: "))
b500 = change(money, 500)
left = money - b500 * 500
b100 = change(left, 100)
left = left - b100 * 100
b20 = change(left, 20)
left = left - b20 * 20
b5 = change(left, 5)
left = left - b5 * 5
b1 = left

print("500: %d" % b500)
print("100: %d" % b100)
print(" 20: %d" % b20)
print("  5: %d" % b5)
print("  1: %d" % b1)
"""


# นั่งมึนนอนมึนอยู่ตั้งนาน:
"""
def change(in_money):
    changed = 0
    input_money = 0

    if in_money >= 500:
        changed = money // 500
        round += 1
        rnd +=
    else:
        countRound = 0
        while True:
            if in_money >= 100:
                b100 = money // 100
                in_money = in_money - 100 * b100
            else:
                rnd += 1
                if in_money >= 20:
        if round == 1:
            changed = b100

        if money >= 100:
            input_money = money + (b500 * 500)
        elif money >= 20:
            input_money = money + (b500 * 500) + (b100 * 100)
        elif money >= 5:
            input_money = money + (b500 * 500) + (b100 * 100) + (b20 * 20)
        else:
            input_money = 1

        toCountRnd = input_money

        rnd = 0

        rnd500 = 0
        rnd100 = 0
        rnd20 = 0

        is_rnd500 = 0
        is_rnd100 = 0
        is_rnd20 = 0
        is_rnd5 = 0

        while toCountRnd >= 5:
            if toCountRnd // 500 > 0:
                toCountRnd = toCountRnd - 500
                rnd500 += 1
                rnd += 1
            elif toCountRnd // 100 > 0:
                toCountRnd = toCountRnd - 100
                rnd100 += 1
                rnd += 1
            elif toCountRnd // 20 > 0:
                toCountRnd = toCountRnd - 20
                rnd20 += 1
                rnd += 1
            elif toCountRnd // 5 > 0:
                toCountRnd = toCountRnd - 5
            else:
                break

        while toCheckRnd >= 5:
            if toCheckRnd // 500 > 0:
                toCheckRnd = toCheckRnd - 500
                is_rnd500 += 1
            elif toCheckRnd // 100 > 0:
                toCheckRnd = toCheckRnd - 100
                is_rnd100 += 1
            elif toCheckRnd // 20 > 0:
                toCheckRnd = toCheckRnd - 20
                is_rnd20 += 1
            elif toCheckRnd // 5 > 0:
                toCheckRnd = toCheckRnd - 5
                is_rnd5 += 1
            elif toCheckRnd == money:
                break

        if len(str(money)) > 1:
            radix1 = money % 10
            money -= radix1

        if money // 5 > 0 and rnd >= 4:
            changed = money // 5
            rnd
            if money // 20 > 0 and rnd >= 3:
                changed = money // 20
                if money // 100 > 0 and rnd >= 2:
                    changed = money // 100
                    if money // 500 > 0 and rnd >= 1:
                        changed = money // 500

    return (changed, round)


    if note == "b500":
        if amount >= 500:
            changed = amount // 500
        else:
            changed = 0
    elif note == "b100":
        if amount >= 100:
            changed = amount // 100
        else:
            changed = 0
    elif note == "b20":
        if amount >= 20:
            changed = amount // 20
        else:
            changed = 0
    elif note == "b5":
        if amount >= 5:
            changed = amount // 5
        else:
            changed = 0
"""

def f1(a, b):
    count = 0
    while True:
        n = a % 10
        if a == 0:
            break
        if n >= b:
            count += 1
        a = a // 10
    return count


x = int(input())
y = int(input())
print(f1(x, y))