#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <char> v[200]; //v[p] = {l,r}
int order[200]; //order['e'] = 0;
int ordernum = 0;
void dfs(char a) {
	order[a] = ordernum;
	ordernum++;

	for (int i = 0; i < 2; i++) {
		if (v[a][i] == '#') continue;
		dfs(v[a][i]);
	}
}

void switching(string* str1, string* str2) {
	string temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int main() {
	int arr[200] = { 0, }; //����� ã��� ����
	int n; //����� ����
	cin >> n;
	for (int i = 0; i < n; i++) {
		char P, L, R;
		cin >> P >> L >> R;
		v[P].push_back(L); v[P].push_back(R);
		arr[P]++; arr[L]--; arr[R]--;
	}

	char ancestor; //�����
	for (int i = 'a'; i <= 'z'; i++) {
		if (arr[i] == 1) {
			ancestor = i;
			break;
		}
	}


	dfs(ancestor);

	int m; //�ܾ��� ����
	cin >> m;
	string str[1000];
	for (int i = 0; i < m; i++) {
		cin >> str[i];
	}

	for (int i = 0; i < m-1; i++) { //ù��° �ܾ�
		for (int j = i + 1; j < m; j++) { //�ι�° �ܾ�
			for (int k = 0; k < 1000; k++) { //�ܾ� �� ���ĺ�
				if (k == str[i].length()) break;
				if (k == str[j].length()) {
					switching(&str[i], &str[j]);
					break;
				}

				int a = order[str[i][k]];
				int b = order[str[j][k]];
				if (a > b) {
					switching(&str[i], &str[j]);
					break;
				}
				else if (a < b) break;

			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << str[i] << "\n";
	}
}