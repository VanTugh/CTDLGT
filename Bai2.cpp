#include <iostream>

using namespace std;

// Hàm tìm giá trị lớn nhất (Chia để trị)
int FindMax(int Arr[], int left, int right) {
    if (left == right)  // Trường hợp chỉ có một phần tử
        return Arr[left];

    int mid = (left + right) / 2;
    int maxLeft = FindMax(Arr, left, mid);
    int maxRight = FindMax(Arr, mid + 1, right);

    return (maxLeft > maxRight) ? maxLeft : maxRight;
}

// Hàm tính tổng của dãy số (Chia để trị)
int tinh_tong(int A[], int left, int right) {
    if (left == right)  // Nếu chỉ có một phần tử
        return A[left];

    int mid = (left + right) / 2;
    int sumLeft = tinh_tong(A, left, mid);
    int sumRight = tinh_tong(A, mid + 1, right);

    return sumLeft + sumRight;
}

int main() {
    // Tìm max trong mảng có sẵn
    int Arr[] = {3, 2, 4, 5, 6, 7, 89, 10};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    cout << "Gia tri lon nhat trong Arr: " << FindMax(Arr, 0, n - 1) << endl;

    // Nhập số lượng phần tử từ người dùng
    int num;
    cout << "Nhap so luong phan tu: ";
    cin >> num;

    // Kiểm tra nếu num <= 0
    if (num <= 0) {
        cout << "So luong phan tu khong hop le!" << endl;
        return 1;
    }

    // Cấp phát mảng động
    int* a = new int[num];

    cout << "Nhap cac phan tu: " << endl;
    for (int i = 0; i < num; i++)
        cin >> a[i];

    // Gọi hàm tính tổng
    int tong = tinh_tong(a, 0, num - 1);
    cout << "Tong cua day so la: " << tong << endl;

    // Giải phóng bộ nhớ động
    delete[] a;

    return 0;
}
