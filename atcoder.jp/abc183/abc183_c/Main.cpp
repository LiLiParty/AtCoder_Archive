#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf

int main(){
    int N,K;
    cin >> N >> K;
    
    vector< vector<ll> > T(N);
    for(int i=0; i<N; i++){
        for(int k=0; k<N; k++){
            ll t;
            cin >> t;
            T.at(i).push_back(t);
        }
    }
    
    vector<ll> p; //{1,2,3,,,,,N-1}
    for(int i=1; i<=N-1; i++){
        p.push_back(i);
    }
    
    ll count=0;
    do{
        ll k=0;
        k += T.at(0).at(p.at(0));
        
        for(int i=0; i<N-2; i++){
            k += T.at(p.at(i)).at(p.at(i+1));
        }
        
        k += T.at(p.at(N-2)).at(0);

        if(k==K) count++;
    }while( next_permutation(p.begin(), p.end()) );

    cout << count <<endl;
    
    
    
}
