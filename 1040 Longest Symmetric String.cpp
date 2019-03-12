/**
 * ˼���ǶԳƳ�����1��ʼ��������������л�������������ĵ㡣����ʱ�临�Ӷ�
 * �������Ľⷨ��һ�㡣
 * */
#include <iostream>
#include <vector>
using namespace std;
int main(){
    char s[1001];
    int n = 0, oddans = 1, evenans = 0;
    vector<int> odd, even;
    scanf("%c", &s[n]);
    while(s[n] != '\n'){
        scanf("%c", &s[++n]);
        odd.push_back(n - 1);
    }
    while(!odd.empty()){
        vector<int> tmp;
        for(int i = 0; i < odd.size(); i++){
            if(odd[i] - oddans < 0 || odd[i] + oddans >= n)
                continue;
            if(s[odd[i] - oddans] == s[odd[i] + oddans])
                tmp.push_back(odd[i]);
        }
        odd = tmp;
        oddans++;
    }
    for(int i = 0; i < n - 1; i++)
        if(s[i] == s[i + 1]){
            even.push_back(i);
            evenans = 1;
        }
    while(!even.empty() && evenans){
        vector<int> tmp;
        for(int i = 0; i < even.size(); i++){
            if(even[i] - evenans < 0 || even[i] + 1 + evenans >= n)
                continue;
            if(s[even[i] - evenans] == s[even[i] + 1 + evenans])
                tmp.push_back(even[i]);
        }
        even = tmp;
        evenans++;
    }
    printf("%d", max(evenans * 2 - 2, oddans * 2 - 3));
}
/*
//��ǰ�õķ�������ÿ���ַ�Ϊ���ĵ㣬�������չ��������������еļ���case�������
//�ⷨ��Ҫ��һ�㡣��������ʱ�临�ӶȴﵽO(n^2)
#include<iostream>
using namespace std;
char str[1001];
int checksymodd(int n) {
	int i = 0;
	while (1) {
		if (n < i || i + n>1000)return 2 * i + 1;
		if (str[n - i - 1] == str[n + i + 1]) {
			i++;
		}
		else {
			return 2*i + 1;
		};
	}
}
int checksymeven(int n) {
	int i = 0;
	while (1) {
		if (n < i || n + i > 1000)return 2 * i;
		if (str[n - i] == str[n + i + 1])i++;
		else return 2 * i;
	}
}
int main() {
	int i = 0, j, k = 0, n, max = 1;
	while (1) {
		str[i] = getchar();
		if ( str[i] != '\n')i++;
		else break;
	}
	n = i;
	for (i = 0; i < n; i++) {
		k = checksymodd(i);
	    j = checksymeven(i);
		if (k > max)max = k;
		if (j > max)max = j;
	}
	cout << max;
}
*/