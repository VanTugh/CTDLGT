# thuat toan tim uoc so chung lon nhat
def UCL(a,b):
    while b:
        a,b=b,a%b
    return a

#test thuat toan
a=int(input(" nhap vao a : "))
b=int(input(" nhap vao b : "))
print(str(UCL(a,b)) + " la ucl cua "+str(a) + " va " +str(b) )
# thuat toan tim module nghich dao theo oclit
def nghich_dao_modulo(a,b):
    if UCL(a,b)!=1: 
        print(" hai so nay khong phai la 2 so nguyen to ")
        return None
    def extened_gcd(a,b):
        if b==0:
            return a,1,0
        else:
            gcd,x1,y1=extened_gcd(b,a%b)
            x=y1
            y=x1-(a//b)*y1
            return gcd,x,y
    gcd, x, y= extened_gcd(a,b)
    return x%b
m=int(input(" nhap vao m : "))
n=int(input(" nhap vao n : "))
print(str(nghich_dao_modulo(m,n)) + " la nghich dao cua "+str(m) + " va " +str(n) )
# thuat toan tim module nghich dao theo oclit mo rong
def ex_clitt(a,b):
    if UCL(a,b)!=1:
        return
    else:
        r0,r1=a,b
        x0,x1=0,1
        y0,y1=1,0
        while r1 !=1:
            q=r0//r1
            r0,r1=r1, r0 - q * r1
            x0,x1=x1, x1-x0*q
            y0,y1=y1, y1-y0*q
        if x1<0:
            x1=a+x1
    return x1
# thuat toan a mod b theo binary a^b mod n
def binary_T(a,b,n):
    f=1
    a=a%n
    b_bin=bin(b)[2:] #Dùng để cắt chuỗi từ ký tự thứ 2 trở đi (bỏ '0b').
    for bit in b_bin:
        f=(f*f)%n
        if bit == '1':
            f=f*a
    return f
# test
print(binary_T(7,560,561))

