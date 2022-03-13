def sumRowCol(ls, numr, numc):
    iPut = 0; smr = 0; sumr = []; sumc = []
    while iPut < numc:
        sumc.append(0)
        iPut += 1
    for i in ls:
        cnt = 0
        for j in i:
            col = cnt % numc
            smr += int(j)
            cnt += 1
            if cnt == numc:
                sumr.append(smr)
                smr = 0
            sumc[col] += int(j)
    return [sumr, sumc]

numr = int(input())
numc = int(input())
ls = []; cnt = 0
while cnt < numr:
    ls.append(input().split(" "))
    cnt += 1
print(*sumRowCol(ls, numr, numc), sep="\n")

"""
5
6
0 -1 3 8 6 7
2 2 2 2 2 2
3 4 1 9 2 -3
-2 8 10 12 5 1
8 2 9 3 4 7
"""