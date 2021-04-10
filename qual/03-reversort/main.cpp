#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T;
  cin >> T;
  REP(_, T) {
    cout << "Case #" << (_ + 1) << ": ";
    int N, C;
    cin >> N >> C;
    if (N - 1 <= C && C <= N * (N + 1) / 2 - 1) {
      vector<int> L(N);
      REP(i, N) L[i] = i + 1;
      REP(i, N - 1) {
        if (C >= (N - i) + (N - 2 - i)) {
          reverse(L.begin() + i, L.end());
          C -= N - i;
        } else {
          C -= 1;
        }
      }
      assert(C == 0);
      vector<int> R(N);
      REP(i, N) R[L[i] - 1] = i + 1;
      REP(i, N) cout << (i == 0 ? "" : " ") << R[i];
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << "\n";
  }
}
