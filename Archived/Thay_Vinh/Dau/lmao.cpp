#include <bits/stdc++.h>


#define GoiTaoLa define
#define so int
#define daidai long long
#define cap pair
#define dautien first
#define thuhai second
#define neu if
#define trongkhi while
#define nguoclai else
#define hukhong void
#define hangdoiuutien priority_queue
#define hangdoi queue
#define nganxep stack
#define dayvaosau push_back
#define mangdong vector
#define dayvao push
#define xoadau pop
#define hoandoi swap
#define sapxep sort
#define phantudau front
#define docvao cin
#define xuatra cout
#define nhapxuatnhanh cin.tie(0) -> sync_with_stdio(0)
#define chinh main
#define trave return
#define kitu char
#define chuoi string
#define laptuantu for
#define congcong ++
#define giong ==
#define bang =
#define cong +
#define tru -
#define nhan *
#define chia /
#define nhohonbang <=
#define kieulogic bool
#define dung true
#define sai false
#define rong empty
#define nhohon <
#define lonhon >
#define lonhonbang >=
#define khac !=
#define va &
#define vava &&
#define hoac |
#define hoachoac ||

using namespace std;

so n,m;
kitu a[1005][1005];
cap<so,so> batdau,ketthuc;
so duongdi[1005][1005];
kitu truyvet[1005][1005];
so x[4] bang {0,0,1,-1};
so y[4] bang {1,-1,0,0};
kitu di[4] bang {'R','L','D','U'};

kieulogic kiemtra(cap<so,so> p){
    so i bang p.dautien;
    so j bang p.thuhai;
    kieulogic f bang (i lonhon 0 vava i nhohonbang n);
    f bang f va (j lonhon 0 vava j nhohonbang m);
    trave f;
}

kieulogic duyetchieurong(cap<so,so> batdau, cap<so,so> ketthuc){
    hangdoi<cap<so,so>> hd;
    duongdi[batdau.dautien][batdau.thuhai] bang 0;
    hd.dayvao(batdau);
    trongkhi (!hd.rong()){
        cap<so,so> u bang hd.phantudau();
        hd.xoadau();
        laptuantu (so i bang 0; i nhohon 4; i congcong){

        }
    }
}

so chinh(){
    nhapxuatnhanh;
    docvao >> n >> m;
    laptuantu (so i bang 1; i nhohonbang n; i congcong){
        laptuantu (so j bang 1; j nhohonbang m; j congcong){
            docvao >> a[i][j];
            neu (a[i][j] giong 'A'){
                batdau.dautien bang i;
                batdau.thuhai bang j;
            }
            nguoclai neu (a[i][j] giong 'B'){
                ketthuc.dautien bang i;
                ketthuc.thuhai bang j;
            }

        }
    }
    kieulogic f bang duyetchieurong(batdau,ketthuc);
    trave 0;
}
