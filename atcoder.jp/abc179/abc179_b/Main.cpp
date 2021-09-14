#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf



int main(){
    int N;
    cin >> N;
    vector<bool> D(N);
    
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        D.at(i) = a==b;
    }
    
    for(int i=0; i<N-2; i++){
        if(D.at(i) && D.at(i+1) && D.at(i+2)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
}
