#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    ll N;
    cin >> N;
    ll sum=0;
    vector<int> a(N);
    vector<int> b(N);
    for(int i=0; i<N; i++){
        cin >> a.at(i);
    }
    for(int i=0; i<N; i++){
        cin >> b.at(i);
    }
    for(int i=0; i<N; i++){
        sum += a.at(i)*b.at(i);
    }

    if(sum == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
