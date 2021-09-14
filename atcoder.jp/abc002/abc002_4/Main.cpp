#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; //N人 M人間関係
    cin >> N >> M;
    vector<int> x(M);
    vector<int> y(M); // ( x.at(i) , y.at(i)) 関係
    for(int p=0; p<M; p++){
        cin >> x.at(p) >> y.at(p);
    }



    int ans = 1;
    for(int bit=0; bit<(1<<N) ; bit++){ //Nビット ***全探索
        int this_bit_result=0;

        vector<int> relate;
        for (int i = 0; i < N; ++i) { 
            if (bit & (1<<i)) {  //i番目にフラグが立っていたら
                relate.push_back(i+1);
                this_bit_result++;
            }
        }

        bool judge1=true;
        for(int k=0; k<relate.size(); k++){
            for(int l=k+1; l<relate.size(); l++){ //( relate.at(k),relate.at(l) )
                bool judge=false;
                for(int p=0; p<M; p++){
                    if( x.at(p) == relate.at(k) and y.at(p) == relate.at(l) ){
                        judge = true;
                    }
                }
                judge1 = judge1 and judge;
            }
        }

        //cout << bit << " " << this_bit_result << endl;

        if(judge1) ans = max(ans,this_bit_result);

    }

    cout << ans << endl;

}
