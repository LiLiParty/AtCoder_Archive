#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> AB;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        AB.emplace_back(b, a); //締め切り、所要時間
    }
    sort(AB.begin(),AB.end());
    bool judge=true;
    ll time=0;
    for(int i=0; i<N; i++){
        time += AB[i].second;
        if(AB[i].first < time){
            judge = false;
            break;
        }
    }
    if(judge){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
