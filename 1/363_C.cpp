#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define null nullptr
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()
#define precise(x) cout << fixed << setprecision(x)
#define pb push_back
#define mp make_pair
#define test int t; cin>>t; while(t--)
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
 
using namespace std;
 
/*
It's been a long day without you, my friend
And I'll tell you all about it when I see you again
We've come a long way from where we began
Oh I'll tell you all about it when I see you again
When I see you again
When I see you again
*/
 
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
typedef unordered_map<int,int> mp;
 
const int mod = 1e9+7;
 
int sod(int n){int sum =0;while(n > 0){sum += n %10;n /= 10;}return sum;}
 
int dig(int n){int cnt =0;while(n > 0){n /= 10;cnt++;}return cnt;}
 
int divs(int n){int cnt = 0;for(int x=1;x*x<=n;x++){if(n % x == 0){cnt++;if(n/x != x)cnt++;}}return cnt;}
 
int isprime(int n){if(n < 2)return false;for(int x=2;x*x<=n;x++)if(n % x == 0) return false;return true;}
 
int power(int x,unsigned int y,int p=mod) {int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 
 
const int inf = 1e18;

bool comp(string fi , string se){
	return fi.size() < se.size();
}
 
 
int32_t main(){
    FAST;
 
    	 #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 	
 	string s;	cin >> s;
 	int n = s.size();
 	
 	vi freq;
 	vector<char> ch;
 	int cnt = 1;

 	for(int x=1;x<n;x++){
 		if(s[x] == s[x-1]){
 			cnt++;
 		}else{
 			freq.pb(cnt);
 			ch.pb(s[x-1]);
 			cnt = 1;
 		}
 	}


 	freq.pb(cnt);
 	ch.pb(s[s.size()-1]);

 	if(freq[0] >= 3)
 		freq[0] = 2;

 	for(int x=1;x<freq.size();x++){
 		int prev = freq[x-1];
 		int th = freq[x];

 		if(prev == 2){	
 			freq[x] = 1;

 		}else{
 			if(th == 1)	continue;
 			else if(th == 2)	continue;
 			else{
 				freq[x] = 2;
 			}
 		}
 	}

 	string ans;

 	for(int x=0;x<freq.size();x++){
 		int num = freq[x];
 		while(num--)
 			ans += (ch[x]);
 	}

 	cout << ans;

 
    return 0;
}
 
 
 
// const int N = 1e6;
// bool prime[N+3];
// void sieve(){
 
//   memset(prime , true , sizeof prime );
 
//   prime[0] = false , prime[1] = false;
//   prime[2] = true;
 
//   for(int x=2;x*x<=N;x++){
//     if(prime[x] == true){
//       for(int i=x*x;i<=N;i+=x)
//         prime[i] = false;
//     }
//   }
 
// } 