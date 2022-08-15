#include <iostream>
#include <string>

using namespace std;

int student[1000000]; //student[order] = height
int card[1000000]; //card[order] = number
int ordered_student[1000000]; //[card-number] = height

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {

		int dat[300] = { 0, }; //dat[height] = student-count

		int N;
		cin >> N;
		for (int n = 0; n < N; n++) { //�л� Ű �Է�
			cin >> student[n];
		}
		for (int n = 0; n < N; n++) { //ī�� ��ȣ �Է�
			cin >> card[n];
		}

		for (int n = 0; n < N; n++) { //�л� Ű �� ���
			int height = student[n];
			dat[height]++;
		}

		int order = 1;
		for (int i = 300; i > 0; i--) { //�л� Ű ������ ����
			int n = dat[i];
			for (int j = 0; j < n; j++) {
				ordered_student[order] = i;
				order++;
			}
		}

		int flag = 0;
		for (int n = 0; n < N; n++) {
			int height = student[n];
			int number = card[n];
			if (ordered_student[number] != height) {
				flag = 1;
				break;
			}
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

}