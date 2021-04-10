#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long;

ll f(vector<ll> & P, vector<ll> & N, int idx, ll sum, ll a, ll b) {
  if (idx == P.size()) {
    if (a == b) return a;
    else return 0;
  }
  ll p = P[idx];
  ll n = N[idx];
  ll da = p * n;
  ll db = 1;
  ll val = 0;
  for (ll e = 0; e <= n; e++) {
    val = max(val, f(P, N, idx + 1, sum, a + da, b * db));
    da -= p;
    db *= p;
    if (b * db > sum) break;
  }
  return val;
}

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    int M;
    cin >> M;
    vector<ll> P(M), N(M);
    REP(i, M) cin >> P[i] >> N[i];

    ll ok = 1;
    ll ng = 1 << 60;

    while (ng - ok > 1) {
      ll x = (ok + ng) / 2;
    }

    // vector<ll> ps;
    ll sum = 0;
    REP(i, M) {
      // REP(_, N[i]) ps.push_back(P[i]);
      sum += P[i] * N[i];
    }
    ll ans = f(P, N, 0, sum, 0, 1);
    cout << "Case #" << (t + 1) << ": " << ans << "\n";
  }
}
