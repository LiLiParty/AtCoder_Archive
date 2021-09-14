#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
using Data = pair<long long, vector<int> >;

int main() {
    vector<long long> N(3);
    int K;
    for (int i = 0; i < 3; ++i) cin >> N[i]; cin >> K;
    vector<vector<long long> > v(3);
    for (int iter = 0; iter < 3; ++iter) {
        v[iter].resize(N[iter]);
        for (int i = 0; i < N[iter]; ++i) cin >> v[iter][i];
        sort(v[iter].begin(), v[iter].end(), greater<long long>());
    }
    priority_queue<Data> que;
    set<Data> se;
    que.push(Data(v[0][0] + v[1][0] + v[2][0], vector<int>({0, 0, 0})));
    for (int k = 0; k < K; ++k) {
        auto c = que.top();que.pop();
        cout << c.first << endl;
        
        // 次の三候補
        for (int iter = 0; iter < 3; ++iter) {
            if (c.second[iter] + 1 < N[iter]) {
                long long sum = c.first - v[iter][c.second[iter]] + v[iter][c.second[iter] + 1];
                auto num = c.second; num[iter]++;
                auto d = Data(sum, num);
                
                // すでに push されたもの以外
                if (!se.count(d)) se.insert(d), que.push(d);
            }
        }
    }
}