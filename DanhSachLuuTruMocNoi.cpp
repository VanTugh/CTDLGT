#include <iostream>
#include <iomanip>
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
void inTieuDe() {
    cout 
         << setw(10) << "Ma SV"
         << setw(20) << "Ho ten"
         << setw(20) << "Nam sinh"
         << setw(12) << "Diem TK"
         << endl;
}
void duyet_danhsach(TRO L) {
    if (eMpty(L)) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    inTieuDe();
    TRO Q = L;
    while (Q != NULL) {
        cout
        << setw(10) << Q->sv.maSV
        << setw(20) << Q->sv.hoTen
        << setw(20) << Q->sv.namSinh
        << setw(12) << fixed << setprecision(2) << Q->sv.diemTK
        << endl;
   Q = Q->next;
}
cout << endl;
}

TRO search(TRO L) {
    TRO Q = L;
    int maSV;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maSV;
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
void aDD(TRO &L)
{
    int n;
    cout<<" nhap vao so luong sinh vien : ";
    cin>>n;
    TRO last = NULL;
    for(int i=0;i<n;i++)
    {
        cout<<" nhap vao sinh vien thu "<<i+1<<" : "<<endl;
        TRO Q = new Node;
        SinhVien sv;
        nhap_Sinh_Vien(sv);
        Q->sv=sv;
        Q->next = NULL;
        
        if (L == NULL) {
            // Danh sách rỗng, node mới là đầu danh sách
            L = Q;
        } else {
            // Thêm vào cuối danh sách
            last->next = Q;
        }
        last = Q; // Cập nhật con trỏ last
        cout << "Da them sinh vien thanh cong!\n";
    }
}
// chen vao bat ky
void iNsert(TRO &L)
{
 cout<<" nhap vao ma sinh vien truoc "<<endl;
 TRO Q = search(L);
 if(Q != NULL)
 { 
        cout<<" da tim thay "<<endl;
        TRO P = new Node;
        SinhVien svmoi;
        cout << "Nhap thong tin sinh vien can chen:\n";
        nhap_Sinh_Vien(svmoi);
        
        P->sv = svmoi;  // Sửa lỗi ở đây
        P->next = Q->next;
        Q->next = P;
        
        cout << "Da them sinh vien thanh cong  "<< endl;
    } else {
        cout << "Khong tim thay sinh vien " << endl;
    }
 }
// xoa phan tu dau tien
void first_delete(TRO &L)
{
    TRO Q;
    Q=L;
    L=L->next;
    delete Q;
}
// xoa theo maSV
void after_Delete(TRO &L, TRO M) {
    if (M == NULL) {
        cout << "Loi: Nut M khong ton tai!" << endl;
        return;
    }
    
    if (M->next == NULL) {
        cout << "Loi: Khong co nut nao sau nut M!" << endl;
        return;
    }
    
    TRO Q = M->next;
    M->next = Q->next;
    delete Q;
    cout << "Da xoa nut thanh cong!" << endl;
}
void delete_by_maSV(TRO &L, int maSV)
{
    if(L==NULL)
    return;
    if(L->sv.maSV== maSV)
    {
        first_delete(L);
        return;
    }
    TRO M = L;
    while(M->next != NULL && M->next->sv.maSV != maSV)
    {
       M= M->next;
    }
    if(M->next!=NULL)
    {
        after_Delete(L, M); // Sử dụng hàm after_Delete sau khi đã tìm được M
    }
}
int main() {
    TRO L;
    creat(L);

    // Thêm sinh viên
   /*SinhVien sv1 = {101, "Nguyen Van A", 2002, 3.5};
    themSinhVien(L, sv1);
    SinhVien sv2 = {102, "Le Thi B", 2001, 3.8};
    themSinhVien(L, sv2);
    */
    aDD(L);
    iNsert(L);
    // Hiển thị danh sách
    cout << "Danh sach sinh vien:\n";
    duyet_danhsach(L);
    
    // Tìm kiếm sinh viên
    first_delete(L);
    cout << "Danh sach sinh vien sau khi xoa :\n";
    duyet_danhsach(L);
    TRO ketQua = search(L);
    if (ketQua != NULL) {
        cout << "Tim thay: " << ketQua->sv.hoTen << endl;
    } else {
        cout << "Khong tim thay sinh vien!" << endl;
    }

    return 0;
}

