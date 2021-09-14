#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int N;
    cin >> N;
    vector<ll> A_p( pow(2,N) );
    for(ll i=0; i<pow(2,N); i++){
        cin >> A_p.at(i);
    }
    vector<ll> copy = A_p;


    for(ll i=1; i<=N-1; i++){
        vector<ll> A;
        for(ll j=1; j<=pow(2,N-i); j++ ){
            //cout << A_p.at(2*j-2) << "vs" << A_p.at(2*j-1) << endl;
            if(A_p.at(2*j-2) > A_p.at(2*j-1)){
                A.push_back(A_p.at(2*j-2));
            }
            if(A_p.at(2*j-2) < A_p.at(2*j-1)){
                A.push_back(A_p.at(2*j-1));
            }
        }
        A_p = A;
    }
    
    ll a = min( A_p.at(0), A_p.at(1));
    
    for(ll i=0; i<pow(2,N); i++){
        if( a == copy.at(i) ){
            cout << i+1 << endl;
            return 0;
        }
    }

}
