
#include<iostream>
#include <iomanip>
#include <string>
using namespace std;
struct SinhVien{
string maSV;
string tensv;
int namSinh;
float diemTK;
};
struct Node{
    Node *next;
    SinhVien sv;
};
typedef Node*TRO;
TRO L;
void create(TRO &L)
{
    L=NULL;
}
int check_empty(TRO L)
{
    return (L==NULL);
}
void them_sinh_vien(SinhVien &sv)
{
    cout<<" nhap vao ma sinh vien :";
    cin>>ws;
    getline(cin,sv.maSV);
    cout<<" nhap ten sinh vien :";
    cin>>ws;
    getline(cin, sv.tensv);
    cout<<" nhap vao nam sinh :";
    cin>>sv.namSinh;
    cout<<" nhap vao diem tong ket :";
    cin>>sv.diemTK;
}
void chen_cuoi(TRO &L, SinhVien sv)
{
    TRO P= new Node;
    P->sv=sv;
    P->next=NULL;
    if(check_empty(L))
    {
        L=P;
    }
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
void tao_danh_sach(TRO &L)
{
    create(L);
    SinhVien sv;
    int n;
    cout<<" nhap vao so sinh vien muon them : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<" nhap vao sinh vien thu "<<i+1<<endl;
        them_sinh_vien(sv);
        chen_cuoi(L,sv);
    }
}
void inDL(TRO L)
{
    TRO Q;
    if(!check_empty(L))
    {
        cout<<setw(10)<<"ma sinh vien"
        <<setw(25)<<"ten sinh vien"
        <<setw(10)<<"nam sinh"
        <<setw(10)<<" diem tong ket"<<endl;
        Q=L;
        while(Q!=NULL)
        {
            cout<<setw(10)<<Q->sv.maSV
            <<setw(25)<<Q->sv.tensv
            <<setw(10)<<Q->sv.namSinh
            <<setw(10)<<Q->sv.diemTK<<endl;
            Q=Q->next;
        }
    }

}
TRO MAX_DIEM(TRO L)
{
    float MAX_DIEMM=L->sv.diemTK;
    TRO MAX_NODE=L;
    TRO DUYET=L->next;
    while(DUYET!=NULL)
    {
        if(DUYET->sv.diemTK>MAX_DIEMM)
        {
            MAX_DIEMM=DUYET->sv.diemTK;
            MAX_NODE=DUYET;
        }
        DUYET=DUYET->next;
    }
    return MAX_NODE;
}
void chen_truoc_MAX(TRO &L)
{
    TRO PRE=L;
    TRO CAN_TIM=MAX_DIEM(L);
    if(CAN_TIM==L)
    {
        TRO P= new Node;
        SinhVien svmoi;
        cout<<" nhap sinh vien can chen truoc MAX : "<<endl;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        P->next=L;
        L=P;
    }
    else
    {
        TRO P= new Node;
        SinhVien svmoi;
        cout<<" nhap sinh vien can chen truoc MAX : "<<endl;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        while(PRE->next!=NULL && PRE->next!=CAN_TIM)
        {
            PRE=PRE->next;
        }
        P->next=PRE->next;
        PRE->next=P;
}
}
void delete_MAX(TRO &L)
{
    TRO PRE=L;
    TRO MAX_DIEMM=MAX_DIEM(L);
    if(MAX_DIEMM==L)
    {
        TRO Q=L;
        L=L->next;
        delete Q;
    }
    else
    {
         while(PRE->next!=NULL && PRE->next!=MAX_DIEMM)
        {
            PRE=PRE->next;
        }
        PRE->next=MAX_DIEMM->next;
        delete MAX_DIEMM;
    }
}
void xoa_all_max(TRO &L)
{
    TRO PRE=NULL;
    TRO DUYET=L;
    float max_ct=MAX_DIEM(L)->sv.diemTK;
    while(DUYET!=NULL)
    {
        if(DUYET->sv.diemTK==max_ct)
        {
            if(DUYET==L)
            {
                L=DUYET->next;
                delete DUYET;
                DUYET=L;
            }
            else
            {
                PRE->next=DUYET->next;
                delete DUYET;
                DUYET=PRE->next;
            }
        }
        else
        {
            PRE=DUYET;
            DUYET=DUYET->next;
        }
    }
}
TRO vi_tri(TRO L, int k)
{
    int dem=1;
    TRO Q=L;
    while(Q!=NULL && dem<k)
    {
        Q=Q->next;
        dem++;
    }
    return  Q;
}
void chen_vao_vi_tri(TRO &L, int k)
{
    TRO P=new Node;
    P->sv.maSV = "003";
    P->sv.tensv = "Mai";
    P->sv.namSinh = 2005;
    P->sv.diemTK = 9.5;
    P->next = NULL;
    if(k<1)
    {
        cout<<" loi"<<endl;
        return;
    }
    if(k==1)
    {
        P->next=L;
        L=P;
    }
    TRO PRE=vi_tri(L,k-1);
    TRO Q=L;
    P->next=PRE->next;
    PRE->next=P;
}
void search_ten(TRO L)
{
    string ten;
    cout<<" nhap vao ten muon nhap :";
    cin.ignore();
    getline(cin,ten);
    TRO Q=L;
    bool found=false;
    while(Q!=NULL)
    {
        if(Q->sv.tensv.compare(ten)==0)
            {
                found=true;
                 cout<<setw(10)<<Q->sv.maSV
            <<setw(25)<<Q->sv.tensv
            <<setw(10)<<Q->sv.namSinh
            <<setw(10)<<Q->sv.diemTK<<endl;

            }
            Q=Q->next;
    }
    if(!found)
    {
        cout<<" khom tim thay"<<endl;
    }
}
void BB_Sort(TRO L)
{
   bool swapp;
    do
    {
        swapp=false;
        TRO Q=L;
        while(Q->next!=NULL)
        {
            if(Q->sv.diemTK>Q->next->sv.diemTK)
            {
                SinhVien temp= Q->sv;
                Q->sv=Q->next->sv;
                Q->next->sv=temp;
                swapp=true;
            }
            Q=Q->next;
        }

    }while(swapp);
}
void sap_chen(TRO &L)
{
    TRO SAP=NULL;
    TRO DUYET=L;
    while(DUYET!=NULL)
    {
        TRO Next=DUYET->next;
        if(SAP == NULL || DUYET->sv.diemTK<SAP->sv.diemTK )
        {
            DUYET->next=SAP;
            SAP=DUYET;
        }
        else
        {
            TRO TEMP=SAP;
            while(TEMP->next!=NULL && TEMP->next->sv.diemTK<DUYET->sv.diemTK)
            {
                TEMP=TEMP->next;
            }
            DUYET->next=TEMP->next;
            TEMP->next=DUYET;
        }
        DUYET=Next;
    }
    L=SAP;
}
int main()
{
    tao_danh_sach(L);
    cout<<" danh sach sau khi tao la :"<<endl;
    inDL(L);
    chen_truoc_MAX(L);
    cout<<" danh sach sau khi chen truoc max la :"<<endl;
    inDL(L);
    delete_MAX(L);
    cout<<" danh sach sau khi xoa   max la :"<<endl;
    inDL(L);
    xoa_all_max(L);
    cout<<" danh sach sau khi xoa tat ca max la :"<<endl;
    inDL(L);
    chen_vao_vi_tri(L,3);
    cout<<" danh sach sau khi chen vao vi tri thu 3 la :"<<endl;
    inDL(L);
    search_ten(L);
    //BB_Sort(L);
    sap_chen(L);
    cout<<" danh sach sau khi sap la :"<<endl;
    inDL(L);
    return 0;
}


































