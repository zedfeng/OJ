#include <iostream>
#include <climits>
using namespace std;
const int MAXNUM = 100000;
//height[i]��¼��i�׷���ϵͳ��Ŀǰ��͸߶ȡ�
int missile[MAXNUM], height[MAXNUM];
int main(){
	int n;
	while (cin >> n){
		int num, minHeight, targetSys;
		for (int i = 0; i < n; i++){
			cin >> missile[i];
		}
		height[0] = missile[0];
		num = 1;
		for (int i = 1; i < n; i++){
			minHeight = INT_MAX;
			targetSys = -1;
			for (int j = 0; j < num; j++){
				//���ڵ�iö�����������ϵͳ�������������ҳ�������ʧ��С�����Ϳ����ظ߶ȣ���ϵͳ��
				if (height[j] >= missile[i]){
					if (height[j] <= minHeight){
						minHeight = height[j];
						targetSys = j;
					}
				}
			}
			//����ҵ��������ص�����ϵͳ���ı����Ŀ����ظ߶ȡ�
			if (targetSys != -1){
				height[targetSys] = missile[i];
			}
			//��������һ������ϵͳ�����ÿ����ظ߶ȡ�
			else{
				height[num] = missile[i];
				num++;
			}
		}
		cout << num << endl;
	}
}