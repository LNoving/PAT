#include <iostream>
#include <vector>
using namespace std;
int pre[50001], in[50001], n;
int post(int inl, int inr, int k){
    if(inl > inr) return 0;
    int i = inl;
    while(in[i] != pre[k]) i++;
    if(post(inl, i - 1, k + 1) == 1) return 1;
    if(post(i + 1, inr, k + i - inl + 1) == 1) return 1;
    cout << pre[k];
    return 1;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &in[i]);
    post(0, n - 1, 0);
    return 0;
}

/***
 * 很久以前烧了两晚上脑袋想出来的解法。其实就是树的转换。还是要多学习现成的套路。
 * 不能光靠自己想。解法如下：
#include <iostream>
using namespace std;
int inn[50000], pre[50000], nnn;
int findd(int p, int q, int a);
int main()
{
	cin >> nnn;
	int p = 0, q = nnn - 1;
	for (int i = 0; i < nnn; i++) {
		cin >> pre[i];
	}
	for (int i = 0; i < nnn; i++) {
		cin >> inn[i];
	}
	cout << findd(p, q, 0);
    return 0;
}
int findd(int p, int q, int a) {
	int i;
	for (i = p; i < nnn; i++) {
		if (inn[i] == pre[a])
			break;
	}
	if (p == i && q == i)
		return inn[i];
	else if (p == i)
		return findd(i+1, q, a + 1);
	else
		return findd(p, i-1, a + 1);
}

*/