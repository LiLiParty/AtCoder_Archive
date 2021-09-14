#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> t(N);
    for(int i=0; i<N;i++){
        cin >> t.at(i);
    }
    int ans = 2000;
    for(int bit=0; bit < (1<<N); bit++){ //Nビット全探索
        int pa=0;
        int pb=0;
        for(int i=0; i<N; i++){
            if(bit & (1<<i)){
                pa += t.at(i);
            }else{
                pb += t.at(i);
            }
        }
        int time = max(pa,pb);
        ans = min(time,ans);
    }
    cout << ans << endl;
}
