import random

# Hàm nhân lũy thừa nhị phân: (a^b) mod n
def binary(a, b, n):
    f = 1
    a = a % n
    b_bin = bin(b)[2:]  # chuyển b sang dạng nhị phân
    for bit in b_bin:
        f = (f * f) % n
        if bit == '1':
            f = (f * a) % n
    return f

# Hàm sinh khóa bí mật ngẫu nhiên: 1 <= X <= q - 2
def sinh_khoa_bi_mat(q):
    return random.randint(1, q - 2)

# Hàm chính thực hiện trao đổi khóa Diffie-Hellman
def main():
    # Thỏa thuận công khai giữa hai bên
    q = 23               # Số nguyên tố
    alpha = 9            # Căn nguyên thủy của q

    print("Giá trị công khai q =", q)
    print("Căn nguyên thủy alpha =", alpha)

    # A sinh khóa riêng và khóa công khai
    X_A = sinh_khoa_bi_mat(q)
    Y_A = binary(alpha, X_A, q)
    print("\nA chọn khóa riêng X_A =", X_A)
    print("Khóa công khai Y_A =", Y_A)

    # B sinh khóa riêng và khóa công khai
    X_B = sinh_khoa_bi_mat(q)
    Y_B = binary(alpha, X_B, q)
    print("\nB chọn khóa riêng X_B =", X_B)
    print("Khóa công khai Y_B =", Y_B)

    # Mỗi bên tính khóa chung
    K_A = binary(Y_B, X_A, q)
    K_B = binary(Y_A, X_B, q)

    print("\nKhóa chung (A tính):", K_A)
    print("Khóa chung (B tính):", K_B)

    # Kiểm tra kết quả
    if K_A == K_B:
        print("\n✅ Hai bên có cùng khóa bí mật!")
    else:
        print("\n❌ Khóa không khớp - có lỗi!")

if __name__ == "__main__":
    main()
