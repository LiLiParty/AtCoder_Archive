#include <bits/stdc++.h>
using namespace std;


int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> Switch(M);
    for(int i=0; i<M; i++){
        int k; cin >> k;
        Switch[i].resize(k);
        for(int j=0; j<k; j++){
            cin >> Switch[i].at(j); //二次元配列　行が電球、列がスイッチ
 			Switch[i].at(j) --;
        }
    }
    vector<int> p(M);
	for (int i = 0; i < M; ++i){
        cin >> p[i];                     //余り配列
    }

    int ans=0; //組み合わせの個数(答え)
    
    for (int bit = 0; bit < (1<<N); ++bit){ //1ならon
      	bool Allon=true;
        for(int i=0; i<M; i++){
            //i行目についての処理
            int on=0;//スイッチonの数
            for(auto x: Switch[i]){ //スイッチの番号を全て列挙
                if(bit & (1<<x)) on++;
            }
          	if(on%2!=p[i]) Allon = false;
        }
      	if(Allon) ans++;
    }

    cout << ans;
}