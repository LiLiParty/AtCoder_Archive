#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<int> p(N);
    int count=0;
    int a,b;
    bool can=false;
    for(int i=0; i<N; i++){
        cin >> p.at(i);
    }

    for(int i=1; i<N+1; i++){
        if( p.at(i-1)!=i and count==0 ){  //昇順ではない時
            a=i;           //来るべき値をaに保持
            b=p.at(i-1);   //実際に入っていた値をbに保持
            count ++;
            continue;
        }
        if( p.at(i-1)!=i and count==1 ){ //二回目の昇順ではない時
            if(i==b and p.at(i-1)==a ){
                can = true;
                count ++;
                continue;
            }else{
                can = false;
                break;
            }
        }
        if( p.at(i-1)!=i and count==2 ){
            can = false;
            break;
        }
    }
    if(can or count==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}