//Kosaraju Algorithm for finding scc (strongly connected component) in directed graph.

//Lose Yourself
#include <bits/stdc++.h>

using namespace std;

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long int
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define debug(x) cout << #x << "=" << x << endl
#define debug_2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define fastio \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

const int MOD = 1000000007;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}   
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
string tostring(int number){stringstream ss; ss<<number; return ss.str();}

int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % MOD;
        base = ((ll)base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

const int maxm=1e6+1;
vector<bool> is_prime(maxm, true);
 
void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxm; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxm; j += i)
            is_prime[j] = false;
       }
    }
}

vvi adj(100005), rev(100005);
int vis[100005], n, m;
stack<int> s;
void dfs1(int u) {
    for (auto v : adj[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            dfs1(v);
        }
    }
    s.push(u);
}

void dfs2(int u) {
    for (auto v : rev[u]) {
        if (!vis[v]) {
            vis[v] = 1;
            dfs2(v);
        }
    }
    // s.push(u);
}

void reverse() {
    for (int i = 1; i <= n; i++) {
        for (auto v : adj[i]) {
            rev[v].pb(i);
        }
    }
}

void kosaraju() {
    cin >> n >> m;
    adj.clear();
    rev.clear();
    memset(vis, 0, sizeof(vis));
    fo (i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs1(i);
        }
    }
    reverse();
    int connected_component = 0;
    fo (i, n) vis[i+1] = 0;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        if (!vis[u]) {
            connected_component++;
            dfs2(u);
        }
    }

}

int main() {
    fastio;
    #ifndef ONLINE_JUDGE
    input_stream;
    #endif
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}