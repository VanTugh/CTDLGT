# thuat toan tim uoc so chung lon nhat su dung euclit
def ucl(a , b) :
    while b:
        a , b = b, a%b
    return a
a= int(input(" nhap a de : "))
b= int(input(" nhap b de : "))
print(" uoc so chung lon nhat cua : ",str(a)," va ",str(b) ," la : " + str(ucl(a,b)))
if ucl(a,b) == 1 :
    print(" day la 2 so nguyen to cung nhau ")
else :
    print(" khong phai 2 so nguyen to cung nhau ")
# tim phan tu nghich dao bang o clit mo rong 
def nghich_dao(m, n):
    if ucl(m, n) != 1:
        print("Không phải số nguyên tố cùng nhau")
        return None

    def extended_gcd(a, b):
        if b == 0:
            return a, 1, 0
        else:
            gcd, x1, y1 = extended_gcd(b, a % b)
            x = y1
            y = x1 - (a // b) * y1
            return gcd, x, y

    gcd, x, y = extended_gcd(m, n)
    return x % n  # lấy mod n để đảm bảo nghịch đảo dương


m=int(input(" nhap vao m : "))
n=int(input(" nhap vao n : "))
print(str(nghich_dao(m,n)) + " la nghich dao cua "+str(m) + " va " +str(n) )


