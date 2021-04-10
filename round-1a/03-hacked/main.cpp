#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;
using ll = long long;

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << (t + 1) << ": ";
    int N, Q;
    cin >> N >> Q;
    vector<string> A(N);
    vector<int> S(N);
    REP(i, N) cin >> A[i] >> S[i];
    if (N == 1) {
      cout << A[0] << " " << S[0] << "/" << 1;
    } else if (N == 2) {
      vector<ll> tc(Q);
      vector<ll> fc(Q);
      ll cnt = 0;
      REP(b, 1LL << Q) {
        int s0 = 0;
        REP(i, Q) if ((A[0][i] == 'T') == (((b >> i) & 1) == 1)) s0 += 1;
        if (s0 != S[0]) continue;
        int s1 = 0;
        REP(i, Q) if ((A[1][i] == 'T') == (((b >> i) & 1) == 1)) s1 += 1;
        if (s1 != S[1]) continue;
        REP(i, Q) {
          if ((((b >> i) & 1) == 1)) tc[i] += 1;
          else fc[i] += 1;
        }
        cnt += 1;
      }
      REP(i, Q) cout << (tc[i] >= fc[i] ? 'T' : 'F');
      ll crr = 0;
      REP(i, Q) crr += max(tc[i], fc[i]);
      ll g = gcd(crr, cnt);
      // cerr << "crr: " << crr << ", cnt: " << cnt << "\n";
      // cerr << "g: " << g << "\n";
      cout << " " << (crr / g) << "/" << (cnt / g);
    }
    cout << "\n";
  }
}
