# de quy tinh n!
def de_quy_tinh_giai_thua(n) :
    if n==0 or n==1 :
     return 1
    
    return n*de_quy_tinh_giai_thua(n-1)
# nhap so
so= int(input(" nhap so de : "))
if so < 0 :
    print(" khong co giai thua cho so am ")
else :
    print(f"{so}! =", de_quy_tinh_giai_thua(so))
# bai 6
# Hàm lặp in ngược chuỗi
def reverse_string_iterative(s):
    return s[::-1]

# Hàm đệ qui in ngược chuỗi
def reverse_string_recursive(s):
    if len(s) == 0:
        return s
    return reverse_string_recursive(s[1:]) + s[0]

s = "PASCAL"
print("Iterative:", reverse_string_iterative(s))
print("Recursive:", reverse_string_recursive(s))

# bai 7 
# Hàm lặp đếm số chữ số
def count_digits_iterative(n):
    count = 0
    while n > 0:
        n = n // 10
        count += 1
    return count

# Hàm đệ qui đếm số chữ số
def count_digits_recursive(n):
    if n < 10:
        return 1
    return 1 + count_digits_recursive(n // 10)

num = int(input(" nhap so deee : "))
print("Iterative:", count_digits_iterative(num))
print("Recursive:", count_digits_recursive(num))