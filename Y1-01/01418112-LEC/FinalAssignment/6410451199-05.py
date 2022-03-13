def is_anagram(str1, str2):
    ps = 0
    for i in str1:
        for j in str2:
            if i == j:
                ps += 1
                continue
    if ps == len(str1):
        return True
    else:
        return False

str1 = "azp"
str2 = "pas"
print(is_anagram(str1, str2))