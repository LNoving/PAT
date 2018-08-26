#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main() {
	int n;
	cin >> n;
    string in, out, tmp;
    string ansin, ansout;
    int tin = 1000000;
    int tout = 0;
    int time;
	for( int i = 0; i<n; i++){
        cin >> tmp;
        cin >> in;
        time = (in[0] - '0') * 100000 + (in[1] - '0') * 10000 + (in[3] - '0')* 1000 + (in[4] - '0')* 100 + (in[6] - '0') * 10 + (in[7] - '0');
        if( time < tin){
            tin = time;
            ansin = tmp;
        }
        cin >> out;
        time = (out[0] - '0') * 100000 + (out[1] - '0') * 10000 + (out[3] - '0')* 1000 + (out[4] - '0')* 100 + (out[6] - '0') * 10 + (out[7] - '0');
        if( time > tout){
            tout = time;
            ansout = tmp;
        }
	}
	cout << ansin+" "+ansout ;
}
