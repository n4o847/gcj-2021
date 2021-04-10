#include <iostream>
#include <vector>
#include <cassert>

#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int main() {
  int T, N, Q;
  cin >> T >> N >> Q;
  REP(_, T) {
    // メモ
    // 最初に2つ決める
    // すでに決まっている2つを適当に取り、
    // 新規と比較する
    // 三分探索になる
    vector<int> L {1, 2};
    for (int x = 3; x <= N; x++) {
      // x は L[lo] と L[hi] の間に入る
      // lo と hi が隣になるまでやる
      int lo = -1;
      int hi = L.size();
      while (hi - lo > 1) {
        int a = (lo * 2 + hi) / 3;
        int b = (lo + hi * 2) / 3;
        if (a == b) {
          if (a - 1 == -1) b++;
          else a--;
        }
        cout << L[a] << " " << x << " " << L[b] << endl;
        // cerr << "? " << L[a] << " " << x << " " << L[b] << endl;
        int c;
        cin >> c;
        // cerr << "! " << c << endl;
        if (c == L[a]) {
          hi = a;
        }
        if (c == x) {
          lo = a;
          hi = b;
        }
        if (c == L[b]) {
          lo = b;
        }
        // cerr << "lo: " << lo << ", hi: " << hi << endl;
      }
      L.insert(L.begin() + hi, x);
      // REP(i, L.size()) cerr << (i == 0 ? "" : " ") << L[i];
      // cerr << endl;
    }
    REP(i, N) cout << (i == 0 ? "" : " ") << L[i];
    cout << endl;
    int Z;
    cin >> Z;
    assert(Z == 1);
  }
}
