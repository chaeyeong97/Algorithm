#include <iostream>
#include <queue>

using namespace std;

struct robot {
	int y;  //y��ǥ
	int x;  //x��ǥ
	int di; //���� (0 ~ 3)
	int cmd; //Ŀ�ǵ� �Է� Ƚ��
};

int direction[4][2] = { //����迭
	{-1, 0}, //��
	{ 0, 1}, //��
	{ 1, 0}, //��
	{ 0,-1}  //��
};

int N; //����â�� ���� ����
int M; //����â�� ���� ����
int map[101][101]; //��ֹ� and visited �Է�
int visited[101][101][4]; //[y][x][di]
int y, x, di; //��ǥ ��ǥ, ����
queue <robot> q;

void commend(robot r) {

	//����
	int ny, nx;

	for (int i = 1; i <= 3; i++) {
		ny = r.y + direction[r.di][0] * i;
		nx = r.x + direction[r.di][1] * i;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break; //������ ����� �����Ұ�
		if (map[ny][nx] == 1) break; //��ֹ� ������ ���� �Ұ�
		if (visited[ny][nx][r.di] == 1) continue; //�湮 ��� ���� �Ұ�
		visited[ny][nx][r.di] = 1;
		q.push({ ny,nx,r.di,r.cmd + 1 });
	}


	int ndi;

	//��ȸ��
	if (r.di == 3) ndi = 0;
	else ndi = r.di + 1;
	if (visited[r.y][r.x][ndi] != 1) { //�湮 ��� ���ԺҰ�
		visited[r.y][r.x][ndi] = 1;
		q.push({ r.y, r.x, ndi, r.cmd + 1 });
	}

	//��ȸ��
	if (r.di == 0) ndi = 3;
	else ndi = r.di - 1;
	if (visited[r.y][r.x][ndi] != 1) {
		visited[r.y][r.x][ndi] = 1;
		q.push({ r.y, r.x, ndi, r.cmd + 1 });
	}

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//������ǥ �Է�
	int changeDi[5] = { 0,1,3,2,0 };

	cin >> y >> x >> di;
	y -= 1; x -= 1;
	di = changeDi[di];
	q.push({ y,x,di,0 });

	//������ǥ �Է�
	cin >> y >> x >> di;
	y -= 1; x -= 1;
	di = changeDi[di];

	while (1) {
		robot r = q.front(); q.pop();
		if (r.y == y && r.x == x && r.di == di) {
			cout << r.cmd;
			break;
		}

		commend(r);
	}
}