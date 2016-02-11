#include<iostream>
using namespace std;
int main(){
	int n, u, d;
	while (cin >> n >> u >> d){
		if (n == 0 && u == 0 && d == 0){
			break;
		}
		int time = 0, cur_height = 0;
		while (cur_height < n){
			time++;
			cur_height += u;
			if (cur_height >= n){
				break;
			}
			time++;
			cur_height -= d;
		}
		cout << time << endl;
	}
	return 0;
}