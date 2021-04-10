#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T;
  cin >> T;
  REP(_, T) {
    int X, Y;
    string S;
    cin >> X >> Y >> S;
    int N = S.size();
    int INF = 1 << 30;
    vector<int> C(N + 1, INF);
    vector<int> J(N + 1, INF);
    C[0] = 0;
    J[0] = 0;
    REP(i, S.size()) {
      if (S[i] == 'C') {
        C[i + 1] = min(C[i], J[i] + Y);
      } else if (S[i] == 'J') {
        J[i + 1] = min(J[i], C[i] + X);
      } else {
        C[i + 1] = min(C[i], J[i] + Y);
        J[i + 1] = min(J[i], C[i] + X);
      }
    }
    int ans = min(C[N], J[N]);
    cout << "Case #" << (_ + 1) << ": " << ans << "\n";
  }
}
