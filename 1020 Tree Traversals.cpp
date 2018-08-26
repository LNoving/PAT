/**
* 优雅的一匹，被我自己帅到了。当然套路还是学的。关键点是递归的地方搞清楚节点的
* 个数，左边多少个，右边多少个。理清思路。边界情况，出口判断还是记一下人家的套
* 路，自己动脑筋想挺麻烦，还容易出bug。比如if(lin > rin)return;就很重要。平时
* 训练的时候要多思考边界情况
*/
#include <cstdio>
#include <vector>
using namespace std;
int n, post[30], in[30], pre[30], level = 0;
vector <int> ans[30];
void fpre(int lin, int rin, int node) {
	if (lin > rin)return;
	int i = lin;
	while (in[i] != post[node]) i++;
	ans[level++].push_back(in[i]);
	fpre(lin, i - 1, node - (rin - i) - 1);
	fpre(i + 1, rin, node - 1);
	level--;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i<n; i++) scanf("%d", post + i);
	for (int i = 0; i<n; i++)scanf("%d", in + i);
	fpre(0, n - 1, n - 1);
	for (int i = 0; ans[i].size() != 0; i++) {
		for (int j = 0; j<ans[i].size(); j++) {
			if (i + j)printf(" ");
			printf("%d", ans[i][j]);
		}
	}
}