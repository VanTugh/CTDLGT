#include <iostream>
#include <iomanip>
#include <string>
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
    TRO Q=L;

        if(!check_empty(L))
        {
            cout<<setw(10)<<"maSV"
            <<setw(10)<<"tenSV"
            <<setw(10)<<"namSinh"
            <<setw(10)<<"diemTK"<<endl;
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
    cout<<" nhap so sinh vien muon them :";
    cin>>n;
    Sinhvien sv_moi;
    for(int i=0;i<n;i++)
    {
        cout<<" them sinh vien thu "<<i+1<<endl;
        them_sinh_vien(sv_moi);
        chen_cuoi(L,sv_moi);
    }
}
TRO tim_MAX_DIEM(TRO L)
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
    TRO MAX_NODE=tim_MAX_DIEM(L);
    if(MAX_NODE==L)
    {
        TRO P= new Node;
        Sinhvien svmoi;
        cout<<" nhap vao sinh vien muon chen truoc max :"<<endl;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        P->next=L;
        L=P;
    }
    else
    {
        TRO PRE=L;
    while(PRE->next!=NULL && PRE->next!=MAX_NODE)
    {
        PRE=PRE->next;
    }
    TRO P= new Node;
        Sinhvien svmoi;
        cout<<" nhap vao sinh vien muon chen truoc max :"<<endl;
        them_sinh_vien(svmoi);
        P->sv=svmoi;
        P->next=PRE->next;
        PRE->next=P;
    }

}
void fisrt_delete(TRO &L)
{
    TRO Q=L;
    L=L->next;
    delete Q;
}
void xoa_MAX(TRO &L)
{
    TRO PRE=L;
    TRO MAX_NODE=tim_MAX_DIEM(L);
    if(MAX_NODE==L)
    {
        fisrt_delete(L);
        return;
    }
    else{

        while(PRE->next!=NULL && PRE->next!=MAX_NODE)
    {
        PRE=PRE->next;
    }
        PRE->next=MAX_NODE->next;
        delete MAX_NODE;
    }


}
TRO vi_tri(TRO L , int k)
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
void them_vao_vi_tri(TRO &L, int k)
{

    TRO P=new Node;
    P->sv.tenSV="XUAN MAI";
    P->sv.maSV="7";
    P->sv.namSinh=2005;
    P->sv.diemTK=9.5;
    if(k==1)
    {
        P->next=L;
        L=P;
    }
    else
    {
        TRO PRE=vi_tri(L,k-1);
        P->next=PRE->next;
        PRE->next=P;

    }
}
void xoa_theo_vi_tri(TRO &L, int k)
{
    if(k==1)
    {
        fisrt_delete(L);
        return;
    }
    else
    {

        TRO PRE=vi_tri(L,k-1);
        TRO Q=PRE->next;
        PRE->next=Q->next;
        delete Q;
    }
}
void delete_all_MAX(TRO &L)
{
    TRO PRE=NULL;
    TRO DUYET=L;
    float MAX_DIEM_CT=tim_MAX_DIEM(L)->sv.diemTK;
    while(DUYET!=NULL)
    {
        if(DUYET->sv.diemTK==MAX_DIEM_CT)
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
void tim_ten(TRO L)
{
    TRO Q=L;
    string ten;
    cout<<" nhap ten can tim :";
    getline(cin,ten);
    bool found=false;
    while(Q!=NULL)
    {
        if(Q->sv.tenSV.compare(ten)==0)
        {
            cout<<setw(10)<<Q->sv.maSV
            <<setw(10)<<Q->sv.tenSV
            <<setw(10)<<Q->sv.namSinh
            <<setw(10)<<Q->sv.diemTK<<endl;
            found=true;
        }
        Q=Q->next;

    }
    if(!found)
    {
        cout<<" k tim thay "<<endl;
    }
}
void sap_chon(TRO L)
{
    TRO i, j, mX;
    for(i=L;i->next!=NULL;i=i->next)
    {
        mX=i;
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(j->sv.diemTK<mX->sv.diemTK)
            {
                mX=j;
            }
        }
        if(mX!=i)
        {
            Sinhvien temp=i->sv;
            i->sv=mX->sv;
            mX->sv=temp;
        }
    }
}
void bb_sort(TRO L)
{
    if (L == NULL || L->next == NULL) return;

    bool swapp;
    do {
        swapp = false;
        TRO Q = L;
        while (Q->next != NULL)
        {
            if (Q->sv.diemTK > Q->next->sv.diemTK)
            {

                Sinhvien temp = Q->sv;
                Q->sv = Q->next->sv;
                Q->next->sv = temp;
                swapp = true;
            }
            Q = Q->next;
        }
    } while (swapp);
}
void sap_chen(TRO L)
{
    TRO P= new Node;
    Sinhvien sv_Switch;
    P->sv=sv_Switch;
    P->next=NULL;
    if(L==NULL || sv_Switch.diemTK>L->sv.diemTK)
    {
        P->next=L;
        L=P;
        return;
    }
    TRO Q=L;
    while(Q->next!=NULL && Q->next->sv.diemTK<Q->sv.diemTK)
    {
        Q=Q->next;
    }
    P->next=Q->next;
    Q->next=P;
}
int main()
{
    tao_danh_sach(L);
    cout<<" danh sach moi tao la :"<<endl;
    inDS(L);
    chen_truoc_MAX(L);
    cout<<" danh sach sau khi chen truoc max la :"<<endl;
    inDS(L);
    xoa_MAX(L);
    cout<<" danh sach sau khi xoa max la :"<<endl;
    inDS(L);
    them_vao_vi_tri(L,3);
    cout<<" danh sach sau khi them vao vi tri thu 3 la :"<<endl;
    inDS(L);
    xoa_theo_vi_tri(L,3);
    cout<<" danh sach sau khi xoa vi tri thu 3 la :"<<endl;
    inDS(L);
    delete_all_MAX(L);
    cout<<" danh sach sau khi xoa tat ca max la :"<<endl;
    inDS(L);
    cin.ignore();
    tim_ten(L);
    //sap_chon(L);
    //bb_sort(L);
    sap_chen(L);
    cout<<" danh sach sau khi sap chon tang dan la :"<<endl;
    inDS(L);
 return 0;
}
