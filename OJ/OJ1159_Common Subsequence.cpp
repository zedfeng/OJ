#include <iostream>
using namespace std;
const int LEN = 1001;	char s1[LEN], s2[LEN];
int maxSubStr[LEN + 1][LEN + 1];
int main(){
	while (cin >> s1 >> s2){
		memset(maxSubStr, 0, sizeof(maxSubStr));
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for (int i = 0; i < len1; i++){
			for (int j = 0; j < len2; j++){
				if (s1[i] == s2[j]){
					maxSubStr[i + 1][j + 1] = maxSubStr[i][j] + 1;
				}
				else{
					maxSubStr[i + 1][j + 1] = maxSubStr[i + 1][j] > maxSubStr[i][j + 1] ? maxSubStr[i + 1][j] : maxSubStr[i][j + 1];
				}
			}
		}
		cout << maxSubStr[len1][len2] << endl;
	}
	return 0;
}