#include <iostream>

using namespace std;


struct SinhVien {
    int maSV;
    string hoTen;
    int namSinh;
    float diemTK;
};
struct Node
{
    SinhVien sv;
    Node *next;

};
typedef Node *TRO;
TRO L;
// khoi tao danh sac rong
void creat(TRO &L)
{
    L=NULL;
}
int eMpty(TRO L)
{
    return L == NULL;
}
void nhap_Sinh_Vien(SinhVien &sv)
{
    cout<<" nhap vao ma sinh vien :";
    cin>>sv.maSV;
    cin.ignore();
    cout<<" nhap vao ho ten : ";
    getline(cin,sv.hoTen);
    cout << "Nhap nam sinh: ";
    cin >> sv.namSinh;
    cout << "Nhap diem tong ket: ";
    cin >> sv.diemTK;

}
void duyet_danhsach(TRO L) {
    if (eMpty(L)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    TRO Q = L;
    while (Q != NULL) {
        cout << "Ma SV: " << Q->sv.maSV << ", Ho ten: " << Q->sv.hoTen
             << ", Nam sinh: " << Q->sv.namSinh << ", Diem TK: " << Q->sv.diemTK << endl;
        Q = Q->next;
    }
}

TRO search(TRO L, int maSV) {
    TRO Q = L;
    while (Q != NULL) {
        if (Q->sv.maSV == maSV) {
            return Q; 
        }
        Q = Q->next;
    }
    return NULL;
}
void themSinhVien(TRO &L, SinhVien sv) {
    TRO Q = new Node;
    Q->sv = sv;
    Q->next = L;
    L = Q;
}


int main() {
    TRO L;
    creat(L);

    // Thêm sinh viên
    SinhVien sv1 = {101, "Nguyen Van A", 2002, 3.5};
    themSinhVien(L, sv1);
    SinhVien sv2 = {102, "Le Thi B", 2001, 3.8};
    themSinhVien(L, sv2);

    // Hiển thị danh sách
    cout << "Danh sach sinh vien:\n";
    duyet_danhsach(L);

    // Tìm kiếm sinh viên
    int maTim;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maTim;
    TRO ketQua = search(L, maTim);
    if (ketQua != NULL) {
        cout << "Tim thay: " << ketQua->sv.hoTen << endl;
    } else {
        cout << "Khong tim thay sinh vien!" << endl;
    }

    return 0;
}

