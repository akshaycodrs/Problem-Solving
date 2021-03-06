//Link : https://codeforces.com/problemset/problem/190/E

// Author : Nachiket Kanore
// Institute : PICT, Pune

/* It does not matter how slowly you go as long as you do not stop.*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define rep(x,s,e) for(int x=s;x<=(e);x++)
#define repn for(int x=0;x<n;x++)
#define rep1n for(int x=1;x<=n;x++)
#define rep1m for(int y=1;y<=m;y++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define precise(x) cout << fixed << setprecision(x)
#define bits(x) __builtin_popcount(x)
#define pb push_back
#define mp make_pair
#define test int t; cin>>t; while(t--)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;


void __print(int x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void debarr(int arr[] , int n){
    cout << "arr : ";
    rep(i,0,n-1) cout << arr[i] << " ";     cout << '\n';
}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
const int mod = 1e9+7;
const int inf = 1e18;
const int N = 2e5 + 100;

set< pii > not_allowed;
set<int> to_process;

vi comp;
int cc = 0;
vector< vi > comps;

bool allowed_to_take(int a , int b){

     if(a > b) swap(a , b);

     if(not_allowed.find({a , b}) == not_allowed.end())
          return true;

     return false;

}

void dfs(int node){

     comp.push_back(node);
     vector<int> adj_of_node;

     for(auto x : to_process){
          if(allowed_to_take(node , x))
               adj_of_node.push_back(x);
     }

     for(auto adj : adj_of_node){
          to_process.erase(adj);
     }

     for(auto adj : adj_of_node)
          dfs(adj);


}

int32_t main(){
     FAST;

     int n , m;     cin >> n >> m;

     rep1n to_process.insert(x);

     rep1m{
          int u, v; cin >> u >> v;
          if(u > v) swap(u , v);
          not_allowed.insert({u , v});
     }

     rep1n{
          int node = x;
          if(to_process.find(node) != to_process.end()){

               
               to_process.erase(node);
               dfs(node);
               cc++;
               comps.push_back(comp);
               comp.clear();

          }
     }


     cout << comps.size() << endl;

     for(auto &ch : comps){
          cout << ch.size() << " ";
          for(auto &xx : ch)
               cout << xx << " ";
          cout << endl;
     }



    return 0;
}



