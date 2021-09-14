#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pp pair<ll,ll>
#define ll long long
#define ld long double
#define mk make_pair
#define INF32 2147483647 
#define INF64 9223372036854775807
#define rep(i, n) for(int i = 0; i < n; i++)
const ll MOD = 1000000007;//10^9+7
const ll mod = 998244353;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> field(1010,vector<ll>(1010,0));
    for(int i=0; i<N; i++){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        field[lx][ly] += 1;
        field[rx][ry] += 1;
        field[lx][ry] -= 1;
        field[rx][ly] -= 1;
    }
    for(int i=0; i<1010; i++){
        for(int j=1; j<1010; j++){
            field[i][j] += field[i][j-1];
        }
    }
    for(int i=1; i<1010; i++){
        for(int j=0; j<1010; j++){
            field[i][j] += field[i-1][j];
        }
    }
    vector<int>cnt(N+1,0);
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            cnt[field[i][j]]++;
        }
    }
    for(int i=1;i<N+1;i++){
        cout << cnt[i] << endl; 
    }
}
