def binary(a,b,n) :
    f=1
    a = a % n
    b_bin=bin(b)[2:]
    for bit in b_bin :
        f=(f*f)%n
        if bit == '1':
            f= (f*a)%n
    return f
print(binary(2,3,6))