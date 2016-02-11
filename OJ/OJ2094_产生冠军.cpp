#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
	int n;
	string win, lose;
	while (cin >> n){
		if (n == 0){
			break;
		}
		set<string> player, loser;
		for (int i = 0; i < n; i++){
			cin >> win >> lose;
			player.insert(win);
			player.insert(lose);
			loser.insert(lose);
		}
		cout << (player.size() == loser.size() + 1 ? "Yes" : "No") << endl;
	}
	return 0;
}