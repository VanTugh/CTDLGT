def chuyen_ki_tu(c):
    if c.isupper():
        return ord(c) - ord('A')
    else:
        return ord(c) - ord('a')

def ki_tu_thanh_vi_tri(pos, is_upper):
    base = ord('A') if is_upper else ord('a')
    return chr((pos % 26) + base)

def ma_hoa_caesar(text, k):
    ketqua = ""
    for c in text:
        if c.isalpha():
            pos = chuyen_ki_tu(c)
            new_pos = (pos + k) % 26
            ketqua += ki_tu_thanh_vi_tri(new_pos, c.isupper())
        else:
            ketqua += c
    return ketqua

def giai_ma(text, key):  # ✅ dùng 'key' đúng cách
    return ma_hoa_caesar(text, -key)

# Thử nghiệm
raw = "TRALALERO TRALALA"
k = 4
print("Mã hóa:  ", ma_hoa_caesar(raw, k))
print("Giải mã: ", giai_ma(ma_hoa_caesar(raw, k), k))
