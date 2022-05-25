daysInAMonth = {
    31: [1, 3, 5, 7, 8, 10, 12],
    30: [4, 6, 9, 11],
    28: [2]
}

def generate_yearMap(daysInAMonth, yearMap={}, initDay=1):
    for month in range(1, 13):
        max = [days for days in daysInAMonth if month in daysInAMonth[days]]
        max[0] += initDay
        yearMap[month] = list(range(initDay, max[0]))
        initDay = yearMap[month][-1] + 1
    return yearMap

yearMap = generate_yearMap(daysInAMonth)
def invalidFound(inputDate):
    invalid = False
    for month in dateInput:
        if month not in range(1, 13):
            invalid = 'Wrong Month'
        else:
            for day in dateInput[month]:
                if day not in daysInAMonth[month]:
                    invalid = 'Wrong Day'
    return invalid

dateInput = []
while len(dateInput) < 3:
    if len(dateInput) < 2:
        inputDate = input().split('-')
    else:
        inputDate = [input(), '1']
    if not invalidFound(inputDate):
        dateInput.append([int(i) for i in inputDate])

if invalidFound(inputDate):
    print(invalidFound(inputDate))
else:
    if dateInput[0][1] == dateInput[1][1]:
        dateInput[int(dateInput[1][1])] = sorted([int(dateInput[0][0]), int(dateInput[1][0])])

print('eiei', dateInput)