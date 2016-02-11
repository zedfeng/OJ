#include <iostream>
using namespace std;
const int LEN = 100000;
int main(){
	int T;
	int start, end, maxsum;
	cin >> T;
	for (int i = 1; i <= T; i++){
		int N;
		cin >> N;
		int* p = new int[N];
		for (int j = 0; j < N; j++){
			cin >> p[j];
		}
		int tempstart, tempend, tempsum;
		start = end = tempstart = tempend = 0;
		tempsum = maxsum = p[0];
		for (int m = 1; m < N; m++){
			if (tempsum > 0){
				tempsum += p[m];
				tempend = m;
			}
			else{
				tempsum = p[m];
				tempstart = m;
				tempend = m;
			}
			if (tempsum > maxsum){
				maxsum = tempsum;
				start = tempstart;
				end = tempend;
			}
		}
		cout << "Case " << i << ":" << endl;
		cout << maxsum << " " << start+1 << " " << end+1 << endl;
		if (i < T){
			cout << endl;
		}
	}
	return 0;
}