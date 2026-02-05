/*
    Author: Devexh
    Created: Thursday, 05.02.2026 06:19 PM (GMT+5:30)
*/

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

#ifdef DEVEX
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve() {
    ll n; cin >> n;
    vector<ll> x(n), y(n);
    for (auto &i : x) cin >> i;
    for (auto &i : y) cin >> i;
    vector<pair<ll, int>> v(n);
    for (int i = 0; i < n; i++) v[i] = {y[i] - x[i], i};
    sort(v.rbegin(), v.rend());
    int l = 0, r = n - 1, ans = 0;
    while (l < r) {
        if (y[v[l].second] + y[v[r].second] >= x[v[l].second] + x[v[r].second]) {
            ans++; l++; r--;
        } else {
            r--;
        }
    }
    cout << ans << nl;
}

int32_t main() {
#ifdef DEVEX
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start = high_resolution_clock::now();
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
#ifdef DEVEX
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}