#include<cstdio>
int main(){
	int num, sum10, sum12, sum16;
	while (scanf("%d", &num)){
		if (num == 0){
			break;
		}
		int temp;
		temp = num;
		sum10 = 0;
		while (temp != 0){
			sum10 += temp % 10;
			temp /= 10;
		}
		temp = num;
		sum12 = 0;
		while (temp != 0){
			sum12 += temp % 12;
			temp /= 12;
		}
		temp = num;
		sum16 = 0;
		while (temp != 0){
			sum16 += temp % 16;
			temp /= 16;
		}
		if (sum10 == sum12&&sum10 == sum16&&sum12 == sum16){
			printf("%d is a Sky Number.\n", num);
		}
		else{
			printf("%d is not a Sky Number.\n", num);
		}
	}
	return 0;
}