def missing_integer(data):
    data.split(","); data.strip(); ls = list("0123456789"); ls.append("10")
    for i in ls:
        if i not in data and i != ",":
            return i

data = "3,2,10,8,5,0,1,7,6,4"
print(missing_integer(data))