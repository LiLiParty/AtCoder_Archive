#include <bits/stdc++.h>
#include <vector>
using namespace std;




int main() {
    
    int R,C,sy,sx,gy,gx;
    cin >> R >> C >> sy >> sx >> gy >> gx;
    
    vector<vector<int>> dist( R, vector<int>(C,-1) );//レベル0からの距離
    dist.at(sy-1).at(sx-1) = 0;
    
    vector<string> field(R); //ステージ
    for(int i=0; i<R; i++){
        cin >> field.at(i);
    }

    queue< pair<int,int> > que;
    que.push( make_pair(sx-1, sy-1) ); //キューの先頭にスタート位置
    
    vector<int> dx = {1,0,-1,0}; 
    vector<int> dy = {0,1,0,-1};

    //幅優先探索
    while( !que.empty() ){
        
        pair<int, int> current_pos = que.front();
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop();
        

        //四方向を探索
        for(int i=0; i<4; i++){
            int nx = x + dx.at(i);
            int ny = y + dy.at(i);
            if( nx+1<0 || nx+1 > R || ny+1<0 || ny+1 > C) continue;
            if( field.at(nx).at(ny) == '#' ) continue;
            if(dist.at(nx).at(ny)!=-1) continue;
            
            que.push( make_pair( nx, ny) );
            dist.at(nx).at(ny) = dist.at(x).at(y) + 1;
        }

    }

    cout << dist.at(gy-1).at(gx-1) << endl;

    


}

