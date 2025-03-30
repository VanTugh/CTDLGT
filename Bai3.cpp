#include <iostream>

using namespace std;

// Hàm tìm kiếm tuần tự cải tiến
int timKiemCaiTien(int arr[], int n, int k) {
    arr[n] = k; // Thêm lính canh vào cuối mảng
    int i = 0;
    
    while (arr[i] != k) { // Không cần kiểm tra i < n
        i++;
    }

    // Nếu vị trí tìm thấy là n (vị trí lính canh), nghĩa là không có trong mảng
    return (i == n) ? -1 : i;
}

int main() {
    int n, k;

    // Nhập số lượng phần tử
    cout << "Nhap so luong phan tu n (0 < n < 100): ";
    cin >> n;

    if (n <= 0 || n >= 100) {
        cout << "Gia tri n khong hop le!" << endl;
        return 1;
    }

    int arr[n + 1]; // Tạo mảng lớn hơn 1 phần tử để chứa lính canh

    // Nhập mảng
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Nhập số cần tìm
    cout << "Nhap so nguyen k: ";
    cin >> k;

    // Tìm kiếm
    int viTri = timKiemCaiTien(arr, n, k);

    // Kết quả
    if (viTri != -1) {
        cout << "So " << k << " xuat hien o vi tri: " << viTri << endl;
    } else {
        cout << "So " << k << " khong co trong day." << endl;
    }

    return 0;
}
