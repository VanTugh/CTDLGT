#include <iostream>
#include <iomanip>
using namespace std;
struct Sinhvien{
string maSV;
string tenSV;
int namSinh;
float diemTK;
};

struct Node{
    Sinhvien sv;
    Node *next;
};
typedef Node* TRO;
TRO L;
void creat(TRO &L)
{
    L=NULL;
}
int check_empty(TRO L)
{
    return (L==NULL);
}
void inDS(TRO L)
{

    TRO Q;
    if(!check_empty(L))
    {
        cout<<setw(10)<<"maSV"
            <<setw(10)<<"tenSV"
            <<setw(10)<<"namSinh"
            <<setw(10)<<"diemTK"<<endl;
        Q=L;
        while(Q!=NULL)
        {
            cout<<setw(10)<<Q->sv.maSV
            <<setw(10)<<Q->sv.tenSV
            <<setw(10)<<Q->sv.namSinh
            <<setw(10)<<Q->sv.diemTK<<endl;
            Q=Q->next;
        }
    }
}
void them_sinh_vien(Sinhvien &sv)
{
    cout<<" nhap vao ma sinh vien :";
    cin>>ws;
    getline(cin, sv.maSV);
    cout<<" nhap ten sinh vien :";
    getline(cin, sv.tenSV);
    cout<<" nhap vao nam sinh :";
    cin>>sv.namSinh;
    cout<<" nhap vao diem tong ket :";
    cin>>sv.diemTK;
}
void chen_cuoi(TRO &L, Sinhvien sv)
{
 TRO P= new Node;
 P->sv=sv;
 P->next=NULL;
 if(check_empty(L))
 {
     L=P;
 }
 else{
    TRO Q=L;
    while(Q->next!=NULL)
    {
        Q=Q->next;
    }
    Q->next=P;
 }
}
void tao_danh_sach(TRO &L)
{
    creat(L);
    Sinhvien sv;
    int n;
    cout<<" nhap so sinh vien muon them :";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<" nhap sinh vien thu "<<i+1<<endl;
        them_sinh_vien(sv);
        chen_cuoi(L,sv);
    }
}
// tim dia chi sinh vien co diem tb lon nhat
TRO tim_sinh_vien_max(TRO L)
{
    float Max_diem= L->sv.diemTK;
    TRO Q_MAX = L;
    TRO P= L->next;
    while(P!=NULL)
    {
        if(P->sv.diemTK>Max_diem)
        {
            Max_diem=P->sv.diemTK;
            Q_MAX=P;
        }
        P=P->next;
    }
    return Q_MAX;

}
void chen_truoc_MAX(TRO &L)
{
    TRO max_tim=tim_sinh_vien_max(L);
     TRO pre= L;
      while(pre->next!=NULL && pre->next != max_tim)
        {
            pre=pre->next;
        }
        TRO P = new Node;
        Sinhvien sv_moi;
        them_sinh_vien(sv_moi);
        P->sv=sv_moi;
        P->next=pre->next;
        pre->next=P;

}
void fisrt_delete(TRO &L)
{
    TRO Q=L;
    L=L->next;
    delete Q;
}
void xoa_MAX(TRO &L)
{
    TRO max_tim=tim_sinh_vien_max(L);
    if(L== max_tim)
    {
         fisrt_delete(L);
         return;
    }

    else
    {
        TRO pre= L;
        while(pre->next!=NULL && pre->next != max_tim)
        {
            pre=pre->next;
        }
            pre->next=max_tim->next;
            delete max_tim;
    }
}
void chen_dau(TRO &L)
{
    TRO P= new Node;
    Sinhvien sv_moi;
    cout<<" nhap sinh vien moi : "<<endl;
    them_sinh_vien(sv_moi);
    P->sv=sv_moi;
    P->next=L;
    L=P;
}
TRO vi_tri(TRO L, int k)
{
    TRO Q=L;
    int dem = 1;
    while(dem < k-1)
    {
        Q= Q->next;
        dem++;
    }
    return Q;
}
void chen_vao_vi_tri(TRO &L, int k)
{
    TRO P = new Node;
    P->sv.maSV="003";
    P->sv.tenSV="MAI";
    P->sv.namSinh=2005;
    P->sv.maSV=9.5;
    P->next=NULL;
    TRO Q= vi_tri(L,k);
    P->next= Q->next;
    Q->next=P;
    if (k == 1)  // Nếu chèn ở đầu danh sách
    {
        P->next = L;
        L = P;
    }
    else
    {
        TRO Q = vi_tri(L, k - 1);  // Tìm node đứng trước vị trí k

        if (Q != NULL)  // Nếu tìm thấy node đứng trước
        {
            P->next = Q->next;
            Q->next = P;
        }
        else
        {
            // Nếu k lớn hơn số lượng sinh viên trong danh sách, thêm vào cuối
            chen_cuoi(L, P->sv);
        }
    }


}
// dem xem co bao nhieu sinh vien ten Lan
int dem_ten(TRO L)
{
    TRO Q=L;
    int dem=0;
    while(Q!=NULL)
    {
        if(Q->sv.tenSV=="Lan")
        {
            dem++;
        }
        Q=Q->next;
    }
    return dem;
}
// tinh diem trung binh tat ca sinh vien
float Tinh_TB(TRO L)
{
    float diem=0;
    TRO Q=L;
    int dem=0;
    while(Q!=NULL)
    {
        diem+=Q->sv.diemTK;
        Q=Q->next;
        dem++;
    }
    return diem/dem;

}
//  sap xep diem theo chieu giam dan bang phuong phap chon
void sap_chon(TRO L)
{
    if (L == NULL || L->next == NULL) // Handle empty or single-node list
        return;

    TRO I, J, MAX_NODE;
    for (I = L; I->next != NULL; I = I->next)
    {
        MAX_NODE = I; // Assume current node has the maximum diemTK
        for (J = I->next; J != NULL; J = J->next)
        {
            if (J->sv.diemTK > MAX_NODE->sv.diemTK) // Find node with larger diemTK
            {
                MAX_NODE = J;
            }
        }
        if (MAX_NODE != I)
        {
            Sinhvien temp = I->sv;
            I->sv = MAX_NODE->sv;
            MAX_NODE->sv = temp;
        }
    }
}
int main()
{
  Sinhvien sv;
  tao_danh_sach(L);
  cout<<" danh sach la : "<<endl;
  inDS(L);

  chen_dau(L);
  xoa_MAX(L);
  cout<<" danh sach la : "<<endl;
  inDS(L);
  chen_truoc_MAX(L);
  cout<<" danh sach la : "<<endl;
  inDS(L);
  cout<<" so sinh vien ten Lan la :"<<dem_ten(L)<<endl;
  cout<<" diem trung binh cua tat ca sinh vien la :"<<Tinh_TB(L)<<endl;
  sap_chon(L);
  cout<<" danh sach la : "<<endl;
  inDS(L);
    return 0;
}
