#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main(){
    int N;
    cin >> N;
    vector<int> d(N);
    for(int i=0; i<N; i++){
        cin >> d.at(i);
    }
    sort(d.begin(),d.end());
    int ARCmin = d.at(N/2);
    int ABCmax = d.at(N/2-1);
    if(ARCmin - ABCmax < 0){
        cout << 0;
    }else{
        cout << ARCmin - ABCmax;
    }
}
