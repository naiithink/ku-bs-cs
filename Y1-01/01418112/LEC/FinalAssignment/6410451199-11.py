def firstClosestPair(ls):
    ls = ls.split(" ")
    cnt = 0
    dif = {}
    stopAt = len(ls) - 1
    while cnt < stopAt:
        dif[f"{cnt} {cnt + 1}"] = abs(float(ls[cnt]) - float(ls[cnt + 1]))
        cnt += 1
    dis = min(list(dif.values()))
    pair = [key for key, value in dif.items() if value == dis]
    position = pair[0].split(" ")
    return [ls[int(position[0])], ls[int(position[1])]]

ls = "50 61 108 123 101 91 98 0"
print(*firstClosestPair(ls))