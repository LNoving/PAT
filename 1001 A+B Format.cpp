#include <iostream>
using namespace std;
int main(){
  int a, b;
  cin >> a >> b;
  int c = a + b;
  string s = to_string(c);
  int l = s.length();
  for (int i = 0; i<l; i++){
    cout << s[i];
    if( s[i] == '-')
      continue;
    else if ( (l - i - 1)% 3 == 0 && i !=  l - 1)
      cout << "," ;
  }
}
