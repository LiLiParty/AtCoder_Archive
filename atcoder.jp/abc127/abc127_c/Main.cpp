#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,M; //NはIDｶｰﾄﾞ､Mはゲート
    vector<int> L(M);
    cin >> N >> M;
    int Lmax=0,Rmin=1e5+1;
    for(int i=0;i<M;i++){
        int L,R;
        cin >> L >> R;
        Lmax = max(Lmax,L);
        Rmin = min(Rmin,R);
    }
    if(Lmax > Rmin){
        cout << 0;
    }else{
    cout << Rmin - Lmax + 1;
    }
}