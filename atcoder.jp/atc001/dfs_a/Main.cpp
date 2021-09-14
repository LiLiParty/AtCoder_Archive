#include <bits/stdc++.h>
using namespace std;


//移動ベクトル
const int dx[4] = {1 , 0, -1, 0};
const int dy[4] = {0 , 1, 0 , -1};


//入力
int H,W;
vector<string> field;

//seen配列、検出済み→true 未検出→false
bool seen[510][510];

void dfs(int h, int w){ 
    seen[h][w] = true;

    for(int dir=0; dir<4; dir++){
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        if(nh < 0 || nh >= H || nw < 0 || nw >=W) continue; //範囲外
        if(field[nh][nw] == '#') continue; //壁
        if(seen[nh][nw]) continue;

        dfs( nh, nw);
    }

}




int main(){
    cin >> H >> W; //たてH×よこW

    for(int i=0; i<H; i++){
        string a;
        cin >> a;
        field.push_back(a);
    }

    int sx,sy,gx,gy;
    for(int h=0; h<H; h++){ //スタートとゴールの位置を特定
        for(int w=0; w<W; w++){
            if(field[h][w] == 's'){
                sx=h;
                sy=w;
            }
            if(field[h][w] == 'g'){
                gx=h;
                gy=w;
            } 
        }
    }

    memset(seen, 0, sizeof(seen)); // seen 配列全体を false に初期化

    //sからdfs
    dfs(sx,sy);

    if(seen[gx][gy]){
        cout << "Yes";
    }else{
        cout << "No";
    }


}
