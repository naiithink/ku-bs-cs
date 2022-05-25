#PM01
"""
x = float(input(""))
if (x).is_integer() == True :
    print (int(x),"is an integer.")
else:
    print (x,"is not an integer.")
"""

#PM02
"""
print("Upper left corner coordinate:")
UL_x = int(input("  << x axis: "))
UL_y = int(input("  << y axis: "))
E = int(input("  << Eastern: "))
S = int(input("  << Southern: "))
print("Enter a coordinate:")
IN_x = int(input("  << x axis: "))
IN_y = int(input("  << y axis: "))

if E > 0 and S > 0:
    UR_x = UL_x + E
    LL_y = UL_y - S
    if IN_x >= UL_x and IN_x <= UR_x and IN_y <= UL_y and IN_y >= LL_y:
        result = ""
    else:
        result = " not"
    print(">>> ({:.2f}, {:.2f}) is{} inside the rectangle.".format(IN_x, IN_y, result))
else:
    pass
"""

#PM03
"""
day = int(input())
h = int(input())
m = int(input())

mon = "monday"
tue = "tuesday"
wed = "wednesday"
thu = "thursday"
fri = "friday"
sat = "saturday"
sun = "sunday"

mor = "morning"
afn = "afternoon"
eve = "evening"
nig = "night"

mhS = 4     
mhE = 12        #+8
ahE = 18        #+6
ehE = 22        #+4

if day > 0 and day <= 7 and h >= 0 and h <= 23 and m >= 0 and m <= 60:
    if h >= 4 and h <= 12:
        time = mor
        if h == 4 and m == 0:
            time = nig
        elif h == 12 and m == 1:
            time = afn
    elif h >= 12 and h <= 18:
        time = afn
        if h == 12 and m == 0:
            time = mor
        elif h == 18 and m == 1:
            time = eve
    elif h >= 18 and h <= 22:
        time = eve
        if h == 18 and m == 0:
            time = afn
        elif h == 22 and m == 1:
            time = nig
    else:
        time = nig

    if day == 1:
        day = sun
    if day == 2:
        day = mon
    elif day == 3:
        day = tue
    elif day == 4:
        day = wed
    elif day == 5:
        day = thu
    elif day == 6:
        day = fri
    elif day == 7:
        day = sat

    print("good-{}-{}.png".format(time, day))
else:
    pass
"""

#PM04
"""
print("<<Point a>>")
aCo_x = int(input("Enter x coordinate: "))
aCo_y = int(input("Enter y coordinate: "))
print("<<Point b>>")
bCo_x = int(input("Enter x coordinate: "))
bCo_y = int(input("Enter y coordinate: "))

while True: #aCo_x != 0 and aCo_y != 0 and bCo_x != 0 and bCo_y != 0
    d_ba = (((aCo_x - bCo_x) ** 2) + ((aCo_y - bCo_y) ** 2)) ** 0.5
    d_x = abs(aCo_x - bCo_x)
    d_y = abs(aCo_y - bCo_y)

    if bCo_x - aCo_x > 0:
        direcX = "east"
    elif bCo_x - aCo_x == 0:
        direcX = ""
    else:
        direcX = "west"
    if bCo_y - aCo_y > 0:
        direcY = "north"
    elif bCo_y - aCo_y == 0:
        direcY = ""
    else:
        direcY = "south"
    if bool(direcY) and bool(direcX):
        dash = "-"
    else:
        dash = ""
    ending = "We are going {}{}{}.".format(direcY, dash, direcX)
    if bCo_x == 0 and aCo_x == 0 and bCo_y == 0 and aCo_y == 0:
        ending = "Goodbye"
    elif not bool(direcY) and not bool(direcX):
        ending = "We are going {}.".format("nowhere")

    if ending == "Goodbye":
        print(ending)
        break
    else:
        print("Distance between ({}, {}) and ({}, {}):".format(aCo_x, aCo_y, bCo_x, bCo_y))
        print("Euclidean distance is {:.2f}.".format(d_ba))
        print("Horizontal distance is {}.".format(d_x))
        print("Vertical distance is {}.".format(d_y))
        print(ending)

    print("<<Point a>>")
    aCo_x = int(input("Enter x coordinate: "))
    aCo_y = int(input("Enter y coordinate: "))
    print("<<Point b>>")
    bCo_x = int(input("Enter x coordinate: "))
    bCo_y = int(input("Enter y coordinate: "))
"""

