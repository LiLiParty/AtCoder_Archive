#include <bits/stdc++.h>
using namespace std;


int main(){
    int64_t A,B,M;
    cin >> A >> B >> M; //Aは冷蔵庫の数、Bは電子レンズの数、Mは割引券の数
    vector<int64_t> a(A); //Aの値段配列
    vector<int64_t> b(B); //Bの値段配列
    for(int i=0;i<A;i++){
        cin >> a.at(i);
    }
    for(int i=0;i<B;i++){
        cin >> b.at(i);
    }//入力を終了

    int64_t minprise=200000000000;

    //割引券を使った場合を全探索
    for(int i=0;i<M;i++){
        int x,y; //割引券の商品の場所　+1されてます
        int64_t c; //割引する価格
        cin >> x >> y >> c;
        int64_t prise;
        prise = a.at(x-1)+b.at(y-1)-c;
        if(prise < minprise){
            minprise = prise;
        }
    }
    int64_t simpleprise;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    simpleprise = a.at(0)+b.at(0);
    if(simpleprise < minprise){
        minprise = simpleprise;
    }
    cout << minprise;
    }
    