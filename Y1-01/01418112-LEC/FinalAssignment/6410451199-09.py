def shiftElement(ls, n, direction):
    ls = ls.split(" ")
    if ls and n and direction:
        if direction == "r":
            product = ("0 " * n) + str(" ".join(ls[:n + 1]))
        elif direction == "l":
            product = str(" ".join(ls[n:])) + (" 0" * n)
        return product

ls = "17 26 108 1009 0 345 225 18/60 1"
n = 1
direction = "l"
print(shiftElement(ls, n, direction))