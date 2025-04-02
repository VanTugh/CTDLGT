#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
# define MAX 6
struct SinhVien{
    int maSV;
    string hoTen;
    float gPA;
};
struct List {
    int count;
    SinhVien sv[MAX];
};

// Tạo danh sách rỗng
void creat(List &L) {
    L.count = -1;
}

// Kiểm tra danh sách rỗng
int check_empty(List L) {
    return (L.count == -1);
}

// Kiểm tra danh sách đầy
int check_full(List L) {
    return (L.count == MAX - 1);
}
// ham nhap 
void nhap(SinhVien &sv) {
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();  // Xóa ký tự xuống dòng còn sót lại

    cout << "Nhap ho ten sinh vien: ";
    getline(cin, sv.hoTen);  // Bây giờ getline() sẽ hoạt động đúng

    cout << "Nhap GPA sinh vien: ";
    cin >> sv.gPA;
}

void nhapList(List &L) {
    int n;
    cout << "Nhap so sinh vien muon them: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (check_full(L)) {
            cout << "Danh sach da day! Khong the them sinh vien.\n";
            break;
        }
        SinhVien sv;
        nhap(sv);  // Nhập một sinh viên
        L.sv[++L.count] = sv;  // Thêm sinh viên vào danh sách
    }
}
// Hàm hiển thị tiêu đề
void hienThiTieuDe() {
    cout << setw(7) << "MaSV" << setw(25) << "Ho ten" << setw(10) << "GPA" << endl;
    cout << setw(7) << "-----" << setw(25) << "--------------------" << setw(10) << "---" << endl;
}

// Hàm hiển thị danh sách
void hienThi(List L) {
    if (check_empty(L)) {
        cout << "Danh sach rong!\n";
        return;
    }

    hienThiTieuDe();
    for (int i = 0; i <= L.count; i++) {
        cout << setw(7) << L.sv[i].maSV 
             << setw(25) << L.sv[i].hoTen 
             << setw(10) << L.sv[i].gPA << endl;
    }
}

// Hàm xóa sinh viên tại vị trí k
int rEmove(List &L, int k) {
    if (k <= L.count + 1 && k > 0) {
        for (int i = k - 1; i < L.count; i++) {
            L.sv[i] = L.sv[i + 1];  // Dịch phần tử về trước
        }
        L.count--;
        return 1;
    }
    return 0;
}

// Hàm chèn sinh viên vào vị trí k
int inSert(List &L, int k, SinhVien sv) {
    if (k <= L.count + 2 && k > 0 && !check_full(L)) {
        for (int i = L.count; i >= k - 1; i--) {
            L.sv[i + 1] = L.sv[i];
        }
        L.sv[k - 1] = sv;  
        L.count++;
        return 1;
    }
    return 0;
}
// thêm một phần tử vào cuối danh sách
int aDD_last_LiSt(List &L)
{
  if(check_full(L))
    return 0;
  else
  {
    L.count++;
    cout<<" them phan tu : "<<endl;
    SinhVien sv;
    nhap(sv);
    L.sv[L.count]= sv;
    return 1;
  }
}

int main() {
    List L;
    creat(L);

    // Thêm sinh viên vào danh sách
    // SinhVien sv1 = {101, "Nguyen Van A", 3.2};
    // SinhVien sv2 = {102, "Le Thi B", 3.6};
    // SinhVien sv3 = {103, "Tran Van C", 2.9};

    // inSert(L, 1, sv1);
    // inSert(L, 2, sv2);
    // inSert(L, 3, sv3);
nhapList(L);
aDD_last_LiSt(L);
cout << "Danh sach sau khi them:\n";
hienThi(L);
rEmove(L,2);
cout << "Danh sach sau khi them:\n";
    hienThi(L);

    return 0;
}
