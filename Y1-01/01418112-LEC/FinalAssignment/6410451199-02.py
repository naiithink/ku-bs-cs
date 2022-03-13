def complement9(x):
    product = ""
    if isinstance(x, int) and x > 0:
        x = str(x)
        for i in x:
            product += str(9 - int(i))
    return product

x = 431609
print(complement9(x))