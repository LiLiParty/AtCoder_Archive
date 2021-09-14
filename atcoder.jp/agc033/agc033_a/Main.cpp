#include <bits/stdc++.h>
using namespace std;




int main() {
    int H,W;
    cin >> H >> W;
    
    vector<vector<int>> dist(H,vector<int>(W,-1));
    queue< pair<int,int> > que;

    vector<string> field(H);
    for(int i=0; i<H; i++){
        cin >> field.at(i);
        for(int j=0; j<W; j++){
            if(field.at(i).at(j)=='#'){
                dist.at(i).at(j)=0;
                que.push( make_pair(i, j) ); //キューの先頭にスタート位置
                dist.at(i).at(j) = 0;
            }
        }
    }

    vector<int> dh = {1,0,-1,0}; 
    vector<int> dw = {0,1,0,-1};

    
    while( !que.empty() ){
        pair<int,int> current_pos = que.front();
        int h = current_pos.first;
        int w = current_pos.second;
        que.pop();

        for(int i=0; i<4; i++){
            int nh = h + dh.at(i);
            int nw = w + dw.at(i);
            if( nh<0 || nh>=H || nw<0 || nw>=W) continue;
            if( field.at(nh).at(nw)=='#') continue;
            if( dist.at(nh).at(nw) != -1) continue;

            que.push( make_pair(nh,nw) );
            dist.at(nh).at(nw) = dist.at(h).at(w) + 1;
        }
    }

    int ans=0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            ans = max(dist.at(i).at(j),ans);
        }
    }

    cout << ans << endl;
}

