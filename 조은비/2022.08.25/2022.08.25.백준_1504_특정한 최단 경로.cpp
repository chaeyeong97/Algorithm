#include <iostream>
#include <queue>

using namespace std;

struct edge {
	int to;
	int cost;
};

bool operator < (edge A, edge B) {
	return A.cost > B.cost;
}

vector <edge> route[801]; // [from] = edge1, edge2, ...

int N; //������ ����
int E; //������ ����
int v1, v2; //���ľ� �ϴ� ���� ��ȣ
int cost[801][801]; //[from][to][cost]

void func(int A) { //cost[A][1~N]�� ä��� �Լ�

	cost[A][A] = 0;
	priority_queue <edge> pq;
	for (int i = 0; i < route[A].size(); i++) {
		pq.push(route[A][i]);
	}

	while (!pq.empty()) {
		edge temp = pq.top(); pq.pop();
		if (cost[temp.to] <= cost[temp.from] + temp.cost) continue;

		cost[temp.to] = cost[temp.from] + temp.cost;

		for (int i = 0; i < route[temp.to].size(); i++) {
			edge next = route[temp.to][i];
			if (cost[next.to] <= cost[next.from] + next.cost) continue;

			pq.push(route[temp.to][i]);
		}
	}

	return cost[B];
}

int main() {

	//�Է� �ޱ�
	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		route[from].push_back({ to, cost });
		route[to].push_back({ from, cost });
	}

	cin >> v1 >> v2;

	//cost �ʱⰪ ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cost[i][j] = 1234567890;
		}
	}

	//cost ����� ����
	for (int n = 1; n <= N; n++) {


	}


}