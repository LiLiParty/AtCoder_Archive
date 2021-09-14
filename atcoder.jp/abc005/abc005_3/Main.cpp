#include <bits/stdc++.h>
using namespace std;



int main() {
    int T,N; //何秒以内,たこ焼き数
    cin >> T >> N;

    vector<int> Tako(N);
    for(int i=0; i<N; i++) cin >> Tako.at(i);

    int M;
    cin >> M;

    if(M>N){
        cout << "no" << endl;
        return 0;
    }

    for(int i=0; i<M; i++){
        int b;cin >> b;

        bool ok=false;
        for(int k=0; k<Tako.size(); k++){ //T秒以内のたこ焼き全探索
            if( Tako.at(k) <= b && Tako.at(k)+T >= b ){
                ok = true;
                Tako.at(k) = 101;
                break;
            }
        }
        if(!ok){
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;


}

