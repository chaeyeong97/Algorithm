#include <iostream>
#include <vector>

using namespace std;

vector <int> high_low[100001]; //��� ��Ʈ ����
vector <int> low_high[100001];
int visited[100001] = { 0, };

int lower = 0;
void dfs1(int X) { //�л� X���� ���� ����� �л� ã��
	for (int i = 0; i < high_low[X].size(); i++) {
		int next = high_low[X][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		lower++;
		dfs1(next);
	}
}

int heigher = 0;
void dfs2(int X) { //�л� X���� ���� ����� �л� ã��
	for (int i = 0; i < low_high[X].size(); i++) {
		int next = low_high[X][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		heigher++;
		dfs2(next);
	}
}

int main() {
	int N, M, X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		high_low[a].push_back(b); //a�࿡ a���� ���� ��� b Ǫ��
		low_high[b].push_back(a); //b�࿡ b���� ���� ��� a Ǫ��
	}

	dfs1(X);
	dfs2(X);

	int U = 1 + heigher; //������ ���� ���� ���
	int V = N - lower; //������ ���� ���� ���

	cout << U << "\n" << V;
}