#include <iostream>

using namespace std;

int N; //���� ũ�� : N * N
int map[16][16]; //�� | 0:��ĭ, 1:��
int cnt; // ��� ��

void dfs(int y, int x, string dir) { //y��ǥ, x��ǥ, ����
	if (y == N - 1 && x == N - 1) {
		cnt++;
		return;
	}

	if (dir == "horizon") { //�������� ������ ��
		if (x + 1 >= N) return;
		if (map[y][x + 1] == 0) { //���η� ����
			dfs(y, x + 1, "horizon");
		}

		if (y + 1 >= N) return;
		if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //�밢������ ����
			dfs(y + 1, x + 1, "diagonal");
		}
	}

	if (dir == "vertical") { //�������� ������ ��
		if (y + 1 >= N) return;
		if (map[y + 1][x] == 0) { //���η� ����
			dfs(y + 1, x, "vertical");
		}

		if (x + 1 >= N) return;
		if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //�밢������ ����
			dfs(y + 1, x + 1, "diagonal");
		}
	}

	if (dir == "diagonal") { //�������� �밢���� ��
		if (x + 1 < N) {
			if (map[y][x + 1] == 0) { //���η� ����
				dfs(y, x + 1, "horizon");
			}
		}

		if (y + 1 < N) {
			if (map[y + 1][x] == 0) { //���η� ����
				dfs(y + 1, x, "vertical");
			}
		}

		if (x + 1 < N && y + 1 < N) {
			if (map[y][x + 1] == 0 && map[y + 1][x] == 0 && map[y + 1][x + 1] == 0) { //�밢������ ����
				dfs(y + 1, x + 1, "diagonal");
			}
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 1, "horizon");

	cout << cnt;
}