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
//const ll mod = 998244353;


int main() {
    int H,W,N;
    cin >> H >> W >> N;

    vector<pp> R(N);
    vector<pp> C(N);

    vector<pp> ANS(N);

    for(int i=0; i<N; i++){
        int A,B;
        cin >> A >> B;
        R[i] = mk(A,i);
        C[i] = mk(B,i);
    }

    sort(R.begin(),R.end());
    sort(C.begin(),C.end());

    int raw=1;
    int col=1;
    for(int i=0; i<N; i++){
        if(i!=0 && R[i].first != R[i-1].first){
            raw++;
        }
        ANS[ R[i].second ].first = raw;

        if(i!=0 && C[i].first != C[i-1].first) col++;
        ANS[ C[i].second ].second = col;
    }

    for(int i=0; i<N; i++){
        cout << ANS[i].first << " " << ANS[i].second << endl;
    }

}
