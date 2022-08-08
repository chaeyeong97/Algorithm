#include <iostream>
#include <vector>

using namespace std;

int height, width; //�� ũ�� ����
int map[100][100]; //��ũȦ ��
int visited[100][100]; //�湮 ���

struct Edge {
	int y; //y�� ��ǥ
	int x; //x�� ��ǥ
};
vector <Edge> sinkhole[100]; //��ũȦ ��� ����

int index = 0; //����[0]���� ������� ���
void func(int y, int x) {
	int di[2][4] = { //���� ����
		{-1,0,1,0},
		{0,1,0,-1}
	};

	sinkhole[index].push_back({ y,x }); //���Ϳ� ���� ��ǥ(��ũȦ ��ǥ) Ǫ��

	for (int i = 0; i < sinkhole[index].size(); i++) { //���� index�� �����ŭ ����Ŭ�� ���ư�(���Խ� ������==1)
		for (int j = 0; j < 4; j++) {
			int ny = sinkhole[index][i].y + di[0][j]; //���� ���� �Է�
			int nx = sinkhole[index][i].x + di[1][j];
			if (ny < 0 || ny >= height || nx < 0 || nx >= width) continue;
			if (visited[ny][nx] == 1) continue;
			visited[ny][nx] = 1;

			if (map[ny][nx] == 0) continue;
			sinkhole[index].push_back({ ny,nx }); //��ũȦ ��ǥ�� �� ���� �ε����� Ǫ��(���� �ε��� ����� +1)
		}
	}

	index++; //�� ����Ŭ�� ������ �ε��� ������Ŵ
}

int func(vector <Edge> sinkhole) {
	int maxy = 0, maxx = 0, miny = 100, minx = 100;

	for (int i = 0; i < sinkhole.size(); i++) {
		if (maxy < sinkhole[i].y) maxy = sinkhole[i].y;
		if (maxx < sinkhole[i].x) maxx = sinkhole[i].x;
		if (miny > sinkhole[i].y) miny = sinkhole[i].y;
		if (minx > sinkhole[i].x) minx = sinkhole[i].x;
	}

	return (maxy - miny + 2) * 2 + (maxx - minx + 2) * 2;
}

int main() {

	//�� ���� �Է�
	cin >> height >> width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> map[i][j];
		}
	}

	//��ũȦ ã��
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (visited[i][j] == 1) continue;
			visited[i][j] = 1; //�湮 ���

			if (map[i][j] == 0) continue;
			func(i, j);
		}
	}

	int maxfences = 0;
	for (int i = 0; i < index; i++) {
		int nowfences = func(sinkhole[i]);

		if (maxfences < nowfences) maxfences = nowfences;
	}

	cout << maxfences;
}