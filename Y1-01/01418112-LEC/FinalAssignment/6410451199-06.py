def is_quirksome(x, digit):
    number = x
    part = 0; part2 = 0; part1 = 0
    rnd = digit / 2; cnt = 0
    sec = 1
    while cnt < rnd:
        part += (number % 10) * 10 ** cnt
        number = number // 10
        cnt += 1
        if cnt == rnd and sec == 1:
            cnt = 0
            part2 = part
            part = 0
            sec += 1
    part1 = part
    if (part1 + part2) ** 2 == x:
        return True
    else:
        return False

x = 81
digit = 2
print(is_quirksome(x, digit))