//PCK9問目　プログラミングコンテスト2のソースコード
#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef pair<int64,int> PD;
#define F first
#define S second
#define pb push_back

vector< PD >rank;

struct BIT
{
  int size;
  vector<int64>trs;
  BIT(int sz){
    trs.assign(sz + 810,0); //適当にyjsnpiとっとく
    size = sz + 809;
  }
  void add(int k,int x){
    for(++k;k <= size;k += k & -k)trs[k] += x;
  }
  int submit(int k){
    int64 ret = 0;
    for(++k;k > 0;k -= k & -k)ret += trs[k];
    return ret;
  }
  
};
  
int place(int64 point,int w)
{
  return lower_bound(rank.begin(),rank.end(),make_pair(point,w) ) - rank.begin();
}

int main()
{
  int N,C;
  cin >> N >> C;
  int query[100000],a[100000],b[100000];
  int64 point[100000] = {0};
  for(int i = 0;i < N;i++)rank.pb(PD(0,-i));
  for(int i = 0;i < C;i++){
    cin >> query[i];
    if(query[i] == 0){
      cin >> a[i] >> b[i]; a[i]--;
      point[a[i]] += b[i];
      rank.pb(PD(point[a[i]],-a[i]));
    } else {
      cin >> a[i];
    }
  }
  sort(rank.begin(),rank.end());
  rank.erase(unique(rank.begin(),rank.end()),rank.end());

  BIT tree(rank.size());
  memset(point,0,sizeof(point));
  for(int i = 0;i < N;i++){
    tree.add(i,1);
  }
  for(int i = 0;i < C;i++){
    if(query[i] == 0) {
      tree.add(place(point[a[i]],-a[i]), -1);
      point[a[i]] += b[i];
      tree.add(place(point[a[i]],-a[i]),1);
    } else {
      int high = rank.size() - 1,low = -1;
      while(high > low + 1){
	int mid = (high + low) >> 1;
	if(tree.submit(mid) >= N - a[i] + 1)high = mid;
	else low = mid;
      }
      cout << -rank[high].S + 1 << " " << rank[high].F << endl;
    }
  }
  return 0;
}  
