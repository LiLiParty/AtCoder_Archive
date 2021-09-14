#include <bits/stdc++.h>
using namespace std;




int main() {
    int H,W;
    cin >> H >> W;
    
    vector<vector<int>> dist(H,vector<int>(W,-1));
    deque< pair<int,int> > dobleque;

    vector<string> field(H);
    int gh,gw;
    for(int i=0; i<H; i++){
        cin >> field.at(i);
        for(int j=0; j<W; j++){
            if(field.at(i).at(j)=='s'){
                dist.at(i).at(j)=0;
                dobleque.push_front( make_pair(i, j) ); //キューの先頭にスタート位置
            }
            if(field.at(i).at(j)=='g'){
                gh = i;
                gw = j;
            }
        }
    }

    vector<int> dh = {1,0,-1,0}; 
    vector<int> dw = {0,1,0,-1};

    
    while( !dobleque.empty() ){
        pair<int,int> current_pos = dobleque.front();
        int h = current_pos.first;
        int w = current_pos.second;
        dobleque.pop_front();

        for(int i=0; i<4; i++){
            int nh = h + dh.at(i);
            int nw = w + dw.at(i);
            if( nh<0 || nh>=H || nw<0 || nw>=W) continue;
            if( dist.at(nh).at(nw) != -1) continue;
            if( field.at(nh).at(nw)=='#'){
                dobleque.push_back(make_pair(nh,nw));
                dist.at(nh).at(nw) = dist.at(h).at(w) + 1;
                continue;
            }
            dobleque.push_front( make_pair(nh,nw) );
            dist.at(nh).at(nw) = dist.at(h).at(w);
        }
    }

    if(dist.at(gh).at(gw)<=2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

