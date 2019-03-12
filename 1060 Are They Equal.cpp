/**
 * 这道题还是挺恶心的。思路要正确， 一开始就要用字符串去做而不是浮点数。否则倒数第二个case过不了
 * */
#include <iostream>
using namespace std;
int main(){
    int n, dota = 0, dotb = 0, indexa = 0, indexb = 0, expa, expb;
    string a, b, aa = "", bb = "";
    cin >> n >> a >> b;
    while(dota < a.length() && a[dota] != '.') dota++;
    while(dotb < b.length() && b[dotb] != '.') dotb++;
    while(indexa < a.length() && (a[indexa] == '0' || a[indexa] == '.')) indexa++;
    while(indexb < b.length() && (b[indexb] == '0' || b[indexb] == '.')) indexb++;
    expa = indexa == a.length() ? -1 : dota >= indexa ? dota - indexa - 1 : dota - indexa;
    expb = indexb == b.length() ? -1 : dotb >= indexb ? dotb - indexb - 1 : dotb - indexb;
    while(aa.length() < n){
        if(indexa < a.length()){
            if(a[indexa] != '.')
                aa += a[indexa];
        }
        else
            aa += '0';
        indexa++;
    }
    while(bb.length() < n){
        if(indexb < b.length()){
            if(b[indexb] != '.')
                bb += b[indexb];
        }
        else
            bb += '0';
        indexb++;
    }
    if(aa == bb && expa == expb){
        cout << "YES 0." << aa << "*10^" << expa + 1;
    }
    else{
        cout << "NO 0." << aa << "*10^" << expa + 1 << " 0." << bb << "*10^" << expb + 1;
    }
}
