#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> A1(N+1);
    vector<int> B1(N);
    vector<int> A2(N+1);
    vector<int> B2(N);
    for(int i=0; i<N+1; i++){
        cin >> A1.at(i);
        A2.at(i)=A1.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> B1.at(i);
        B2.at(i)=B1.at(i);
    }

    ll ans1=0;
    ll ans2=0;

    for(int i=0; i<N; i++){
        if(A1.at(i)<B1.at(i)){
            ans1 += A1.at(i);
            B1.at(i) -= A1.at(i);
            A1.at(i)=0;

            if(A1.at(i+1)<=B1.at(i)){
                ans1 += A1.at(i+1);
                A1.at(i+1) = 0;
            }else{
                ans1 += B1.at(i);
                A1.at(i+1) -= B1.at(i);
            }
        }else{
            ans1 += B1.at(i);
            A1.at(i) -= B1.at(i);
        }
    }
    
    cout << ans1;


}