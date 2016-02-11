#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF){
		int* num = new int[n];
		for (int i = 0; i < n; i++){
			scanf("%d", &num[i]);
		}
		//默认建立最大堆
		make_heap(num, num + n);
		pop_heap(num, num + n);
		printf("%d", num[n - 1]);
		for (int i = 1; i < m; i++){
			pop_heap(num, num + n - i);
			printf(" %d", num[n - i - 1]);
		}
		printf("\n");
	}
	return 0;
}