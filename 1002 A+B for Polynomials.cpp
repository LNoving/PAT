#include <iostream>
using namespace std;
int main(){
  int n1, n2, p;
  float a1[1001]={0}, a2[1001] = {0}, ans[1001] = {0};
  cin >> n1 ;
  for(int i = 0; i < n1; i++){
    cin >> p;
    cin >> a1[p];
  }
  cin >> n2 ;
  for(int i = 0; i < n2; i++){
    cin >> p;
    cin >> a2[p];
  }
  int cnt = 0;
  for(int i = 0; i< 1001; i++){
    a2[i] = a1[i] + a2[i] ;
    if (a2[i] != 0){
      cnt ++;
    }
  }
  cout << cnt;
  for (int i = 1000; i >= 0 ;i--){
    if(a2[i] != 0){
      cout<<" ";
      cout << i ;
      cout <<" ";
      printf("%.1f", a2[i]);
    }
  }
}
