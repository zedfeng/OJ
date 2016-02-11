#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
const int kMaxLen = 101;
int gcd(int a, int b){
	int temp;
	while (b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}
int lcm(int a, int b)
{
	return a / gcd(a, b)*b;//�ȳ���ˣ�������ܽ������
}
//��������Ϊ����������С������
//������С���������������˻��������Լ�������������Լ�����ڷ��ӵ����Լ�����Է�ĸ����С��������
//ע������С������֮ǰ��������Ҫͨ��
int main(){
	int test, cir1, day1, cir2, day2, g1, g2;
	scanf("%d", &test);
	while (test--){
		scanf("%d/%d %d/%d", &day1, &cir1, &day2, &cir2);
		int denominator, numerator;
		g1 = gcd(day1, cir1);
		g2 = gcd(day2, cir2);
		day1 /= g1;
		cir1 /= g1;
		day2 /= g2;
		cir2 /= g2;
		numerator = lcm(day1, day2);
		denominator = gcd(cir1, cir2);
		if (denominator == 1){
			printf("%d\n", numerator);
		}
		else{
			printf("%d/%d\n", numerator, denominator);
		}
	}
	return 0;
}