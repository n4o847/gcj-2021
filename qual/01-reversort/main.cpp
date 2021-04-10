#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T;
  cin >> T;
  REP(_, T) {
    int N;
    cin >> N;
    vector<int> L(N);
    REP(i, N) cin >> L[i];
    int ans = 0;
    REP(i, N - 1) {
      auto pos = find(L.begin() + i, L.end(), i + 1);
      int j = pos - L.begin();
      ans += j - i + 1;
      reverse(L.begin() + i, pos + 1);
    }
    cout << "Case #" << (_ + 1) << ": " << ans << "\n";
  }
}
