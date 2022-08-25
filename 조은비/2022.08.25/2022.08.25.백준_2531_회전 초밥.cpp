#include <iostream>

using namespace std;

int N; //������ ��
int d; //�ʹ��� ������
int k; //�����Ͽ� �Դ� ������ ��
int c; //������ȣ(�ʹ� ���� 1��)

int table[30000]; //[���� ��ȣ] = �ʹ� ��ȣ

int main() {
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}

	int maxcnt = 0;
	for (int i = 0; i < N; i++) { //i: �����ϴ� ���� ��ȣ
		int dat[3001] = {}; //[�ʹ� ��ȣ] = ���� ��:1, �� ���� ��:0
		dat[c] = 1;
		int cnt = 1;

		for (int j = 0; j < k; j++) {
			int susi = table[(i + j) % N];
			if (dat[susi] == 1) continue;

			cnt++;
			dat[susi] = 1;
		}

		maxcnt = max(maxcnt, cnt);
	}

	cout << maxcnt;
}