#PASSED

"""
s, shift, c = input().lower(), 0, ""
for i in s:
    if not shift and i in "-_=.$":
        shift = 1
        continue
    elif not shift:
        c += i
        continue
    if shift and i:
        c += i.upper()
        shift = 0

print(c)
"""

###
"""def camel(phrase, original):
    if len(phrase) < 2:
        return phrase
    if phrase is original:
        for i in phrase:
            if i not in "-_=.$":
                i = i.lower()
            else:
                break
    if phrase[0] in "-_=.$":
        return phrase[1].upper() + camel(phrase[2:], original)
    elif len(phrase):
        return phrase[0] + camel(phrase[1:], original)

s = input()
print(camel(s, s))
"""
"""word = input().lower()
ls = []
ans = ''
i = 0
sym = ['-', '_', '=', '.', '$']
while i < len(word):
if word[i] in sym:
word = word.replace(word[i], ' ')
i += 1
word = word.split(' ')
for j in word:
if j != '':
ls.append(j)
for k in range(len(ls)):
if k != 0:
ls[k] = ls[k].capitalize()
print(''.join(ls))"""

"""
import builtins
import inspect

a = "hap"
b = a.find("")
print(inspect.getsource(input))
"""

"""matrix = []
while True:
    line = input()
    if line == "-1":
        break
    lambda: x = """

"""l1 = [1,2,3,4,5,6,7,8,9]

def convintomatrix(x):

    sqrt = int(len(x) ** 0.5)
    matrix = []
    while x != []:
        matrix.append(x[:sqrt])
        x = x[sqrt:]
    return matrix

print (convintomatrix(l1))"""

"""import multiprocessing

def replace(result, guess):
    for char in result:
        if char == guess:
            return guess
        else:
            return "-"

target = input(); result = ""
while True:
    print("j")
    guess = input()
    check = guess * len(target)
    if guess == "0":
        break
    result = map(replace, guess)
    #print([(result.replace(k, j)) for i in target for j in guess for k in result if i == j])

result = target
print(target)
"""

def checkif(number):
    if number[::-1].find(".") > 2:
        return False
    
    if number.find(",") > 3:
        return False

    cir = 0
    for i in number:
        if i == ",":
            cir += 1
        if not cir and i == "0":
            return False

    convertable = ""
    for i in number[::-1]:
        if number.count(","):
            if i != ",":
                convertable += i
        else:
            convertable = number[::-1]
    while True:
        try:
            float(convertable[::-1])
            break
        except ValueError:
            return False
    integral = number[::-1]
    if number.count("."):
        integral = number[(len(number) - number.rfind(".")) * -1 - 1::-1]
    index = 0; commasep = []
    for i in integral:
        index += 1
        if i == ",":
            commasep.append(index)
    for i in commasep:
        if i % 4:
            return False

    return True


inp = input()

if inp and inp[-1] != "." and inp[0] != "," and checkif(inp) and not inp.count(" "):
    number = ""
    for i in inp:
        if i != ",":
            number += i
    if float(number) > 0:
        if number.count("."):
            precision = number[::-1].rfind(".")
            result = ("{:.{}f}".format(float(number) + 1, precision))
            print(str(result).zfill(len(number)))
        else:
            result = int(number) + 1
            print(str(result).zfill(len(number)))
    else:
        print("ERROR")
else:
    print("ERROR")

x = input(); ls = []; member = ""; indx = 0
for i in x:
    if i != ",":
        member += i
    elif i == ",":
        ls.append(member.strip())
        member = "">
    if indx == len(x) - 1:
        if i != "," and i != " ":
            ls.append(member)
            break
        else:
            ls.append("")
            break
    indx += 1

count = 0
for i in ls:
    if count == len(ls) - 1:
        print("\"{}\"".format(i), end="")
    else:
        print(f"\"{i}\",", end="")
    count += 1