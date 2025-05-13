import numpy as np
def UCL(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def ex_clit(a,b):
    if UCL(a,b)!=1:
        print(" 2 so k nguyen to cung nhau ")
        return
    else:
        r0,r1=b,a
        x0,x1=0,1
        y0,y1=1,0
        while r1!=1:
            q=r0//r1
            r0,r1=r1,r0%r1
            x0,x1=x1,x0-q*x1
            y0,y1=y1,y0-q*y1
    if x1<0:
            x1+=b
    return x1
def chuyen_chu_thanh_so(c):
     return ord(c.upper())-ord('A')
def chuyen_so_thanh_chu(pos):
     return chr(pos % 26 + ord('A'))
def HILL(text, key):
     ketqua=""
     if len(text)%2 !=0:
          text+='X'
     for i in range(0, len(text), 2):
          vectoR =[chuyen_chu_thanh_so(text[i]),chuyen_chu_thanh_so(text[i+1])]
          res = np.dot(key,vectoR)%26
          ketqua+=chuyen_so_thanh_chu(res[0])+chuyen_so_thanh_chu(res[1])
     return ketqua
def nghich_dao_ma_tran(k):
     det= int(round(np.linalg.det(k)))
     det_mod=det%26
     inv_det= ex_clit(det_mod,26)
     adj=np.array([[k[1][1],-k[0][1]],[-k[1][0],k[0][0]]])
     adj_mod=adj%26
     return (inv_det*adj_mod)%26
def giai_ma(cipher, key):
     inv_chip=nghich_dao_ma_tran(key)
     return HILL(cipher,inv_chip)
if __name__ == "__main__":
    key = np.array([[3, 3], [2, 5]])
    text = "HELP"

    ma_hoa = HILL(text, key)
    print("Mã hóa:", ma_hoa)

    giai_ma = giai_ma(ma_hoa, key)
    print("Giải mã:", giai_ma)