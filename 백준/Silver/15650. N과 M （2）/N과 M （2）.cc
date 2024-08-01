#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> &visited, vector<int> &answer, int size, int m, int latest) {
	if (size == m) {
		for (int k : answer) cout << k << " ";
		cout << "\n";
		return;
	}
	for (int i=latest+1; i<visited.size(); i++) {
		if (visited[i] == 0) {
			answer.push_back(i);
			visited[i] = 1;
			dfs(visited, answer, size+1, m, i);
			answer.pop_back();
			visited[i] = 0;
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> visited(n+1, 0);
	vector<int> answer;
	dfs(visited, answer, 0, m, 0);
}
