/**
 * 注意子序列可以缺项。题目里没有明确说明这一点，在这一点上浪费了很多时间。
 * 时间复杂度大概是 o(m * l) 其实时间复杂度还能再小一点，用一个color到序号的
 * 映射，可以做到接近o(l) 经测试case 3 和case 4 比大佬的解法还是快了很多的。
 * 做的过程中疏忽了的一点是即使当前不匹配，当前长度也可能因为前面序列长度的增加
 * 而增加
 * */
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, l, last[201], cur[201], fav[201], strip, ans;
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> fav[i];
    cin >> l;
    fill(last, last + 201, 0);
    fill(cur, cur + 201, 0);
    for(int i = 0; i < l; i++){
        cin >> strip;
        for(int j = 0; j < m; j++){
            if(strip == fav[j]){
                if(j > 0){
                    if(cur[j - 1] != 0)
                        cur[j] = max(last[j - 1] + 1, last[j] + 1);
                }
                else
                    cur[j] = last[j] + 1;
            }
            else
                cur[j] = max(cur[j - 1], last[j]);
        }
        for(int j = 0; j < m; j++)
            last[j] = cur[j];
    }
    cout << last[m - 1];
}
