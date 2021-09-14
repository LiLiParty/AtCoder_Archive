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


ll dp[1000000];//dp[各桁の数字の和] = 通り

int main() {
    int N,Q; cin >> N >> Q;
    vector<int> A(N+1);
    for(int i=1; i<=N; i++) cin >> A[i];
    int shift = 0;
    vector<pp> ans;
    for(int i=0; i<Q; i++){
        int T; cin >> T;
        int x,y;
        cin >> x >> y;
        if(T == 1){
            int xx = x-shift;
            if(xx <= 0) xx+=N;
            int yy = y-shift;
            if(yy <= 0)yy+=N;
            int tmp = A[xx];
            A[xx] = A[yy];
            A[yy] = tmp;
        }else if(T == 2){
            shift++;
            if(shift == N) shift = 0;
        }else{
            int index = x - shift;
            if(index <= 0) index+=N;
            ans.push_back(mk(A[index],x));
        }
    }

    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first << endl;
    }
}
