#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n+1, vector<int>());
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}
	
	vector<vector<int>> connect(n+1, vector<int>(n+1, -1));
	for (int i=1; i<=n; i++) {
		queue<int> q;
		q.push(i);
		connect[i][i] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int k : graph[cur]) {
				if (connect[i][k] == -1) {
					connect[i][k] = 1;
					q.push(k);
				}
			}
		}
	}

	for (int i=1; i<=n; i++) {
		for (int j=i+1; j<=n; j++) {
			int cursum = connect[i][j] + connect[j][i];
			connect[i][j] = cursum;
			connect[j][i] = cursum;
		}
	}
	
	for (int i=1; i<=n; i++) {
		int answer = 0;
		for (int j=1; j<=n; j++) {
			if (connect[i][j] == -2) answer++;
		}
		cout << answer << "\n";
	}
}