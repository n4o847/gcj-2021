#include <iostream>
#include <vector>
#include <string>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T;
  cin >> T;
  int P;
  cin >> P;
  REP(_, T) {
    vector<string> S(100);
    REP(i, 100) cin >> S[i];
    int ans = 0;
    cout << "Case #" << (_ + 1) << ": " << ans << "\n";
  }
}
