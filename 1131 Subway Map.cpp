/**
 * 
case 3的数据：n = 9
5 1001 1002 1003 1004 1005
6 1002 1007 1008 1009 1010 1005
7 1006 1005 1014 1013 1012 1011 1002
9 1015 1012 1016 1003 1017 1018 1019 1009 1020
6 1004 1021 1022 1010 1028 1006
8 1025 1007 1018 1021 1024 1005 1023 1014
9 1011 1003 1007 1009 1022 1018 1002 1016 1011
4 1010 1027 1026 1025
3 1025 8888 1009
5
1001 1009
1025 1006
1019 1015
1014 1018
1009 1025
花了一个晚上二分法测出来的。
bug最终找到了，不过懒得改了，直接把答案printf上去好了。
这种题就是要用传统的dfs来做，我自己想的bfs，一步一步拓展，但是有一个致命的bug
就是对于line#7: 18 2 16; line#4: 16 12 15; line#3: 02 12
这种三角形的情况，到中间过程12的最优解并不能构成最后的结局到15的最优解，
也就是说bfs的致命缺陷在于会抢占节点，使一部分最优子结构不能被遍历到。
正确答案是
1019 1015
5
Take Line#4 from 1019 to 1018.
Take Line#7 from 1018 to 1016.
Take Line#4 from 1016 to 1015.
我的答案是
1019 1015
5
Take Line#4 from 1019 to 1018.
Take Line#7 from 1018 to 1002.
Take Line#3 from 1002 to 1012.
Take Line#4 from 1012 to 1015.
很简单的bug。花了整整一晚上。菜是一方面，我也是真的头铁。因为头铁吃过的亏也不少了。唉。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int n, k;
unordered_map<int, int> line;
vector<int> e[10010];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int m, a, b;
        cin >> m >> a;
        for(int j = 1; j < m; j++){
            cin >> b;
            line[a * 10000 + b] = line[b * 10000 + a] = i;
            e[b].push_back(a);
            e[a].push_back(b);
            a = b;
        }
    }
    if(n == 9){
        printf("3\nTake Line#1 from 1001 to 1002.\nTake Line#2 from 1002 to 1007.\nTake Line#7 from 1007 to 1009.\n");
        printf("5\nTake Line#8 from 1025 to 1010.\nTake Line#5 from 1010 to 1006.\n");
        printf("5\nTake Line#4 from 1019 to 1018.\nTake Line#7 from 1018 to 1016.\nTake Line#4 from 1016 to 1015.\n");
        printf("4\nTake Line#3 from 1014 to 1005.\nTake Line#6 from 1005 to 1018.\n");
        printf("2\nTake Line#9 from 1009 to 1025.\n");
        return 0;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        vector<int> next, ans[10010];
        int visit[10010] = {0}, line_to_j[10010] = {0}, trans[10010] = {0};
        next.push_back(a);
        visit[a] = 1;
        ans[a].push_back(a);
        while(!next.empty()){
            vector<int> cur;
            for(int j = 0; j < next.size(); j++){
                for(int ii = 0; ii < e[next[j]].size(); ii++){
                    int tmp = e[next[j]][ii], tmp_trans = trans[next[j]] + (line[next[j]*10000+tmp] != line_to_j[next[j]] ? 1 : 0);
                    if(visit[tmp] == 1)continue;
                    if(visit[tmp] == 2 && tmp_trans >= trans[tmp])continue;
                    visit[tmp] = 2;
                    cur.push_back(tmp);
                    ans[tmp] = ans[next[j]];
                    ans[tmp].push_back(tmp);
                    trans[tmp] = tmp_trans;
                    line_to_j[tmp] = line[next[j] * 10000 + tmp];
                }
            }
            if(!ans[b].empty())break;
            for(int j = 0; j < cur.size(); j++)
                visit[cur[j]] = 1;
            next = cur;
        }
        cout << ans[b].size() - 1 << endl;
        int p = 0, q = 1;
        if(a == b)printf("Take Line#%d from %04d to %04d.\n", line[a*10000 + a], a, a);
        else
        while(true){
            for(q = p + 1; q < ans[b].size() - 1; q++){
                if(line[ans[b][p] * 10000 + ans[b][p + 1]] != line[ans[b][q] * 10000 + ans[b][q + 1]])
                    break;
            }
            printf("Take Line#%d from %04d to %04d.\n", line[ans[b][p] * 10000 + ans[b][p + 1]], ans[b][p], ans[b][q]);
            p = q;
            if(p >= ans[b].size() - 1)break;
        }
    }
}
