def maxlen(s):
    st = s.split(" ")
    ls = [len(i) for i in st]
    mx = max(ls)
    product = [mx, [i for i in st if len(i) == mx]]
    return product

s = "Gently down the stream"
print(maxlen(s)[0], *maxlen(s)[1], sep="\n")