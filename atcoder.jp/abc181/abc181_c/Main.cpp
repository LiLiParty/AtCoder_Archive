#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf


int main(){
    ll N;
    cin >> N;
    vector< pair<double,double> > p(N);
    for(ll i=0; i<N; i++){
        double x,y;
        cin >> x >> y;
        p.at(i) = make_pair(x,y);
    }

    bool flag = false;
    for(ll i=0; i<N; i++){
        for(ll j=i+1; j<N; j++){
            for(ll k=j+1; k<N; k++){
                if( p[i].first - p[j].first ==0 && p[i].first - p[k].first==0){
                    flag = true;
                    //cout << i << " " << j << " " << k;
                    break;
                }
                if( p[i].first - p[j].first ==0 || p[i].first - p[k].first==0) continue;
                if( (p[i].second - p[j].second)/(p[i].first - p[j].first) == (p[i].second - p[k].second)/(p[i].first - p[k].first)){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
