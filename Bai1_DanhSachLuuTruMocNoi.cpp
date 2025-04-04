#include <iostream>
#include <iomanip>
using namespace std;

struct SinhVien
{
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

void creat(TRO &L)
{
    L = NULL;
}

int check_empty(TRO L)
{
    return L == NULL;
}

void them_Sinh_Vien(SinhVien &sv)
{
    cout << "Nhap ma sinh vien: ";
    cin >> sv.maSV;
    cin.ignore();
    cout << "Nhap vao ho ten: ";
    getline(cin, sv.hoTen);
    cout << "Nhap vao nam sinh: ";
    cin >> sv.namSinh;
    cout << "Nhap vao diem tong ket: ";
    cin >> sv.diemTK;
}

void tao_danh_sach_moi(TRO &L)
{
    int n;
    cout << "Nhap so luong sinh vien muon them: ";
    cin >> n;
    TRO last = NULL;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap vao sinh vien thu " << i + 1 << ": " << endl;
        TRO Q = new Node;
        SinhVien sv;
        them_Sinh_Vien(sv);
        Q->sv = sv;
        Q->next = NULL;
        if (L == NULL)
            L = Q;
        else
            last->next = Q;

        last = Q;
        cout << "Da them thanh cong" << endl;
    }
}

TRO seaRch(TRO L)
{
    TRO Q = L;
    int maSV;
    cout << "Nhap ma sinh vien can tim: ";
    cin >> maSV;
    while (Q != NULL)
    {
        if (Q->sv.maSV == maSV)
            return Q;
        Q = Q->next;
    }
    return NULL;
}

void inTieuDe()
{
    cout
        << setw(10) << "Ma SV"
        << setw(20) << "Ho ten"
        << setw(20) << "Nam sinh"
        << setw(12) << "Diem TK"
        << endl;
}

void duyet_danh_sach(TRO L)
{
    if (check_empty(L))
    {
        cout << "Danh sach rong!" << endl;
        return;
    }
    inTieuDe();
    TRO Q = L;
    while (Q != NULL)
    {
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

int dem_chieu_dai_danh_sach(TRO L)
{
    int count = 0;
    TRO Q = L;
    while (Q != NULL)
    {
        Q = Q->next;
        count++;
    }
    return count;
}

void hien_thi_dsach_sv_diem(TRO L)
{
    if (check_empty(L))
    {
        cout << "Danh sach rong!" << endl;
        return;
    }
    int count = 0;
    TRO Q = L;
    while (Q != NULL)
    {
        if (Q->sv.diemTK >= 6.5)
        {
            if (count == 0)
            {
                cout << "Danh sach sinh vien co diem tong ket >= 6.5:\n";
                inTieuDe();
            }
            cout << setw(10) << Q->sv.maSV
                 << setw(20) << Q->sv.hoTen
                 << setw(20) << Q->sv.namSinh
                 << setw(12) << fixed << setprecision(2) << Q->sv.diemTK
                 << endl;
            count++;
        }
        Q = Q->next;
    }

    if (count == 0)
    {
        cout << "Khong co sinh vien nao co diem tong ket >= 6.5.\n";
    }
}

void chen_vao_vi_tri(TRO &L)
{
    int k;
    cout << "Nhap vao vi tri muon chen: ";
    cin >> k;
    SinhVien svMoi;
    cout << "Nhap thong tin sinh vien moi:\n";
    them_Sinh_Vien(svMoi);
    TRO P = new Node;
    P->sv = svMoi;
    P->next = NULL;

    if (k <= 1 || L == NULL)
    {
        P->next = L;
        L = P;
    }
    else
    {
        TRO Q = L;
        int i = 1;
        while (Q->next != NULL && i < k - 1)
        {
            Q = Q->next;
            i++;
        }
        P->next = Q->next;
        Q->next = P;
    }
    cout << "Da chen sinh vien vao vi tri " << k << " thanh cong!\n";
}

void xoa_danh_sach(TRO &L)
{
    TRO Q;
    while (L != NULL)
    {
        Q = L;
        L = L->next;
        delete Q;
    }
}

int main()
{
    TRO L;
    creat(L);
    tao_danh_sach_moi(L);
    cout << "Danh sach sinh vien:\n";
    duyet_danh_sach(L);

    int so_luong = dem_chieu_dai_danh_sach(L);
    cout << "Chieu dai danh sach la: " << so_luong << endl;

    TRO kq = seaRch(L);
    if (kq != NULL)
    {
        cout << "Tim thay sinh vien:\n";
        inTieuDe();
        cout << setw(10) << kq->sv.maSV
             << setw(20) << kq->sv.hoTen
             << setw(20) << kq->sv.namSinh
             << setw(12) << fixed << setprecision(2) << kq->sv.diemTK
             << endl;
    }
    else
    {
        cout << "Khong tim thay sinh vien!\n";
    }

    hien_thi_dsach_sv_diem(L);

    chen_vao_vi_tri(L);
    cout << "Danh sach sau khi chen:\n";
    duyet_danh_sach(L);

    xoa_danh_sach(L); // Giải phóng bộ nhớ
    return 0;
}
