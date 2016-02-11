#include<string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		int length = 0;
		int result = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] != ' '){
				length++;
			}
			else{
				//length记录当前找到的单词长度，一遇到空格就置零
				//result记录最后找到的单词长度，只有发现新单词长度是才更新
				result = length == 0 ? result : length;
				length = 0;
			}
		}
		return length == 0 ? result : length;
	}
};