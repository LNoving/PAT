/**
 * ���Ǻܷ��˵�һ���⡣
 *  It is guaranteed that all the integers are in the range of long int.����ƭ�˵ģ�
 * ��ֻ��int���ѡ�������Ϊ�˹�case��д�Ĵ��롣
 * */
#include <iostream>
using namespace std;
int arr[200001], tmp;
int main(){
    int n1, n2, k = 0;
    cin >> n1;
    for(int i = 0; i < n1; i++)
        scanf("%d", &arr[i]);
    cin >> n2;
    int mid = (n1 + n2 + 1) / 2;
    for(int i = 0; i < n2; i++){
        scanf("%d", &tmp);
        while(k < n1 && arr[k] < tmp){
            if(k + i + 1 == mid){
                cout << arr[k] << endl;
                return 0;
            }
            k++;
        }
        if(k + i + 1 == mid){
            cout << tmp << endl;
            return 0;
        }
    }
    while(k < n1){
        if(k + n2 + 1 == mid){
            cout << arr[k] << endl;
            return 0;
        }
        k++;
    }
}
