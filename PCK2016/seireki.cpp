#include <bits/stdc++.h>
using namespace std;
int main(){
  int tosi[5] = {0,1867,1911,1925,1988};
  char moji[5] = {' ','M','T','S','H'};
  int E,Y; cin >> E >> Y;
  if(!E){
    int i = 5;
    while(i--){
      if(tosi[i] < Y){
	cout << (char)moji[i] << Y - tosi[i] << endl;
	break;
      }
    }
  }else cout << tosi[E] + Y << endl;
  return 0;
}
