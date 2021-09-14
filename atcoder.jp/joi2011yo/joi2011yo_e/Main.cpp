#include <bits/stdc++.h>
#include <vector>
using namespace std;




int main() {
    int H,W,N; //高,幅,チーズ数
    cin >> H >> W >> N;

    vector<string> field(H);

    for(int i=0; i<H; i++){
        cin >> field.at(i);
    }

    //////////////////////////////////////////
    vector<pair<int,int>> cheese(N+1); //.at(0)にスタート .at(i) にi番のチーズ
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if( field.at(i).at(j)=='S'){
                cheese.at(0) = make_pair(i,j);
                continue;
            }
            if( field.at(i).at(j)=='.') continue;
            if( field.at(i).at(j)=='X') continue;

            int c = field.at(i).at(j) - '0';
            //cout << c << "番のチーズ(" << i << "," << j << ")" << endl; 
            cheese.at(c) = make_pair(i,j);
        }
    }
    ////////////////////////////////////////////////

    queue<pair<int,int>> que;
    vector<int> dh = {1,0,-1,0}; 
    vector<int> dw = {0,1,0,-1};
    
    int ans=0;
    
    for(int i=0; i<N; i++){ //i番目とi+1番目のチーズの最短距離
        vector<vector<int>> dist( H, vector<int>(W,-1));
        dist.at(cheese.at(i).first).at(cheese.at(i).second) = 0;
        que.push( cheese.at(i));
        
        while( !que.empty() ){
            pair<int, int> current_pos = que.front();
            int h = current_pos.first;
            int w = current_pos.second;
            que.pop();
        
            //四方向を探索
            for(int i=0; i<4; i++){
                int nh = h + dh.at(i);
                int nw = w + dw.at(i);
                if( nh<0 || nh+1 > H || nw<0 || nw+1 > W) continue;
                if( field.at(nh).at(nw) == 'X' ) continue;
                if(dist.at(nh).at(nw)!=-1) continue;
            
                que.push( make_pair( nh, nw) );
                dist.at(nh).at(nw) = dist.at(h).at(w) + 1;
            }
        }
        //cout << i << "番から" << i+1 << ":" << dist.at(cheese.at(i+1).first).at(cheese.at(i+1).second) << endl;
        ans += dist.at(cheese.at(i+1).first).at(cheese.at(i+1).second);
    }
    

    cout << ans << endl;
    
    

}

