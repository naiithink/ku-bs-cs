"""
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
data = [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384]
months = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"]
"""

"""
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
n = 0
total = 0
while n < 10:
    total += primes[n]
    n += 1
print(total)
"""

"""
months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec']
days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
n = 0

while n < 12:
    print("%s %s" % (months[n], days_in_month[n]))
    n += 1
"""

"""
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
n = 0
while n < 10:
    primes[n] *= 2
    n += 1
print(primes)
"""

"""
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
total = 0
for i in primes:
    total += i
print(total)
"""

"""
import math
def find_max(list):
    max = -math.inf
    for i in list:
        if i > max:
            max = i
    return max

print(find_max([1, 2, 3, 4]))
print(find_max([4, 3, 2, 1]))
print(find_max([4, 3, 5, 9, 7, 2, 4, 4, 10, 0, 11, 8]))
print(find_max([-7, -9, -8, -2, -7, -11, -4, -5]))
"""

"""
scores = [60, 70, 85, 66, 70, 0, 15, 9]
for i in range(0, 8):
    print(scores[i])
"""

# EX08-01
"""
data = []
while True:
    n = int(input())
    if n != -1:
        data.append(n)
    else:
        break

print(data)
"""

# EX08-02
"""
data = []
s = input()
while s:
    data.append(s)
    s = input()

print(data)
"""

# EX09-01
"""
s = input()
data = []
while s:
    data.append(s)
    s = input()

max = ""
for i in data:
    if len(i) > len(max):
        max = i
print(max)
"""

"""
s = input()
data = []
while s:
    data.append(s)
    s = input()
print(max(data))
"""

# PB01
"""
score = []
n = 20
while n > 0:
    inp = int(input("Enter score: "))
    if inp >= 0 and inp <= 10:
        score.append(inp)
        n -= 1
    else:
        print("Score is out of range.")

histo = list(range(0, 11))

for i in histo:
    for s in score:
        if i == s:
            histo[i] += 1
    histo[i] -= i

print("Original list:\n{}".format(score))

sc = 0
while sc < 11:
    stars = "*" * histo[sc]
    print("{:>2d} {}".format(sc, stars))
    sc += 1
"""

# PB02
"""
def accum_sum(l):
    product = 0
    for i in l:
        product += i
        if i != l[-1]:
            print(product)
    return product

l = []
n = int(input("Enter a number (0 to end): "))

while n:
    if n == 0:
        break
    elif n >= 1 and n <= 999:
        l.append(n)
    else:
        print("Number is out of range.")
    n = int(input("Enter a number (0 to end): "))

print("Original list:\n{}\nAccumulative Sum:".format(l))
print(accum_sum(l))
"""

# PB03
"""
def find_sd(l):
    sum_score = 0
    n = len(l)
    for i in l:
        sum_score += i
    avg = sum_score / n

    sum_ss = 0
    for i in l:
        ss = (i - avg) ** 2
        sum_ss += ss
    sd = (sum_ss / (n - 1)) ** 0.5

    return sd

l = []
while True:
    score = float(input("Enter score: "))
    if score == -1:
        break
    elif score < 0 or score > 100:
        print("Score is out of range.")
    else:
        l.append(score)

if l:
    n = len(l)
    max = max(l)
    min = min(l)
    sum_score = 0
    for i in l:
        sum_score += i
    avg = sum_score / n

    print("Maximum score is {:.2f}.\nMinimum score is {:.2f}.\nAverage score is {:.2f}.\nStandard deviation is {:.2f}.".format(max, min, avg, find_sd(l)))
else:
    pass
"""

# PB04
"""
def find_mode(l):
    
    histo = list(range(0, 11))

    for i in histo:
        for s in l:
            if i == s:
                histo[i] += 1
        histo[i] -= i
    
    max = 0
    for i in histo:
        if i > max:
            max = i

    list_all = []
    for s in histo:
        if s == max:
            i1 = histo.index(s)
            list_all.append(i1)
            histo[i1] = 0
    for s in histo:
        if s == max:
            i2 = histo.index(s)
            list_all.append(i2)
            histo[i2] = 0
    for i in list_all:
        print(i)

l = []
count = 20
while count > 0:
    score = int(input("Enter score: "))
    if score >= 0 and score <= 10:
        l.append(score)
        count -= 1
    else:
        print("Score is out of range.")

print("-----\nOriginal list:\n{}\nMode of scores:".format(l))
find_mode(l)
"""

# PB05
"""
pool = []
while True:
    x = int(input())
    if x == -1:
        break
    elif x > 0:
        pool.append(x)
    else:
        pass

nought = pool[0]
display = [nought]
for i in pool:
    if i > nought:
        display.append(i)
        nought = i

print(display)
"""

"""
list1 = []
maxx = 0
while True:
    i = int(input())
    if i > maxx :
        maxx = i
        list1.append(maxx)
    elif i == -1 :
        break
print(list1)
"""

# PB06
"""
def remove_duplicates(t):
    product = []
    for i in t:
        if i not in product:
            product.append(i)
    return product

t = [2, 2, 2, 2, 1, 1, 2, 1, 1, 3, 3, 3]
print(remove_duplicates(t))
"""

"""
import math

def find_mode(l):
    max = -math.inf
    for i in range(len(l)):
        x = l.count(i)
        if x > max:
            max = x
    
    mode = []
    for i in range(len(l)):
        x = l.count(i)
        if x == max:
            mode.append(i)
    
    for i in mode:
        print(i)

l = []
count = 0
while count < 20:
    x = int(input('Enter score: '))
    if x > 10 or x < 0:
        print('Score is out of range.')
    else:
        l.append(x)
        count += 1

print('-----')
print('Original list:')
print(l)
print('Mode of scores:')

find_mode(l)
"""