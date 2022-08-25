#include <iostream>

using namespace std;

int Ms; //�ʱ� ���ھ�
int Ma; //���� ���ڱݾ�
int N; //���� ��
int L; //������ �Ⱓ
int table[15][16]; //[n][l] = l���� �� n�� ����

int dat[15]; //[n] = �ż� ����
int maxmoney;
void func(int money, int n, int l) { //���� ���� ��, ���� ����, ���� �Ⱓ
	if (n == N) {
		int summoney = money;
		for (int i = 0; i < N; i++) {
			summoney += table[i][l+1] * dat[i];
		}

		maxmoney = max(maxmoney, summoney);
		return;
	}

	int i = 0;
	while (1) {
		int change = money - table[n][l] * i;
		if (change < 0) return;

		dat[n] = i;
		func(change, n + 1, l);

		i++;
	}
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {

		//������ �Է�
		cin >> Ms >> Ma >> N >> L;

		for (int n = 0; n < N; n++) {
			for (int l = 0; l <= L; l++) {
				cin >> table[n][l];
			}
		}

		int money = Ms;
		for (int i = 0; i < L; i++) {
			maxmoney = 0;

			func(money, 0, i);

			money = maxmoney;
			money += Ma;
		}

		cout << "#" << t << " ";
		cout << money - Ms - (Ma * L) << "\n";
	}
}