#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#define MAX 8

struct SinhVien {
    int maSV;
    string hoTen;
    float diem;
};

struct List {
    int count;
    SinhVien sv[MAX];
};

void creat(List &L) {
    L.count = -1;
}

int check_empty(List L) {
    return (L.count == -1);
}
int check_full(List L)
{
    return (L.count==MAX-1);
}
void nhap_sv(SinhVien &sv) {
    cout << "Nhap thong tin :" << endl;
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap ho Ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap diem: ";
    cin >> sv.diem;
}

void in(List L) {
    if (check_empty(L)) {
        cout << "Danh sach rong." << endl;
    } else {
        cout << setw(5) << "Ma SV" << setw(20) << "Ho Ten" << setw(10) << "Diem" << endl;
        for (int i = 0; i <= L.count; i++) {
            cout << setw(5) << L.sv[i].maSV;
            cout << setw(20) << L.sv[i].hoTen;
            cout << setw(10) << L.sv[i].diem << endl;
        }
    }
}

void add(List &L) {
    if (L.count >= MAX - 1) {
        cout << "Khong the them them sinh vien, da vuot qua gioi han." << endl;
        return;
    }
    int n;
    cout << "Nhap so sinh vien muon them: ";
    cin >> n;

    // Ensure we don't attempt to add more students than space allows
    if (L.count + n >= MAX) {
        cout << "Khong the them " << n << " sinh vien. Chi cho phep them toi da "
        << (MAX - L.count - 1) << " sinh vien." << endl;
        n = MAX - L.count - 1; // Adjust n to the remaining capacity
    }

    for (int i = 0; i < n; i++) {
        L.count++;
        SinhVien sv;
        nhap_sv(sv);
        L.sv[L.count] = sv;
    }
}
// nhap vao danh sach
bool add_any(List &L, int k) {
    cout << "Nhap vi tri muon chen: ";
    cin >> k;

    if (k < 1 || k > L.count + 2)
        return false;

    if (check_full(L)) {
        cout << "Khong the chen, danh sach da day." << endl;
        return false;
    }

    for (int i = L.count; i >= k - 1; i--) {
        L.sv[i + 1] = L.sv[i];
    }

    SinhVien sv;
    nhap_sv(sv);
    L.sv[k - 1] = sv;
    L.count++;
    return true;
}
void sap_xep_lua_chon(List &L)
{
    for(int i=0;i<=L.count;i++)
    {
        int minI=i;
        for(int j=i+1;j<=L.count;j++)
        {
            if(L.sv[j].diem<L.sv[minI].diem)
                minI=j;
        }
        if(minI!=i)
        {
            SinhVien temp= L.sv[i];
            L.sv[i]=L.sv[minI];
            L.sv[minI]=temp;
        }
    }
}
void sap_xep_noi_bot(List &L)
{
    for(int i=0;i<=L.count;i++)
    {

        for(int j=i+1;j<=L.count;j++)
        {
            if(L.sv[i].diem>L.sv[i+1].diem)
            {
                SinhVien temp= L.sv[j];
                L.sv[j]=L.sv[j+1];
                L.sv[j+1]=temp;
            }
        }
    }
}
// xoa sinh vien truoc sinh vien co diem tb lon nhat
void sx_chen(List &L)
{
    for(int i=1;i<=L.count;i++)
    {
        SinhVien key=L.sv[1];
        int j=i-1;
        while(j>=0 && L.sv[j].diem>key.diem)
        {
            L.sv[j+1]=L.sv[j];
            j--;
        }
         L.sv[j+1]=key;
    }

}
// xoa sinh vien truoc sinh vien co diem tb lon nhat
void xoapt(List &L)
{
    int MaxI=0;
    for(int i=0;i<=L.count;i++)
    {
        if(L.sv[MaxI].diem<L.sv[i].diem)
          MaxI=i;
    }
    if(MaxI>0)
    {
        for(int i = MaxI-1; i<=L.count;i++)
        {
            L.sv[i]=L.sv[i+1];
        }
        L.count--;
        cout << "Da xoa phan tu truoc sinh vien co diem cao nhat!\n";
    } else {
        cout << "Khong co phan tu de xoa!\n"; 
    }
    }

int rEmove(List &L, int &k)
{
    cout<<" nhap vi tri muon xoa : ";
    cin>>k;
   if( k<0 || k>L.count +1)
    return 0;
 else
 {
     for(int i=k-1;i<L.count;i++)
        L.sv[i]=L.sv[i+1];

    L.count--;
   return 1;
 }
}

int main() {
    List L;
    creat(L);
    add(L);
    int k;
    add_any(L,k);
    in(L);
    rEmove(L,k);
   // cout<<" sau khi xoa "<<endl;
   // in(L);
    sap_xep_lua_chon(L);
    cout<<" danh sach sau xep:"<<endl;
    in(L);
    xoapt(L);
    cout<<" sau khi xoa "<<endl;
    in(L);
    return 0;
}
