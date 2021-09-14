#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807
//const ll mod=1000000007;//10^9-7



int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    vector<ll> B(M);
    for(int i=0; i<N; i++){
        cin >> A.at(i);
    }
    for(int i=0; i<M; i++){
        cin >> B.at(i);
    }

    ll A_sum=0;
    ll A_count=0;
    for(int i=0; i<N; i++){
        if(K < A_sum+A.at(i)) break;
        A_count++;
        A_sum+=A.at(i);
    }
    
    ll ans=0;
    ll B_sum=0;
    ll B_count=0;
    for(int i=A_count; i>=0; i--){
        
        for(int k=B_count; k<M; k++){
            if(K < A_sum + B_sum + B.at(k)) break;
            B_count++;
            B_sum+=B.at(k);
        }
        //cout << "Aから:" << A_count << "冊 Bから:" << B_count << "冊" << endl; 
        //cout << "Asum: " << A_sum <<   " Bsum: "<< B_sum << endl;
        ans = max(ans,A_count+B_count);
        A_count--;
        if(A_sum!=0) A_sum -= A.at(A_count);
    }
    
    cout << ans << endl;
    



}

