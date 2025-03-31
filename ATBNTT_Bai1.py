# thuat toan tim uoc so chung lon nhat su dung euclit
def ucl(a , b) :
    while b:
        a , b = b, a%b
    return a




a = int(input(" nhap a de : "))
b= int(input(" nhap b de : "))
print(" uoc so chung lon nhat cua : ",str(a)," va ",str(b) ," la : " + str(ucl(a,b)))
if ucl(a,b) == 1 :
    print(" day la 2 so nguyen to cung nhau ")
else :
    print(" khong phai 2 so nguyen to cung nhau ")
# tim phan tu nghich dao bang o clit mo rong 
def nghich_dao(m, n):
    if ucl(m,n) != 1 :
        print(" khong phai so nguyen to cung nhau ")
        return
    else :
        if n == 0 :
            return m, 1, 0
        else :
            ucl, m1, n1 = ucl(n,m%n)
            m= n1
            n= m1 - (m//n)*n1
            return ucl, m, n


