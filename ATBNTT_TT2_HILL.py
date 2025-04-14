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