#PM05
"""
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

#PM06
'''
a = int(input(''))
b = int(input(''))
c = int(input(''))

if a > 0 and c > 0 and b >0:
    if a*a+b*b == c*c :
        print('True')
    elif c*c+b*b == a*a :
        print('True')
    elif a*a+c*c==b*b :
        print('True')
    else:
        print('False')
'''

#PM07
"""
x = int(input())
n = int(input())
if x > 7 or  x < 1 or n < 0 or n > 31 :
  print("ERROR") 
else :
  f = n - x 
  if f % 7 == 0 :
    print("Sunday")
  elif f % 7 == 1 :
    print("Monday")
  elif f % 7 == 2 :
    print("Tuesday")
  elif f % 7 == 3 :
    print("Wednesday")
  elif f % 7 == 4 :
    print("Thursday")
  elif f % 7 == 5 :
    print("Friday")
  elif f % 7 == 6 :
    print("Saturday")
"""

#PM08
"""
d = str(input())
n = int(input())
if (n < 1 or n > 31) or ( d.lower() != "sunday" and d.lower() != "monday" and d.lower() != "tuesday" and d.lower() != "wednesday" and d.lower() != "thursday" and d.lower() != "friday" and d.lower() != "saturday" ):
  print("ERROR")
else : 
  if d.lower() == "sunday" :
    n -= 1
  elif d.lower() == "monday" :
    n = n
  elif d.lower() == "tuesday" :
    n += 8
  elif d.lower() == "wednesday" :
    n += 9
  elif d.lower() == "thursday" :
    n -= 4
  elif d.lower() == "friday" :
    n -= 3
  elif d.lower() == "saturday" :
    n -= 2
  f = n % 7
  if f % 7 == 0 :
    print("Sunday")
  elif f % 7 == 1 :
    print("Monday")
  elif f % 7 == 2 :
    print("Tuesday")
  elif f % 7 == 3 :
    print("Wednesday")
  elif f % 7 == 4 :
    print("Thursday")
  elif f % 7 == 5 :
    print("Friday")
  elif f % 7 == 6 :
    print("Saturday")

"""

#PM09
"""
n = int(input())
c = n
a = 1 
t = 0
while a <= n :
  b = 1
  while b <= n :
    m = t
    if a*b == c and (a<b) :
      t = a + b
      if m < t :
        m = t
    b += 1
  a += 1 
print(m)
"""

#PM10
"""
number = int(input())
collect = 0

if number > 0 and number <= 4 * 10 ** 9:
    while True:
        rem = number % 10
        number = number // 10
        if rem % 2 != 0:
            collect += rem
            if number == 0:
                break
        if number == 0:
            break
    if collect == 0:
        collect = -1
    print(collect)
else:
    pass
"""

#PM11
"""
number = int(input())
collect = 1
cnt = 0

if number > 0 and number <= 4 * 10 ** 9:
    while True:
        rem = number % 10
        number = number // 10
        if rem % 2 == 0:
            collect *= rem
            cnt += 1
            if number == 0:
                break
        elif rem % 2 != 0 and cnt != 0:
            rem = 1
            collect *= rem
            if number == 0:
                break
        elif number == 0 and cnt == 0:
            collect = -1
            break
    print(collect)
else:
    pass
"""

#PM12
"""
face1 = int(input())
face2 = int(input())
rnd = 0
score = 0
tscore = 0
res = ""

while True:
    if face1 > 0 and face1 <= 6 and face2 > 0 and face2 <= 6:
        rnd += 1
        score = face1 + face2
        if rnd == 1:
            if score == 7 or score == 11:
                res = "W"
                break
            elif face1 + face2 == 2 or face1 + face2 == 3 or face1 + face2 == 12:
                res = "L"
                break
            else: #score == 4 or score == 5 or score == 6 or score == 8 or score == 9 or score == 10
                tscore = score
        elif rnd != 1:
            if score == 7:
                res = "L"
                break
            elif score == tscore:
                res = "W"
                break
    else:
        print("ERROR")
        pass
    score = 0
    face1 = int(input())
    face2 = int(input())

print(rnd, score, res)
"""