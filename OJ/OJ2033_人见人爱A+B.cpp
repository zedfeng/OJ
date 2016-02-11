#include<iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	while (n--){
		int ah, am, as, bh, bm, bs;
		cin >> ah >> am >> as >> bh >> bm >> bs;
		int rh, rm, rs;
		rs = (as + bs) % 60;
		rm = ((as + bs) / 60 + am + bm) % 60;
		rh = ((as + bs) / 60 + am + bm) / 60 + ah + bh;
		cout << rh << " " << rm << " " << rs << endl;
	}
	return 0;
}