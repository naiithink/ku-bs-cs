iPut = input()
excact = len(iPut)
remain = len(iPut)
while remain:
    toPrint = " " * (excact - remain) + " ".join(iPut)
    print(toPrint)
    remain -= 1
    iPut = iPut[:remain]