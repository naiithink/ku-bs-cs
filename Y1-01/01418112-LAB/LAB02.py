import math

#PB01
#r  = int(input('Enter a radius: '))
#Ar = '{:.2f}'.format(math.pi*r**2)
#Cr = '{:.2f}'.format(math.pi*r*2)
#print('Area of a circle with radius', r, 'is', Ar,'\nCircumference of a circle with radius', r, 'is', Cr)

#PB02
#wid    = float(input('Enter width: '))
#len    = float(input('Enter length: '))
#dpt    = float(input('Enter depth: '))
#vol    = wid*len*dpt                        #cub.m
#STaken = vol*15                             #s
#MTaken = STaken/60
#dsp    = '{}{:.2f}{}'.format('Time to fill a pool is ', MTaken, ' minutes.')
#print(dsp)

#PB03
#inc = float(input())
#ex  = float(input())
#print('1234567890'*3)
#print('{:13s}{:+8.2f} {:s}'.format('Total Income ', inc, 'bahts'))
#print('{:13s}{:8.2f} {:>s}'.format('Expense', ex, 'bahts'))
#print('{:13s}{:08.2f} {:>s}'.format('Profit', inc+ex, 'bahts'))

#PB04
#print('First fraction:')
#a = int(input('>>Enter a numerator a: '))
#b = int(input('>>Enter a denominator b: '))
#print('Second fraction:')
#c = int(input('>>Enter a numerator c: '))
#d = int(input('>>Enter a denominator d: '))
#cmn_den = b*d
#a2 = a*d
#c2 = c*b
#rnum = a2+c2
#print('Summation of the two fractions is', rnum, "/", cmn_den)

#PB05
#note K1 = Kaew, K2 = Kwan
#Dis     = int(input())
#Cap     = int(input())
#maxDis  = Cap*15
#dpnK1   = maxDis*0.5
#dpnK2   = maxDis*0.9
#nK1     = math.ceil((Dis+1)/dpnK1)
#nK2     = math.ceil((Dis+1)/dpnK2)
#print(nK1)
#print(nK2)

#PB06
#n  = int(input())
#d1 = input()
#d2 = input()
#eT = n//2
#oT = math.ceil(n%2)
#eD = "{}{}".format(d1, d2)
#oD = str(d1)
#rs = eD*eT+oD*oT
#print(rs)

#PB07
#DOC
#x   = float(input('Enter x: '))
#y   = float(input('Enter y: '))
#z   = float(input('Enter z: '))
#a1  = math.pow(x, y)+z
#a2  = math.cos(2*(math.pi))+math.log(x)
#a3  = math.fabs(x)+math.fabs(y)
#a4  = math.pow((x**2)+(y**2)+(z**2), 0.5)
#a5  = math.pow(math.sin(x), 2)+math.pow(math.cos(x), 2)
#a6  = math.pow(x+y, 1/5)
#a7  = math.pow(math.e, x*(math.log(y)))
#da1 = '{}{:.2f}'.format('a1 = ', a1)
#da2 = '{}{:.2f}'.format('a2 = ', a2)
#da3 = '{}{:.2f}'.format('a3 = ', a3)
#da4 = '{}{:.2f}'.format('a4 = ', a4)
#da5 = '{}{:.2f}'.format('a5 = ', a5)
#da6 = '{}{:.2f}'.format('a6 = ', a6)
#da7 = '{}{:.2f}'.format('a7 = ', a7)
#print(da1)
#print(da2)
#print(da3)
#print(da4)
#print(da5)
#print(da6)
#print(da7)

#-----