/*
#include <iostream>
#include <string>
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
        cout<<setw(10)<<" ma sinh vien"
        <<setw(10)<<"ten SV"
        <<setw(10)<<"nam Sinh"
        <<setw(10)<<"diem TK"<<endl;
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
    getline(cin,sv.maSV);
    cout<<" nhap vao ten sinh vien :";
    getline(cin,sv.tenSV);
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
void tao_danh_sach(TRO &L)
{
    creat(L);
    int n;
    cout<<" nhap vao so luong sinh vien muon them : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<" nhap vao sinh vien thu "<< i+ 1<<endl;
        Sinhvien svmoi;
        them_sinh_vien(svmoi);
        chen_cuoi(L,svmoi);

    }
}
TRO MAX_DIEM(TRO L)
{
    float MAX_DIEM=L->sv.diemTK;
    TRO MAX_NODE=L;
    TRO DUYET=L->next;
    while(DUYET!=NULL)
    {
        if(DUYET->sv.diemTK>MAX_DIEM)
        {
            MAX_DIEM=DUYET->sv.diemTK;
            MAX_NODE=DUYET;
        }
        DUYET=DUYET->next;
    }
    return MAX_NODE;
}
void chen_truoc_MAX(TRO &L)
{
    TRO MAX_NODE=MAX_DIEM(L);
    TRO PRE=L;
    if(MAX_NODE==L)
    {
        TRO P= new Node;
        Sinhvien svmoi;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        P->next=L;
        L=P;
    }
    else
    {
        TRO P= new Node;
        Sinhvien svmoi;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        while(PRE->next!=NULL && PRE->next!=MAX_NODE)
        {
            PRE=PRE->next;
        }
        P->next=PRE->next;
        PRE->next=P;
    }
}
void first_delete(TRO &L)
{
    TRO Q=L;
    L=L->next;
    delete Q;
}
void xoa_MAX(TRO &L)
{
    TRO MAX_NODE=MAX_DIEM(L);
    if(L==MAX_NODE)
    {
        TRO Q=L;
    L=L->next;
    delete Q;
    }
    else
    {
        TRO PRE=L;
        while(PRE->next!=NULL && PRE->next!=MAX_NODE)
        {
            PRE=PRE->next;
        }
        PRE->next=MAX_NODE->next;
        delete MAX_NODE;
    }
}
TRO vi_tri(TRO L, int k)
{
    int dem=1;
    TRO Q=L;
    while(Q!=NULL && dem<k)
    {
        Q=Q->next;
        dem++;
    }
    return Q;
}
void chen_vao_vi_tri(TRO &L, int k)
{
    TRO P= new Node;
    P->sv.maSV = "003";
    P->sv.tenSV = "Mai";
    P->sv.namSinh = 2005;
    P->sv.diemTK = 9.5;
    P->next = NULL;
    if(k<1)
    {
        cout<<" loi";
        return;
    }
    if(k==1)
    {
        P->next=L;
        L=P;
        return;
    }
    TRO PRE= vi_tri(L,k-1);
    P->next=PRE->next;
    PRE->next=P;

}
int dem_ten_Mai(TRO L)
{
    TRO Q=L;
    int dem=0;
    while(Q!=NULL)
    {
        if(Q->sv.tenSV.compare("Mai")==0)
        {
            dem++;
        }
        Q=Q->next;
    }
    return dem;
}
float diemTB(TRO L)
{
    int dem=0;
    float tong=0;
    TRO Q=L;
    while(Q!=NULL)
    {
        tong+=Q->sv.diemTK;
        dem++;
        Q=Q->next;
    }
    return tong/dem;
}
void sap_chon_giam_dan(TRO L)
{
    TRO I,J,MAX_NODE;
    for(I=L;I->next!=NULL;I=I->next)
    {
        MAX_NODE=I;
        for(J=I->next;J!=NULL;J=J->next)
        {
            if(J->sv.diemTK>MAX_NODE->sv.diemTK)
            {
                MAX_NODE=J;
            }
        }
        if(MAX_NODE!=I)
        {
            Sinhvien temp=I->sv;
            I->sv=MAX_NODE->sv;
            MAX_NODE->sv=temp;
        }
    }
}
void xoa_all_max(TRO &L)
{
   float MAX_DIEMM = MAX_DIEM(L)->sv.diemTK;
    TRO Pre = NULL;
    TRO DUYET = L;
    while (DUYET != NULL) {
        if (DUYET->sv.diemTK == MAX_DIEMM) {
            if (DUYET == L) {
                L = DUYET->next;
                delete DUYET;
                DUYET = L;
            } else {
                Pre->next = DUYET->next;
                delete DUYET;
                DUYET = Pre->next; // Move to the next node
            }
        } else {
            Pre = DUYET;
            DUYET = DUYET->next;
        }
    }

}
int main()
{
    tao_danh_sach(L);
    cout<<" danh sach la :"<<endl;
    inDS(L);
    chen_truoc_MAX(L);
    cout<<" danh sach sau khi chen la :"<<endl;
    inDS(L);
  //  xoa_MAX(L);
  //  cout<<" danh sach sau khi xoa max la :"<<endl;
  //  inDS(L);
    chen_vao_vi_tri(L,3);
    cout<<" danh sach sau khi chen vao vi tri thu 3 la :"<<endl;
    inDS(L);
    cout<<" co "<<dem_ten_Mai(L)<<endl;
    cout<<" trung binh cong "<<diemTB(L)<<endl;
    sap_chon_giam_dan(L);
    cout<<" danh sach sap giam :"<<endl;
    inDS(L);
    xoa_all_max(L);
    cout<<" danh sach sau khi xoa het max :"<<endl;
    inDS(L);
    return 0;
}
*/

