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
				//length��¼��ǰ�ҵ��ĵ��ʳ��ȣ�һ�����ո������
				//result��¼����ҵ��ĵ��ʳ��ȣ�ֻ�з����µ��ʳ����ǲŸ���
				result = length == 0 ? result : length;
				length = 0;
			}
		}
		return length == 0 ? result : length;
	}
};