#6410451199 พศวัต ถิ่นกาญจน์วัฒนา

"""
i1 = int(input())

if i1 >= 0 and i1 <= 255:
    
"""

#02
"""
n = int(input())
p = 1
c = 0

while True:
    if p == n:
        break    
    if n % p == 0:
        c += p
    p += 1
print(c)
"""

#03
"""
n = int(input())                #levels
leng = 5 + (n - 1) * 2
level = 0
sublevel_line = 0
done = 0

while done <= n:
    level += 1
    while sublevel_line <= 3:
        if sublevel_line == 0:
            symbinsub = level
        elif sublevel_line == 3:
            sublevel_line = 0
            break 
        
        symb = "*" * symbinsub
        comple = "." * ((leng - symbinsub) // 2)
        print("{}{}{}".format(comple, symb, comple))
        symbinsub += 2
        sublevel_line += 1
    done += 1
    if done == n:
        break    

if leng % 2 == 0:
    comple = "." * ((leng - 3) / 2)
else:
    comple = "." * (((leng + 1) - 3) // 2)
base = "{}***{}\n{}***{}\n{}***{}".format(comple, comple, comple, comple, comple, comple)
print(base)
"""