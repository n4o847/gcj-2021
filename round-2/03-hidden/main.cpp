#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long;

int main() {
  const ll M = 1000000007;
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    ll ans = 0;
    ll N;
    cin >> N;
    vector<ll> V(N);
    REP(i, N) cin >> V[i];
    vector<ll> P(N);
    REP(i, N) P[i] = i + 1;
    do {
      stack<ll> S;
      bool f = true;
      REP(i, N) {
        while (S.size() && S.top() < P[i]) {
          S.pop();
        }
        S.push(P[i]);
        if (V[i] != S.size()) {
          f = false;
          break;
        }
      }
      if (f) {
        (ans += 1) %= M;
      }
    } while (next_permutation(P.begin(), P.end()));
    cout << "Case #" << t << ": " << ans << "\n";
  }
}
