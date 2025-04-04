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