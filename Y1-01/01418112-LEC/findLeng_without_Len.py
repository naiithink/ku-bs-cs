def is_anagram(str1, str2):

    ls = "123"
    num = [x for x in range(999)]
    cnt = [1 for i in ls if i]
    findLen = [y for x in cnt for y in num if x]
    leng = findLen[-1]
    print("leng =", leng)
    
    #for i in cnt:
    #    sum += int(i)
    
    #print(cnt)
    #for i in ls:


"""    if ls == :
        return True
    else:
        return False
"""
str1 = "abcde"
str2 = "acebd"
print(is_anagram(str1, str2))

ls = "123"
    num = [x for x in range(999)]
    cnt = [1 for i in ls if i]
    findLen = [y for x in cnt for y in num if x]
    leng = findLen[-1]
    print("leng =", leng)