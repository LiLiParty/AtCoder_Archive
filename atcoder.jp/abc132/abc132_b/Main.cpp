#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin >> p.at(i);
    }
    int ans=0;
    for(int i=1; i<n-1; i++){
        if(p[i-1] < p[i] and p[i] < p[i+1]){
          ans++;
        }else if(p[i+1] < p[i] and p[i] < p[i-1]){
          ans++;
        }
    }
    cout << ans;
}