#include <iostream>
#include <queue>

using namespace std;

int N; //ī���� ����
int M; //ī�� ��ü Ƚ��
priority_queue <long long, vector<long long>, greater<long long>> q; //ī��

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < M; i++) {
		long long a = q.top(); q.pop();
		long long b = q.top(); q.pop();
		q.push(a + b);
		q.push(a + b);
	}

	long long sum = 0;
	while (!q.empty()) {
		sum += q.top(); q.pop();
	}

	cout << sum;
}