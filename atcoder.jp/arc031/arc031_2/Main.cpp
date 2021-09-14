#include <bits/stdc++.h>
using namespace std;

bool seen[11][11];//seen配列 falseに初期化しておく
//移動ベクトル
const int dx[4] = {1 , 0, -1, 0};
const int dy[4] = {0 , 1, 0 , -1};
//埋め立て可能回数
int landfill = 1;
//入力
vector<string> field(15); //12*12にする

void dfs(int x, int y){ //最初に見つけた島から探索
    seen[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>9 || ny<0 || ny>9) continue;
        if(seen[nx][ny]) continue;
        if(field[nx][ny] == 'x') continue;

        if(field[nx][ny] == 'o') dfs(nx,ny);
    }
}

int main() {
    for(int i=0; i<10; i++){
        cin >> field.at(i);
    }

    int a=false;
    int xx,yy;
    for(int i=0; i<10; i++){
        if(a) break;
        for(int j=0; j<10; j++){
            if(field[i][j]=='o'){
                xx=i;
                yy=j;
                a=true;
                break;
            }
        }
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            memset(seen, 0, sizeof(seen));
            bool b=false;
            if(field[i][j]=='x'){
                field[i][j] = 'o';
                b=true;
            }
            dfs(xx,yy);
            
            //0かつすべてtrueが見つかったら
            bool flag = true;
            for(int k=0; k<10; k++){
                for(int l=0; l<10; l++){
                    if(field[k][l]=='o' and !seen[k][l]) flag = false; //fieldが０かつseenがfalseなら
                }
            }
            if(flag){
                cout << "YES" << endl;
                return(0);
            }

            if(b) field[i][j] = 'x';

        }
    }

    cout << "NO" << endl;

}

