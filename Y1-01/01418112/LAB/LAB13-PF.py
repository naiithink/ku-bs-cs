def vowels(word, count, boolean):
    word.lower()
    cnt = 0
    for i in word:
        if i in "aeiou":
            cnt += 1

    if count:
        product = cnt
    elif boolean:
        product = bool(cnt)
    
    return product

######################################################################
#import nthk
import ctypes

#print("here's it", ctypes.cast(140704471110384, ctypes.py_object).value)


# PB01
"""
word = input()
word = word.lower()
indx = 0
pair = []
while indx < len(word) - 1:
    pairing = word[indx] + word[indx + 1]
    if pairing not in pair:
        pair.append(pairing)
    indx += 1
pair.sort()
for x in pair:
    print(x)
"""

# PB02

def merge(name):
    product = ""
    round = 1
    if len(name[0]) and len(name[1]):
        for n in name:
            if len(n) < 4 or vowels(n, 1, 0) < 2:
                product += n
                continue
            th = 1
            for i in n:
                if round == 1:
                    if th and i in "aeiou":
                        th -= 1
                    elif not th:
                        break
                    product += i
                elif round == 2:
                    if not th:
                        product += i
                    if i in "aeiou":
                        th -= 1
                        continue
            round += 1
    
    print(product)
            
"""
def mixed(name):
    product = ""
    for n in name:
        if len(n) < 4 or vowels(n, 1, 0) == len(n) or not vowels(n, 0, 1):
            if product:
                product += n
                return product
            product += n
            continue
        found = 0
        for i in n:
            if vowels(i, 0, 1) and vowels(product, 1, 0) == 1:
                if found:
                    break
                product += i
                found += 1
            if vowels(i, 0, 1) and vowels(product, 0, 1): #and name.index(n) == -1:
                product += n[n.index(i) + 1:]
                return product
            if not vowels(product, 0, 1) or vowels(product, 1, 0) == 1:
                product += i
"""
name = [input(), input()]
merge(name)

"""
def mixed(name):
    mixd, turn = "", 0
    if name[0] and name[1]:
        for n in name:
            turn += 1
            if len(n) <= 3 or vowels(n, 1, 0) < 2 or vowels(n[0], 0, 1) and vowels(n[-1], 0, 1):
                mixd += n
                if turn == 2:
                    return mixd
            else:
                found = 0
                chars = 0
                for i in n:
                    if turn == 1 and found == 2:
                        if n[:chars - 1]:
                            mixd += n[:chars - 1]
                    elif turn == 2 and found == 1:
                        if n[chars:]:
                            mixd += n[chars:]
                        return mixd
                    if vowels(i, 0, 1):
                        found += 1
                    chars += 1
"""

"""
name = [input(), input()]
mixd, vwel, prnt = "", "aeiou", 1

if name[0] and name[1]:
    for i in name:
        i = i.lower()
        if ord(i[0]) not in range(97, 123):
            prnt = 0
            break
        if len(i) < 3 or vowels(i, 1, 0) < 2:
            mixd += i
            continue
        vwno = 0
        indx = 0
        adde = i
        for j in i:
            if name.index(i) == 1 and vwno == 1 and len(i[indx + 1:]) > 0:
                adde = i[indx:]
                break
            elif name.index(i) == 0 and vwno == 2 and len(i[:indx]) > 0:
                adde = i[:indx - 1]
                break
            if vowels(j, 0, 1):
                vwno += 1
            indx += 1
        mixd += adde
if prnt:
    print(mixd)
"""
"""
    print(bin(id(mixd)))
    print(hex(id(mixd)))
    """"""
    0b100000000011101001111101101110000
    0x10074fb70

    0b100000100110100000011101011110000
    0x104d03af0

    0b100000000111001101111101100110000
    0x100e6fb30
    """"""
"""

# PB03
"""
request = [input(), int(input())]
(piece, index, grocr, add) = (request[0][0], (request[1] % 7) - 1, [], "")
for i in request[0]:
    if i != ",":
        add += i
    else:
        grocr.append(add)
        add = ""
print(grocr[index])
"""

# PB04
"""
source = [input(), input(), input()]
(draft, template, raw) = (source[0], source[1], source[2])

drf = ""
for i in draft:
    if i != " " and i not in drf:
        drf += i

tem = ""
for i in template:
    if i != " " and i not in tem:
        tem += i

decrp = ""
for i in raw:
    if i in tem:
        index = tem.index(i)
        decrp += drf[index]
    else:
        decrp += i

print(decrp)
"""

# PB05
"""
word, carr, refn = input(), "a", ""
word = word.lower()
if len(word) > 1:
    for i in word:
        if ord(i) not in range(97, 123):
            refn = ""
            break
        if ord(i) in range(97, 123) and ord(i) >= ord(carr) and i not in refn:
            refn += i
            carr = i
        else:
            break
print(len(refn))
"""

# PB06
"""
phrase, rotate = input(), int(input())

if rotate and len(phrase):
    if abs(rotate) > len(phrase):
        rotate %= len(phrase)
    if rotate * -1 < 0:
        comple = len(phrase) - rotate
        print(phrase[-rotate:] + phrase[:comple])
    else:
        rotate *= -1
        comple = rotate
        print(phrase[rotate:] + phrase[:comple])
else:
    print(phrase)
"""

# PB07
