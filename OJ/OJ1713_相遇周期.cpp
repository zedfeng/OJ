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
	return a / gcd(a, b)*b;//先除后乘，否则可能结果过大。
}
//相遇周期为两个周期最小公倍数
//分数最小公倍数等于两数乘积除其最大公约数，分数的最大公约数等于分子的最大公约数除以分母的最小公倍数。
//注意求最小公倍数之前两分数需要通分
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