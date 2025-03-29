#include <iostream>
#include <string>
using namespace std;
// tinh de quy n!
long long dequytinhgiaithua( int n)
{
    if(n==0)
     return 1;
    else
    {
        return(dequytinhgiaithua(n-1)*n);
    }
}
// day so fibonanchi
long long fibo(int n)
{
    if(n<=2)
     return 1;
    else
     return fibo(n-1)+fibo(n-2);

}
// Hàm lặp in ngược chuỗi
void hamlapinnguoc(string &S)
{
  for(int i= S.length()-1;i>=0;i--)
  {
    cout<<S[i];
  }
  cout<<endl;
}
// de qy in nguoc chuoi
void de_quy_in_nguoc_chuoi(string &S, int index)
{
    // dieu kien dung
   if(index<0)
    return;
    // in ra tu cuoi
    cout<<S[index];
   de_quy_in_nguoc_chuoi(S,index-1);
}
// de quy dem so chu so
int dem_so_chu_so( int n )
{
    n= abs(n);
    if(n<10)
     return 1;
    else
     return 1+dem_so_chu_so(n/10);
}

int main()
{
//   cout<<"de quy : "<<dequytinhgiaithua(5)<<endl;
//   cout<<"day fi : "<<fibo(10)<<endl;
string S="PASCAL";
hamlapinnguoc(S);
de_quy_in_nguoc_chuoi(S,S.length()-1);
cout<<endl;
int n;
cout<<"nhap so : ";
cin>>n;
cout << "So chu so cua " << n << " la: " << dem_so_chu_so(n) << endl;
    return 0;
}