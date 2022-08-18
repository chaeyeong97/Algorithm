#include <iostream>
#include <vector>

using namespace std;

int height, width; //�ٺ�ġ Ÿ�� ��, â��
int tower[3][5]; //�ٺ�ġ Ÿ��
int rotated_tower[3][5]; //ȸ���� �ٺ�ġ Ÿ��
int maxValue = 0; //�ٺ�ġ ����

int score() {
	int sum[100] = { 0, }; //���� ��
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			sum[j] += rotated_tower[i][j];
		}
	}

	int times = 1;
	for (int j = 0; j < width; j++) {
		times = times * sum[j];
	}

	return times;
}

void dfs(int level) { //level : ��
	if (level == height) {
		int Value = score();
		if (maxValue < Value) {
			maxValue = Value;
		}
		return;
	}

	for (int i = 0; i < width; i++) {
		int ni = i;
		
		int flag = 0;
		for (int j = 0; j < width; j++) {
			if (ni >= width) ni -= width;
			
			for (int k = 0; k < level; k++) {
				if (rotated_tower[k][j] == tower[level][ni]) {
					flag = 1;
					break;
				}
			}
			if (flag) break;

			rotated_tower[level][j] = tower[level][ni++];
		}
		if (flag) continue;

		dfs(level + 1);
	}
}

int main() {
	cin >> height >> width;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cin >> tower[i][j];
		}
	}

	dfs(0);

	cout << maxValue;
}