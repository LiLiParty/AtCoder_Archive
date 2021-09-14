#include <bits/stdc++.h>
using namespace std;




int main() {
    int N,M;
    cin >> N >> M;

    vector<vector<int>> G( N+1, vector<int>(N+1) ); //n番目に,頂点n

    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        G.at(a).at(b) = 1;
        G.at(b).at(a) = 1;
    }

    vector<int> p(N-1); //={2,3,4,,,,N}
    for(int i=2; i<=N; i++){
        p.at(i-2) = i;
    }
    int ans=0;

    do{ //各順序でたどる
        bool flag = true;
        if(G.at(1).at(p.at(0)) != 1) flag = false;
        for(int i=0; i<N-2; i++){
            if( G.at(p.at(i)).at(p.at(i+1)) == 1){
            }else{
                flag = false;
            }
        }
        if(flag) ans++;

    }while( next_permutation( p.begin(), p.end() ) );

    cout << ans << endl;


}

