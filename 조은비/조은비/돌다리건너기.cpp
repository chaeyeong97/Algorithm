#include <iostream>

using namespace std;

int a = 0; //���ٸ� ����ġ
int cnt = 0; //����� ��
string magic; //���� ���縵
string stone[2]; //���ٸ�

//dfs �Լ�
//level: ���� ���縵 ����
//step: ���ٸ� ����
void dfs(int level, int step) {
	if (level == magic.length()) { //�������� : ��� ���縵�� �������
		cnt++;                     //           ����� ���� 1�� ���ϰ� ����
		return;
	}

	for (int i = step; i < stone[a].length(); i++) { //���ٸ��� step���� 1�� ����
		if (magic[level] != stone[a][i]) continue;
		if (a == 0) a = 1; //���ٸ� 1/0 ����ġ
		else a = 0;
		dfs(level + 1, i + 1); //���縵 ã���� level+1(���� ���� ���縵), i+1(���� ���ٸ� ������ ��������)
		if (a == 0) a = 1; //���� �� �ٽ� ���ٸ� ����ġ
		else a = 0;
	}
}

int main() {
	cin >> magic >> stone[0] >> stone[1];

	dfs(0, 0); //a�� 0�� �� ��� ���� ������
	a = 1;
	dfs(0, 0); //a�� 1�� �� ��� ���� ����

	cout << cnt;//��� �� ���
}