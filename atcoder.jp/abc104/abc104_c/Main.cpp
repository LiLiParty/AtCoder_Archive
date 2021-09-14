#include <bits/stdc++.h>
using namespace std;


int main(){
    int D,G;
    int p[D],c[D];
    cin >> D >> G;
    for(int i=0; i<D; i++){
        cin >> p[i] >> c[i];
    }
    int ans=1e9;
    for(int bit = 0; bit < (1<<D); bit++){ //完全に解く→1　解かない→2
        int sum = 0;
        int count = 0;
        int rest_max = 0;
        for(int i = 0; i < D; i++){
            if(bit & (1<<i)){
                sum += p[i]*100*(i+1) + c[i];
                count += p[i];
            }else{
                rest_max = max(rest_max,i);
            }
        }//完全に解くものをsumに足し、残った問題番号の最大を得た。
        if(G <= sum + p[rest_max]*100*(rest_max + 1)){
            while(G > sum){
                sum += 100*(rest_max+1);
                count ++;
            }
            ans = min(ans,count);
            continue;
        }else{
            continue;
        }
    }
    cout << ans;
}
        
        
            
