#include<iostream>
#include<queue>
using namespace std;
const int kMaxLen = 105;
char maze[kMaxLen][kMaxLen];
int flag[kMaxLen][kMaxLen];
int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };//上下左右
struct status{
	int x;
	int y;
	int pre_dir;
	int turn;
};
int main(){
	int t, m, n;
	int k, x1, y1, x2, y2;
	cin >> t;
	while (t--){
		cin >> m >> n;
		memset(maze, '\0', sizeof(maze));
		memset(flag, -1, sizeof(flag));
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				cin >> maze[i][j];
			}
		}
		cin >> k >> x1 >> y1 >> x2 >> y2;//y是行，x是列
		queue<status> q;
		status init = { x1, y1, -1, 0 };
		q.push(init);
		int find = 0;
		while (!q.empty()){
			status cur = q.front();
			q.pop();
			if (cur.x == x2&&cur.y == y2){
				find = 1;
			}
			for (int i = 0; i < 4; i++){
				status next;
				next.y = cur.y + dir[i][0];
				next.x = cur.x + dir[i][1];
				next.pre_dir = i;
				next.turn = (cur.pre_dir == i || cur.pre_dir == -1) ? cur.turn : cur.turn + 1;//方向是否改变
				if (maze[next.y][next.x] == '.'&&next.turn <= k && (flag[next.y][next.x] == -1 || flag[next.y][next.x] >= next.turn)){
					//有效节点，且可以访问，且未访问过或者虽然访问过但访问它所需的转弯次数大于等于当前转弯次数。
					q.push(next);
					flag[next.y][next.x] = next.turn;
				}
			}
		}
		if (find){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}