#include <bits/stdc++.h>
using namespace std;


int main(){
    int N; //店舗の数
    cin >> N;
    pair<pair<string,int>,int> rest[N];
    for(int i=0; i<N; i++){
        string S;
        int P;
        cin >> S >> P;
        rest[i].first = make_pair(S,-1*P);
        rest[i].second = i+1;
    }
    sort(rest,rest+N);
    for(int i=0; i<N; i++){
        cout << rest[i].second << endl;
    }
}
