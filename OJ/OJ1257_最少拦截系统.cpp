#include <iostream>
#include <climits>
using namespace std;
const int MAXNUM = 100000;
//height[i]记录第i套防空系统的目前最低高度。
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
				//对于第i枚导弹，如果有系统可以拦截它，找出性能损失最小（降低可拦截高度）的系统。
				if (height[j] >= missile[i]){
					if (height[j] <= minHeight){
						minHeight = height[j];
						targetSys = j;
					}
				}
			}
			//如果找到了能拦截导弹的系统，改变它的可拦截高度。
			if (targetSys != -1){
				height[targetSys] = missile[i];
			}
			//否则，新增一个拦截系统，设置可拦截高度。
			else{
				height[num] = missile[i];
				num++;
			}
		}
		cout << num << endl;
	}
}