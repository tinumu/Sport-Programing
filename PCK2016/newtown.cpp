#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a >> b >> c;
  int S = a * b;
  if(a < b)swap(a,b);
  while(b){
    int temp = a;
    a = b;
    b = temp % b;
  }
  cout << (S / (a * a)) * c << endl;
  return 0;
}
