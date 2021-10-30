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
    int N,M; cin >> N >> M;
    
    if(N == 1 && M == 1){
        cout << "Yes" << endl;
        return 0;
    }


    vector<vector<int>> B(N+1,vector<int>(M+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> B[i][j];
        }
    }

    //mod
    for(int i=1; i<=N; i++){
        int mod = -1;
        int Num = 0;

        for(int j=1; j<=M; j++){
            if(Num != 0){
                if(Num + 1 != B[i][j]){
                    cout << "No" << endl;
                    return 0;
                }
            }
            Num = B[i][j];

            int M = B[i][j]%7;
            if(M == 0) M = 7;

            if(mod == -1){
            }else if(mod+1 != M){
                //cout << B[i][j] << endl;
                cout << "No" << endl;
                return 0;
            }

            mod = M;
        }
    }

    
    for(int j=1; j<=M; j++){
        int num = B[1][j];
        for(int i=2; i<=N; i++){
            if( num + 7 != B[i][j]){
                cout << "No" << endl;
                return 0;
            }
            num = B[i][j];
        }
    }

    cout << "Yes" << endl;

}
