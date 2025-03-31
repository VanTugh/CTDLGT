# tim phan tu nghich dao bang o clit mo rong 
def ucl(a , b) :
    while b:
        a , b = b, a%b
    return a
def ex_clit(a,b) :
    if ucl(a,b) != 1:
       return
    r0, r1= b, a
    x0, x1 = 0, 1
    y0, y1 = 1, 0
    while r1 != 1 :
     q=r0//r1
     r0, r1 = r1 , r0%r1
     x0, x1 = x1, x0-q*x1
     y0, y1 = y1, y0-q*y1
    if x1<0 :
       x1= a+x1
    return x1

print(ex_clit(4,6))


