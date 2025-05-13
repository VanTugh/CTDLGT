# tinh luy thua module bang nhi phan: a^b mod n
def binary(a,b,n):
    f=1
    a= a % n
# doi b thanh nhi phan
    b_binary=bin(b)[2:]
    for bit in b_binary:
        f=(f*f)%n
        if bit =='1':
            f=(f*a)%n
    return f
# tinh nghich dao modulo bang euclit mo rong
# tim uoc chung lon nhat
def GCD(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def ex_clit(a,b):
    if GCD(a,b)!=1:
        return
    r0,r1=b,a
    x0,x1=0,1
    y0,y1=1,0
    while r1!=1:
        q=r0//r1
        r0,r1=r1, r0 %r1
        x0,x1=x1, x0-q*x1
        y0,y1=y1, y0-q*y1
    if x1<0:
        x1=x1+b
    return x1
#ham tao khoa
def generate_key():
    p=7919
    q=1009
    n=p*q
    phi=(p-1)*(q-1)
    e=0
    for e in range(2,phi):
        if GCD(e,phi)==1:
            break
    d=ex_clit(e,phi)
    return e,d,n
def RSA(m,e,n):
    return binary(m,e,n)
def DE_RSA(c,d,n):
    return binary(c,d,n)

if __name__ =="__main__":
    e,d,n=generate_key()
    print(f"khoa public (e,n)= ({e},{n})")
    print(f"khoa p (e,private)= ({d},{n})")
    M=123
    print(f"thong diep ban dau : {M}")
    C= RSA(M,e,n)
    print(f"ma hoa : {C}")
    D=DE_RSA(C,d,n)
    print(f"giai ma : {D}")














# def generateKey():
#     p=7919
#     q=1009
#     n=p*q
#     phi = (p-1)*(q-1)
# # chon e
#     e=0
#     for e in range(2,phi):
#         if GCD(e,phi)==1:
#             break
#     d=ex_clit(e,phi)
#     return e,d,n
# # ma hoa
# def encrypt_RSA(m,e,n):
#     return binary(m,e,n)
# # giai ma 
# def decrypt(c,d,n):
#     return binary(c,d,n)

# # main
# if __name__=="__main__":
#     e,d,n=generateKey()
# print(f"khoa public (e,n)= ({e},{n})")
# print(f"khoa p (e,private)= ({d},{n})")
# M=123
# print(f"thong diep ban dau : {M}")

# C= encrypt_RSA(M,e,n)
# print(f"ma hoa : {C}")
# D=decrypt(C,d,n)
# print(f"giai ma : {D}")
      