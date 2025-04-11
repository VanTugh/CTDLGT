#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct SinhVien
{
    string maSV;
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

void creat(TRO &L)
{
    L = NULL;
}

int check_empty(TRO L)
{
    return L == NULL;
}
void nhap_sinh_vien(SinhVien &sv)
{
    cout<<" nhap ma sinh vien : ";
    getline(cin,sv.maSV);
    if(sv.maSV.empty())
    return;
    cout<<" nhap vao ho ten sinh vien : ";
    getline(cin,sv.hoTen);
    cout<<" nhap vao nam sinh : ";
    cin>>sv.namSinh;
    cout<<" nhap vao diem tong ket : ";
    cin>>sv.diemTK;
    cin.ignore();
}
// chen sinh vien 
void chen_cuoi(TRO &L, SinhVien sv)
{
  TRO P = new Node;
  P->sv=sv;
  P->next=NULL;
  if(check_empty(L))
   L=P;
  else
  {
    TRO Q=L;
    while(Q->next!=NULL)
    {
        Q=Q->next;
    }
    Q->next=P;
  }
}
// viec nhap ket thuc khi ma sinh vien la rong 
void nhap_dsach(TRO &L)
{
    creat(L);
    SinhVien sv;
    while(true)
    {
        nhap_sinh_vien(sv);
        if(sv.maSV.empty())
         break;
        chen_cuoi(L,sv);
    }
}
void hienThiDanhSach(TRO L) {
    cout << setw(10) << "MaSV" << setw(25) << "Ho ten"
         << setw(10) << "Nam sinh" << setw(10) << "DiemTK" << endl;
    while (L != NULL) {
        cout << setw(10) << L->sv.maSV << setw(25) << L->sv.hoTen
             << setw(10) << L->sv.namSinh << setw(10) << L->sv.diemTK << endl;
        L = L->next;
    }
}
// hien thi sinh vien sinh nam 1998
void hien_thi_sinh_vien_1998(TRO L )
{
     bool found= false;
    while(L != NULL)
    {
       
        if(L->sv.namSinh==1998)
        {
            if(!found)
            {
                cout<<" da tim thay "<<endl;
                cout << setw(10) << "MaSV" << setw(25) << "Ho ten"
         << setw(10) << "Nam sinh" << setw(10) << "DiemTK" << endl;
            }
            found=true;
             cout << setw(10) << L->sv.maSV << setw(25) << L->sv.hoTen
             << setw(10) << L->sv.namSinh << setw(10) << L->sv.diemTK << endl;

        }
        L = L->next;
    }
    if(!found)
    cout<<" khong tim thay ";
}
void fisrt_delete(TRO &L)
{
    TRO Q=L;
    L=L->next;
    delete Q;
}

int main()
{
    TRO L;
    SinhVien sv;
    nhap_dsach(L);
    cout<<" danh sach la : "<<endl;
    hienThiDanhSach(L);
    hien_thi_sinh_vien_1998(L);
    fisrt_delete(L);
    cout<<" danh sach sau khi xoa la : "<<endl;
    hienThiDanhSach(L);
}