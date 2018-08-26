/**
 * 排序，再次证明了合适的数据存储方式的重要性。合理运用struct和sort可以事半功倍
 * 感觉L大佬的解法还没我的优雅233333333不过我的代码看起来好丑。
 * 思路：利用一个struct存student的信息，输入完一个组就进行组内排序。然后对整个
 * 排序。反正组内排序只是为了得到一个g rank值，和其他没关系。
 * */
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct Stu{
    char name[14];
    int group, score, grank, frank;
} Stu;
Stu stu[301*101];
bool cmp(Stu a, Stu b){
    if(a.score == b.score){
        for(int i = 0; i<13; i++){
            if(a.name[i] < b.name[i])return true;
            if(a.name[i] > b.name[i])return false;
        }
    }
    return a.score > b.score;
}
int main() {
    int n, k;
    scanf("%d", &n);
    int id = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &k);
        char name[14];
        int score;
        int a = id;
        for(int j = 0; j<k; j++){
            scanf("%s %d", name, &score);
            stu[id].group = i + 1;
            stu[id].score = score;
            strcpy(stu[id].name, name);
            id ++;
        }
        int b = id;
        sort(stu + a, stu + b, cmp);
        int grank = 0;
        score = -1;
        for(int j = a; j<b; j++){
            if(score != stu[j].score){
                stu[j].grank = j - a + 1;
                grank = j - a + 1;
                score = stu[j].score;
            }
            else
                stu[j].grank = grank;
        }
    }
    sort(stu, stu + id, cmp);
    int frank = 0;
    int score = -1;
    for(int j = 0; j<id; j++){
        if(score != stu[j].score){
            stu[j].frank = j + 1;
            frank = j + 1;
            score = stu[j].score;
        }
        else
            stu[j].frank = frank;
    }
    printf("%d", id);
    for(int i = 0; i<id; i++){
        printf("\n%s %d %d %d", stu[i].name, stu[i].frank, stu[i].group, stu[i].grank);
    }
}