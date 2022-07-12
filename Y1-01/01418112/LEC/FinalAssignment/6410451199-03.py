def is_abecedarian(s):
    ls = list(s)
    if ls == sorted(ls):
        return True
    else:
        return False

s = "duck"
print(is_abecedarian(s))