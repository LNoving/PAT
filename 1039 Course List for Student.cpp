/**一个很大的vector<int>数组 v[]来存放信息。注意为了逻辑简单，按照输出的 要求
存放信息。要求输出学生选的课程，就按学生来存。注意，这里的hash只是一个容器，
只需要把名字hash掉，然后存进去，根本不需要根据hash值算名字。
最后一个case170ms过的，限制200ms，还是挺危险。
*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;
const int maxn = 26 * 26 * 26 * 10 + 10;
vector<int> v[maxn];
int gethash(char* name){
    int ans = (int)(name[0] - 'A');
    ans *= 26;
    ans += (int)(name[1] - 'A');
    ans *= 26;
    ans += (int)(name[2] - 'A');
    ans *= 10;
    ans += (int)(name[3] - '0');
    return ans;
}
int main(){
    scanf("%d %d", &n, &k);
    char name[5];
    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        for(int j = 0; j<b; j++){
            scanf("%s", &name);
            v[gethash(name)].push_back(a);
        }
    }
    for(int i = 0; i<n; i++){
        scanf("%s", &name);
        int h = gethash(name);
        printf("%s %d", name,v[h].size());
        std::sort(v[h].begin(),v[h].end());  ///sort的用法
        for(int j = 0; j< v[h].size(); j++){
            printf(" %d", v[h][j]);
        }
        printf("\n");
    }
}
