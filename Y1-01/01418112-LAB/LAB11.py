# PB01
"""
line = int(input())

n = 0
width = (1 + (line - 1) * 2)
while n < line:
    n += 1
    symb = "*" * (1 + (n - 1) * 2)
    print("|{:^{complement}s}|".format(symb, complement = width))
"""

"""
line = int(input())

i = 1
star = 1
width = (line * 2) - 1
while i <= line:
    symb = '*'*star
    print('|{:^{wid}s}|'.format(symb,wid=width))

    i += 1
    star += 2
"""

# PB02
"""
data = input()
vowels = "aeiou"
inc = 0
for i in str.lower(data):
    if i in vowels[0:6]:
        inc += 1

print(inc)
"""

# PB03
"""
datain = input()
vowels = "aeiouAEIOU"
dataot = ""
for i in datain:
    if i not in vowels[0:13]:
        dataot += i

print(dataot)
"""

# PB04
"""
target = input()
ntargt = len(target)
used = []
if ntargt != 0 and ntargt <= 100:
    for i in target:
        if ord(i) < 97 or ord(i) > 122:
            boo = False
            break
        else:
            boo = True
    if boo:
        count = 6
        corrt = 0
        while count > 0:
            guess = input()
            if guess == "0":
                break
            elif len(guess) == 1 and guess in target[:ntargt + 1] and guess not in used:
                corrt += target.count(guess)
                used += guess
            else:
                count -= 1
        print("%d/%d" % (corrt, ntargt))
else:
    pass
"""

# PB05
"""
rss = input()
cri = input()

scr = 0
symb = "PCS-X"
used = ""

if len(rss) and rss[0] == "[" and rss[-1] == "]" and rss != "[]":
    for i in cri:
        if i not in used and i in symb:
            scr += rss.count(i)
            used += i
    css = len(rss) - 2
    mks = scr * 100 / css
else:
    mks = 0

print("%d\n%.2f" % (scr, mks))
"""

# PB06
"""
def isVowel(c):
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u'

def decrp(encrp):
    if len(encrp) < 3:
        return encrp
    if isVowel(encrp[0]) and encrp[2] == encrp[0] and encrp[1] == 'p':
        return encrp[0] + decrp(encrp[3:])
    else:
        return encrp[0] + decrp(encrp[1:])

encrp = input()
print(decrp(encrp))
"""

word = input().lower()
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

print(''.join(ls))