#PB01
"""
def check_prime(n):
    if n <= 1:
        is_prime = 0
    else:
        divder = n - 1
        is_prime = 1
        while divder >= 2:
            rem = n % divder
            if rem == 0:
                is_prime = 0
                break
            if divder == 2:
                break
            divder -= 1
    return is_prime

n = int(input("Enter number: "))
if check_prime(n):
    print(n,"is a prime number.")
else:
    print(n,"is not a prime number.")
"""

#PB02
"""
def factor_count(n):
    divder = n
    count = 0
    if n >= 1:
        while n != 0:
            rem = n % divder
            if rem == 0:
                count += 1
                if divder == 1:
                    break
            divder -= 1
    else:
        pass

    return count

n = int(input("Enter n: "))
c = factor_count(n)
print(c)
"""

#PB03
"""
def nb_year(p0, percent, aug, p):
    import math
    day = 0
    val = p0
    while val <= p:
        if val >= p:
            break
        day += 1
        val = math.floor(val + (val * (percent / 100) + aug))

    return day

print( nb_year(1500000, 0.25, 1000, 2000000) )
"""

#PB04
"""
def factorial(n):
    if n >= -1 and n <= 1:
        product = 1
    else:
        if n < 0:
            product = n * -1
            factor = (n * -1) - 1
        else:
            product = n
            factor = n - 1
        while factor >= 1:
            product = product * factor
            factor -= 1
            if factor == 1:
                break
    if n < 0:
        product = product * -1

    return product

n = int(input("Enter n: "))
print("%d!" % n, "=", factorial(n))
"""

"""???
def fac(n):
    if n == 1:
        product = 1
    elif n <= 0:
        product = "Invalid Input"
    else:
        x = n
        product = 0
        while x2 >= 1:
            product = x * (x - 1)
            x -= 1
            if x == 1:
                break

    return product

n = int(input("Enter n: "))
print("%d!" % n, "=", fac(n))
"""

#PB05
"""
def fibonacci(n):
    if n == 1 or n == 2:
        product = 1
    else:
        count = 0
        count_to = n - 2
        a1 = 1
        a2 = 1
        while count <= count_to:
            count += 1
            product = a1 + a2
            a1 = a2
            a2 = product
            if count == count_to:
                break

    return product

n = int(input("Enter n: "))
print("fibo({}) = {}".format(n, fibonacci(n)))
"""

#PB06
"""
def alt_sum(n):
    import math
    n_p = math.ceil(n / 2)
    n_n = math.floor(n / 2)
    sum_positive = (n_p * (2 + ((n_p - 1) * 2))) // 2
    sum_negative = -1 * ((n_n * (4 + ((n_n - 1) * 2))) // 2)
    product = sum_positive + sum_negative

    return product

n = int(input("Enter n of series: "))
print("Alternating Sum from 1 to {:d} is {:d}".format(n, alt_sum(n)))
"""