#include <iostream>
#include <climits>
using namespace std;
const int MAXLEN = 10000;
int num[MAXLEN], maxSub[MAXLEN], maxSubStart[MAXLEN];
int main(){
	int K;
	while (cin >> K&&K != 0){
		for (int i = 0; i < K; i++){
			cin >> num[i];
		}
		maxSub[0] = num[0];
		maxSubStart[0] = 0;
		for (int i = 1; i < K; i++){
			if (maxSub[i - 1] > 0){
				maxSub[i] = maxSub[i - 1] + num[i];
				maxSubStart[i] = maxSubStart[i - 1];
			}
			else{
				maxSub[i] = num[i];
				maxSubStart[i] = i;
			}
		}
		int max = INT_MIN, start, end;
		for (int i = 0; i < K; i++){
			if (maxSub[i]>max){
				max = maxSub[i];
				start = num[maxSubStart[i]];
				end = num[i];
			}
		}
		if (max < 0){
			cout << 0 << " " << num[0] << " " << num[K - 1] << endl;
		}
		else{
			cout << max << " " << start << " " << end << endl;
		}
	}
}