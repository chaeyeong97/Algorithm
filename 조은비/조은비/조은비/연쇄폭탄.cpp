//2022�� 08�� 04�� �˰��� ���͵� ����2

#include <iostream>
#include <queue>

using namespace std;

struct bomb {
	int y; //��ź y��ǥ
	int x; //��ź x��ǥ
	int num; //��ź ��ȣ
};

int operator < (bomb A, bomb B) { //pq �켱���� ����
	return A.num > B.num; //num���� ����������
}

int arr[1000][1000]; //��ź �ʵ�
int DAT[1000][1000]; //�ʵ� �� �� ���� �� 0, ���� �� 1
priority_queue <bomb> bom;
int di[2][5] = { //������ �ʵ� ���� �迭
	{0,-1,0,1,0},
	{0,0,1,0,-1}
};

int main() {
	int n;
	cin >> n; //�ʵ� ������

	for (int i = 0; i < n; i++) { //�ʵ�� pq�� ��ź ���� �Է�
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			bom.push({ i,j,arr[i][j] });
		}
	}

	int sec = 0; //�ɸ��� �ð�
	while (!bom.empty()) {
		bomb t = bom.top(); bom.pop();
		if (DAT[t.y][t.x] == 1) continue;
		sec = t.num;
		for (int j = 0; j < 5; j++) {
			int ny = t.y + di[0][j];
			int nx = t.x + di[1][j];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			DAT[ny][nx] = 1;
		}
	}

	cout << sec << "��";
}