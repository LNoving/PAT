/***
 * �ܾ���ǰ�����������Դ�������Ľⷨ����ʵ��������ת��������Ҫ��ѧϰ�ֳɵ���·��
 * ���ܹ⿿�Լ���
 */ 
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
