/**
* ���ŵ�һƥ�������Լ�˧���ˡ���Ȼ��·����ѧ�ġ��ؼ����ǵݹ�ĵط�������ڵ��
* ��������߶��ٸ����ұ߶��ٸ�������˼·���߽�����������жϻ��Ǽ�һ���˼ҵ���
* ·���Լ����Խ���ͦ�鷳�������׳�bug������if(lin > rin)return;�ͺ���Ҫ��ƽʱ
* ѵ����ʱ��Ҫ��˼���߽����
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