#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    cin >> N;
    vector<vector<bool>> dp(101,vector<bool>(10001,0));
    dp.at(0).at(0) = 1;
    vector<int> p(N);
    for(int i=0; i<N; i++){
        cin >> p.at(i);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<=10000; j++){
            if(j-p.at(i)>=0){
                dp.at(i+1).at(j) = dp.at(i).at(j) | dp.at(i).at(j-p.at(i));
            }else{
                dp.at(i+1).at(j) = dp.at(i).at(j);
            }
        }
    }

    int ans=0;
    for(int j=0; j<=10000; j++){
        if(dp.at(N).at(j)) ans++;
    }

    cout << ans << endl;
    
}