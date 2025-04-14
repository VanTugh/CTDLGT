# Tìm nghịch đảo modulo
def nghich_dao_modulo(a, m):
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    raise ValueError("a và m không nguyên tố cùng nhau")

# Chuyển chữ sang số
def chuyen_chu_sang_so(c):
    base = ord('A') if c.isupper() else ord('a')
    return ord(c) - base

# Chuyển số sang chữ
def chuyen_so_sang_chu(n, is_upper):
    base = ord('A') if is_upper else ord('a')
    return chr((n % 26) + base)

# Hàm mã hóa affine
def ma_hoa_affine(text, a, b):
    ketqua = ""
    for c in text:
        if c.isalpha():
            pos = chuyen_chu_sang_so(c)
            new_pos = (a * pos + b) % 26
            ketqua += chuyen_so_sang_chu(new_pos, c.isupper())
        else:
            ketqua += c
    return ketqua  # ✅ đưa ra ngoài vòng for
def giai_ma(text, a,b):
    ketqua = ""
    a_int= nghich_dao_modulo(a,26)
    for c in text:
        if c.isupper():
            pos = chuyen_chu_sang_so(c)
            new_pos= (a_int*(pos-b))%26
            ketqua+=chuyen_so_sang_chu(new_pos, c.isupper())
        else:
            ketqua+=c
    return ketqua
# Thử nghiệm
text = "VAGH TUGH"
a = 3
b = 4
print("Mã hóa: ", ma_hoa_affine(text, a, b))
print("giai ma : ",giai_ma(ma_hoa_affine(text, a, b),a,b))
