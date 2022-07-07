#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <list>

using namespace std;
using ll = long long;
#define pb push_back
#define ve vector
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; i--)
#define f first
#define se second
#define W while
#define um unordered_map
#define us unordered_set
#define be begin
#define en end

// Some predefined templates
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
  out << "[";
  bool first = true;
  for (auto v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const unordered_set<T> &a)
{
  out << "[";
  bool first = true;
  for (auto v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const set<T> &a)
{
  out << "[";
  bool first = true;
  for (auto v : a)
  {
    out << (first ? "" : ", ");
    out << v;
    first = 0;
  }
  out << "]";
  return out;
}

template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const map<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}

template <typename U, typename T, class Cmp>
ostream &operator<<(ostream &out, const unordered_map<U, T, Cmp> &a)
{
  out << "{";
  bool first = true;
  for (auto &p : a)
  {
    out << (first ? "" : ", ");
    out << p.first << ":" << p.second;
    first = 0;
  }
  out << "}";
  return out;
}


ll gcd(ll x, ll y)
{
  return (y == 0 ? x : gcd(y, x % y));
}
ll lcm(ll x, ll y)
{
  return x * y / gcd(x, y);
}

int to_int(string &s)
{
  int res = 0;
  for (char c : s)
  {
    res = res * 10 + (c - '0');
  }
  return res;
}

string substring(string& s, int l, int r) {
  string res = "";
  for(int i = l; i <= r; i++) res += s[i];
  return res;
}

/*class Compare
{
public:
    bool operator() (pair<int, int>& a, pair<int, int>& b)
    {
        return a.first > b.first;
    }
    //a[0] > b[0] : min
};*/


struct Tuple {
  int l, r, idx;
};

bool COMP(pair<int, int>& p1, pair<int, int>& p2) {
  return p1.first < p2.first;
}

bool COMP1(ve<int>& a, ve<int>& b) {
  //return p1.first < p2.first;
  for(int i = 0; i < a.size(); i++) {
    if(a[i] < b[i]) {
      return true;
    }
    if(a[i] > b[i]) {
      return false;
    }
  }
  return true;
}


int state[8][6] = {
  {1,1,1,1,1,1},
  {0,0,0,0,0,0},
  {1,0,1,0,1,0},
  {0,1,0,1,0,1},
  //do the [1, 4] flip
  {0,1,1,0,1,1},
  {1,0,0,1,0,0},
  {0,0,1,1,1,0},
  {1,1,0,0,0,1},
};

int a[105];
void solve() {
  int n;
  cin >> n;
  int K; cin >> K;
  memset(a, -1, sizeof(a));
  ve<int> on, off; //open close
  W(true) {
    int x;
    cin >> x;
    if(x == -1) break;
    on.pb(x - 1);
    a[x - 1] = 1;
  }

  W(true) {
    int x;
    cin >> x;
    if(x == -1) break;
    off.pb(x - 1);
    a[x - 1] = 0;
  }

  for(int i = 0; i < n; i++) {
    if(i + 6 < n && a[i] != a[i + 6] && a[i] != -1 && a[i + 6] != -1) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
  }

  ve<ve<int>> res;
  set<int> works[3];
  works[0].insert(0);
  works[1].insert(1);works[1].insert(2);works[1].insert(3);works[1].insert(4);
  works[2].insert(0);
  works[2].insert(1);
  works[2].insert(2);
  works[2].insert(3);
  works[2].insert(5);
  works[2].insert(6);
  works[2].insert(7);

  for(int i = 0; i < 8; i++) {
    if(K < 3 && works[K].find(i) == works[K].end()) continue;
    ve<int> b(n);
    for(int j = 0; j < n; j++) {
      b[j] = state[i][j % 6];
    }

    bool good = true;
    for(int j = 0; j < n; j++) {
      if(a[j] != -1 && a[j] != b[j]) {
        good = false;
      }
    }
    if(good) {
      res.pb(b);
    }
  }

  sort(res.begin(), res.end(), COMP1);

  if(res.size() == 0) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for(ve<int>& b : res) {
    for(int i : b) printf("%d", i);
    printf("\n");
  }

}

//思维题
int main()
{

  int t = 1;
  //cin >> t;
  W (t--)
  { 
    solve();
  }
  return 0;
}
