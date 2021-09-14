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
    int H,W;
    cin >> H >> W;
    vector<vector<ll>> field(H,vector<ll>(W,0));
    vector<ll> sumRaw(H),sumLine(W);

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> field[i][j];
        }
    }

    for(int i=0; i<H; i++){
        ll sum = 0;
        for(int j=0; j<W; j++){
            sum += field[i][j];
        }
        sumRaw[i] = sum;
    }

    for(int i=0; i<W; i++){
        ll sum = 0;
        for(int j=0; j<H; j++){
            sum += field[j][i];
        }
        sumLine[i] = sum;
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cout << sumRaw[i] + sumLine[j] - field[i][j] << " ";
        }
        cout << endl;
    }

}
