#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;

    vector< pair<string,ll> > S(N);
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        if(s.at(0) == '!'){
            s.erase(s.begin());
            S.at(i) = make_pair(s,1);//!を削除
        }else{
            S.at(i) = make_pair(s,0);
        }
    }
    sort(S.begin(),S.end());


    for(int i=0; i<N-1; i++){
        if( S.at(i).first == S.at(i+1).first ){
            if( S.at(i).second != S.at(i+1).second ){
                cout << S.at(i).first << endl;
                return 0;
            }
        }
    }
    
    cout << "satisfiable" << endl;

}
