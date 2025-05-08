import random

# Ước chung lớn nhất
def GCD(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Sinh khóa bí mật k sao cho GCD(k, q) = 1
def gen_key(q):
    key = random.randint(2, q - 2)  # Đảm bảo nằm trong (1, q-1)
    while GCD(q, key) != 1:
        key = random.randint(2, q - 2)
    return key

# Tính lũy thừa modulo: a^b mod n
def binary(a, b, n):
    f = 1
    a = a % n
    b_bin = bin(b)[2:]
    for bit in b_bin:
        f = (f * f) % n
        if bit == '1':
            f = (f * a) % n
    return f

# Mã hóa ElGamal
def encrypt_ELGAMAL(message, q, h, g):
    en_cry = []
    k = gen_key(q)
    s = binary(h, k, q)
    p = binary(g, k, q)
    print("g^k used :", p)
    print("g^ak used :", s)
    for char in message:
        en_cry.append(s * ord(char))
    return en_cry, p

# Giải mã ElGamal
def decrypt_ELGAMAL(en_cry, p, key, q):
    de_cry = []
    h = binary(p, key, q)
    for val in en_cry:
        de_cry.append(chr(int(val // h)))
    return ''.join(de_cry)

# Chương trình chính
def main():
    message = input("Nhập thông điệp: ")
    print("Thông điệp ban đầu:", message)

    q = 104729  # số nguyên tố lớn
    g = 2       # phần tử sinh
    key = gen_key(q)  # khóa riêng a
    h = binary(g, key, q)  # h = g^a mod q

    print(f"Khóa riêng: {key}")
    print(f"Khóa công khai (q, g, h): ({q}, {g}, {h})")

    en_cry, p = encrypt_ELGAMAL(message, q, h, g)
    print("Mã hóa:", en_cry)

    de_cry = decrypt_ELGAMAL(en_cry, p, key, q)
    print("Giải mã:", de_cry)

if __name__ == "__main__":
    main()
