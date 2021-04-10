#include <iostream>
#include <vector>
#include <algorithm>

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
      int m = 0;
      REP(i, Q) if (A[0][i] == A[1][i]) m += 1;
      int x = (S[0] + S[1] + m - Q) / 2;
      // cerr << "x: " << x << "\n";
      bool mf = x < m - x;
      // cerr << "mf: " << mf << "\n";
      int mi = max_element(S.begin(), S.end()) - S.begin();
      REP(i, Q) {
        if (A[0][i] == A[1][i]) cout << (mf ? A[mi][i] == 'T' ? 'F' : 'T' : A[mi][i]);
        else cout << A[mi][i];
      }
      cout << " " << (mf ? S[mi] - x + (m - x) : S[mi]) << "/" << 1;
    }
    cout << "\n";
  }
}
