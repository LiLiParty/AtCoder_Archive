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

int main(){
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H+1,vector<int>(W+1));

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cin >> A[i][j];
        }
    }

    bool ans = true;

    for(int i1=1; i1<=H; i1++){
        for(int i2=i1+1; i2<=H; i2++){
            for(int j1=1; j1<=W; j1++){
                for(int j2=j1+1; j2<=W; j2++){
                    if( A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) ans = false;
                }
            }
        }
    }

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
