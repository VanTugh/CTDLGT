import numpy as np

# Chuyển từ chữ sang số: A=0,...,Z=25
def chuyen_chu_sang_so(c):
    return ord(c.upper()) - ord('A')

# Chuyển số về chữ
def chuyen_so_sang_chu(n):
    return chr(n % 26 + ord('A'))

# Mã hóa Hill
def ma_hoa_hill(text, K):
    if len(text) % 2 != 0:
        text += 'X'  # padding nếu độ dài lẻ
    
    ketqua = ''
    for i in range(0, len(text), 2):
        vec = [chuyen_chu_sang_so(text[i]), chuyen_chu_sang_so(text[i+1])]
        res = np.dot(K, vec) % 26
        ketqua += chuyen_so_sang_chu(res[0]) + chuyen_so_sang_chu(res[1])
    return ketqua

# Tìm ma trận nghịch đảo modulo 26
def nghich_dao_ma_tran(K):
    det = int(np.round(np.linalg.det(K)))  # Định thức
    det_mod = det % 26
    inv_det = None

    # Tìm nghịch đảo modulo của định thức
    for i in range(1, 26):
        if (det_mod * i) % 26 == 1:
            inv_det = i
            break
    if inv_det is None:
        raise ValueError("Ma trận không khả nghịch modulo 26")

    # Ma trận phụ hợp (adjugate)
    adj = np.array([[K[1][1], -K[0][1]], [-K[1][0], K[0][0]]])
    adj = adj % 26

    return (inv_det * adj) % 26

# Giải mã Hill
def giai_ma_hill(cipher, K):
    K_inv = nghich_dao_ma_tran(K)
    return ma_hoa_hill(cipher, K_inv)

# =======================
K = np.array([[3, 3], [2, 5]])
text = "HELP"

ma_hoa = ma_hoa_hill(text, K)
print("Mã hóa:", ma_hoa)

giai_ma = giai_ma_hill(ma_hoa, K)
print("Giải mã:", giai_ma)





# UCLN
import numpy as np
def UCL(a, b):
    while b:
        a, b = b, a % b
    return a

# Thuật toán Euclid mở rộng
def ex_clit(a, b):
    if UCL(a, b) != 1:
        return None
    r0, r1 = b, a
    x0, x1 = 0, 1
    while r1 != 0:
        q = r0 // r1
        r0, r1 = r1, r0 % r1
        x0, x1 = x1, x0 - q * x1
    if x0 < 0:
        x0 += b
    return x0

# Thuật toán a^b mod n (Binary Exponentiation)
def binary_T(a, b, n):
    f = 1
    a = a % n
    b_bin = bin(b)[2:]
    for bit in b_bin:
        f = (f * f) % n
        if bit == '1':
            f = (f * a) % n
    return f

# Caesar Cipher
def chuyen_ki_tu_thanh_so(c):
    return ord(c.upper()) - ord('A')

def chuyen_so_thanh_ki_tu(c, is_upper):
    base = ord('A') if is_upper else ord('a')
    return chr((c % 26) + base)

def ma_hoa_Caesar(text, k):
    ketqua = ""
    for c in text:
        if c.isalpha():
            pos = chuyen_ki_tu_thanh_so(c)
            new_pos = (k + pos) % 26
            ketqua += chuyen_so_thanh_ki_tu(new_pos, c.isupper())
        else:
            ketqua += c
    return ketqua

def giai_ma_Caesar(text, k):
    return ma_hoa_Caesar(text, -k)

# Affine Cipher
def chuyen_AFF(c):
    return ord(c.upper()) - ord('A')

def chuyen_2_AFF(n, is_upper):
    base = ord('A') if is_upper else ord('a')
    return chr((n % 26) + base)

def ma_hoa_AFFINE(text, a, b):
    ketqua = ""
    for c in text:
        if c.isalpha():
            pos = chuyen_AFF(c)
            new_pos = (a * pos + b) % 26
            ketqua += chuyen_2_AFF(new_pos, c.isupper())
        else:
            ketqua += c
    return ketqua

def giai_ma_AFFINE(text, a, b):
    ketqua = ""
    a_inv = ex_clit(a, 26)
    if a_inv is None:
        return "Không tồn tại nghịch đảo modular"
    for c in text:
        if c.isalpha():
            pos = chuyen_AFF(c)
            new_pos = (a_inv * (pos - b)) % 26
            ketqua += chuyen_2_AFF(new_pos, c.isupper())
        else:
            ketqua += c
    return ketqua

# ==========================
# Test với text = "TUGH"
text = "TUGH"
print("==== Caesar Cipher ====")
caesar_mahoa = ma_hoa_Caesar(text, 3)
print("Mã hóa Caesar:", caesar_mahoa)
print("Giải mã Caesar:", giai_ma_Caesar(caesar_mahoa, 3))

print("\n==== Affine Cipher ====")
a, b = 5, 8  # a phải nguyên tố cùng 26
aff_mahoa = ma_hoa_AFFINE(text, a, b)
print("Mã hóa Affine:", aff_mahoa)
print("Giải mã Affine:", giai_ma_AFFINE(aff_mahoa, a, b))
def nghich_dao_ma_tran(K):
    det = int(round(np.linalg.det(K)))