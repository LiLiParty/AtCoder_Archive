#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin >> N;

    vector<int> A(N); //徒歩何分
    vector<int> P(N); //何円
    vector<int> X(N); //台数

    for(int i=0; i<N; i++){
        cin >> A.at(i) >> P.at(i) >> X.at(i);
    }

    int ans=1000000001;
    for(int i=0; i<N; i++){
        if(X.at(i)-A.at(i)>0){
            ans = min(ans,P.at(i));
        }
    }

    if(ans==1000000001){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
}