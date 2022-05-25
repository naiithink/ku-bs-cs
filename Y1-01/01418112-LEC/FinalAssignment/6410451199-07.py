def firstDescPair(ls):
    product = None
    if ls:
        each = ls.split(" ")
        def findOut(each):
            product = None
            if len(each) < 2:
                return None
            elif int(each[0]) < int(each[1]) or int(each[0]) == int(each[1]):
                return findOut(each[1:])
            else:
                product = [each[0], each[1]]
                return product
        product = findOut(each)
        if product and len(product) > 1:
            product = [str(i) for i in product]
            product = " ".join(product)
    return product

ls = "50 57 108 123 1000 999 998 0"
print(firstDescPair(ls))