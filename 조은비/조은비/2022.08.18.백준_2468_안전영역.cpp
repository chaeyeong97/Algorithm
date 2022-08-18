#include <iostream>
#include <queue>

using namespace std;

int N; //�� ũ��
int map[100][100]; //�� ���� | [y][x] = ����
int visited[100][100]; // �湮 ���� 0/1
int cntMax; //���� ���� ����

struct edge { int y; int x; };

queue <edge> q;

int di[4][2] = { //���� �迭 (4����) | [����][0=y, 1=x]
	{-1, 0},
	{ 0, 1},
	{ 1, 0},
	{ 0,-1}
};

void reset() { //visited �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}
}

void safe(int y, int x, int height) { //���� ���� ���� ������ visited�� 1�� ���

	q.push({ y,x });

	while (!q.empty()) {

		edge temp = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {

			int ny = temp.y + di[i][0];
			int nx = temp.x + di[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			if (visited[ny][nx] == 1) continue;

			if (map[ny][nx] > height) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			} 

		}
	}
}

int isSafe(int x) { // ���� x ������ ������ ���� ��� �� ���� ���� ����

	int cnt = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (visited[i][j] == 1) continue;
			visited[i][j] = 1;

			if (map[i][j] <= x) continue;
			cnt++;

			safe(i, j, x);

		}
	}

	return cnt;
}


int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i <= 100; i++) {

		reset();

		int cnt = isSafe(i);

		cntMax = max(cntMax, cnt);
	}

	cout << cntMax;
}