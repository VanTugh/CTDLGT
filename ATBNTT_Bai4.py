def mod_inverse(a, m):
    # tim nghich dao module 
    m0, x0, x1 = m, 0, 1
    while a>1 :
        q= a//m
        a,m= m, a%m
        x0,x1= x1-q*x0, x0
    return x1+m0 if x1<1 else x1

print(mod_inverse(6,11))
a, m = 6, 11
result = mod_inverse(a, m)
print(f"{a}^-1 mod {m} = {result}")