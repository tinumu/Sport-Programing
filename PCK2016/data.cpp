#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define Pi pair<int,int>
#define Pii pair<Pi,int>
int main(){
  vector<Pii>v;
  int d[3];
  int N;cin >> N;
  for(int i = 0;i < N;i++){
    cin >> d[0] >> d[1] >> d[2];
    sort(d,d + 3);
    Pii t;
    t.F.F = d[0];t.F.S = d[1],t.S = d[2];
    v.pb(t);
  }
  sort(v.begin(),v.end());
  int a = v.size();
  v.erase(unique(v.begin(),v.end()),v.end());
  int b = v.size();
  cout << a - b << endl;
  return 0;
}
