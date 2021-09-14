#include <iostream>
#include <vector>
using namespace std;


bool flag;

void dfs(int i, vector<vector<int>> &G, vector<bool> &seen, int pre){
    seen.at(i) = true;

    for(auto next_v : G.at(i)){
        //cout << i ;
        if(seen.at(next_v-1)){
            if(next_v != pre){
                //cout << "閉路" << i ;
                flag = false;
            }
            //cout << "next_vは" << next_v << "preは" << pre << endl;
            continue;
        }
        if(next_v == pre) continue;
        dfs(next_v-1,G,seen,i+1);
    }

}



int main() {
    int N,M;
    cin >> N >> M;

    vector<bool> seen(N,0);//i番目にi-1番目が探索済みかを代入
    vector<vector<int>> G(N); 
    //0番目～N-1番目が存在。 i番目にi+1番目と結合している頂点を代入。
    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        G.at(a-1).push_back(b);
        G.at(b-1).push_back(a);
    }

    


    flag = true;
    int ans=0;

    for(int i=0; i<N; i++){
        if(!seen.at(i)){ //未探索ならdfs
            //cout << "探索開始：" << i ;
            dfs(i,G,seen,0);
            if(flag){
                //cout << " カウント";
                ans++;
            }
            //cout << endl;
        }
        flag = true;
    }

    cout << ans << endl;

}