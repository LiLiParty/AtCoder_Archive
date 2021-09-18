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
    ll H,W; cin >> H >> W;
    vector<vector<ll>> A(H+1,vector<ll>(W+1,0));
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> A[i][j];
        }
    }
    vector<vector<ll>> B(H+1,vector<ll>(W+1,0));
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> B[i][j];
        }
    }
    ll count = 0;
    for(int i=1; i<H; i++){
        for(int j=1; j<W; j++){
            ll diff = B[i][j] - A[i][j];
            count += abs(diff);
            A[i][j] += diff;
            A[i+1][j] += diff;
            A[i][j+1] += diff;
            A[i+1][j+1] += diff;
        }
    }

    bool ans = true;
    for(int i=1; i<=H; i++){
        if(B[i][W] != A[i][W]) ans = false;
    }
    for(int i=1; i<=W; i++){
        if(B[H][i] != A[H][i]) ans = false;
    }

    if(ans){
        cout << "Yes" << endl;
        cout << count << endl;
    }else{
        cout << "No" << endl;
    }

}
