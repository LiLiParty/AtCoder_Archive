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
    double N;
    cin >> N;
    vector<double> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());

    vector<double> A_sum(N,0);
    for(int i=0; i<N; i++){
        A_sum[i] = A[i];
        if(i!=0){
            A_sum[i] += A_sum[i-1];
        }
    }
    //cout << "A_sum[N-1]: " << A_sum[N-1] << endl;
    double ans = INF32;
    for(int i=0; i<N; i++){
        double x = A[i] / 2.0;
        double Ai = A_sum[N-1] / N;
        double MIN = 0;
        MIN += A[i] * (i+1);
        MIN += A_sum[N-1] - A_sum[i];
        MIN /= N;
        ans = min(ans, x+Ai-MIN);
        /*
        if(ans == x+Ai-MIN){
            cout << ans << " " << x << " " << Ai << " " << MIN << endl;
        }
        */
    }

    printf("%.9lf",ans);
}