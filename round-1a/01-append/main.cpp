#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T;
  cin >> T;
  REP(t, T) {
    int N;
    cin >> N;
    vector<string> X(N);
    REP(i, N) cin >> X[i];
    int ans = 0;
    string prev = "";
    // int prev = 0;
    REP(i, N) {
      string x = X[i];
      if (prev.size() < x.size()) {
        prev = x;
        continue;
      } else if (prev.size() == x.size()) {
        if (stoll(prev) < stoll(x)) {
          prev = x;
          continue;
        } else {
          prev = x + "0";
          ans += 1;
          continue;
        }
      } else {
        REP(j, x.size()) {
          if (prev[j] > x[j]) {
            int add = prev.size() - x.size() + 1;
            ans += add;
            prev = x;
            REP(_, add) prev.push_back('0');
            goto done;
          }
          if (prev[j] < x[j]) {
            int add = prev.size() - x.size();
            ans += add;
            prev = x;
            REP(_, add) prev.push_back('0');
            goto done;
          }
        }
        {
          string prev_inc = to_string(stoll(prev) + 1);
          if (x == prev_inc.substr(0, x.size())) {
            int add = prev.size() - x.size();
            ans += add;
            prev = prev_inc;
            goto done;
          } else {
            int add = prev.size() - x.size() + 1;
            ans += add;
            prev = x;
            REP(_, add) prev.push_back('0');
            goto done;
          }
        }
        done:;
      }
    }
    cout << "Case #" << (t + 1) << ": " << ans << "\n";
  }
}
