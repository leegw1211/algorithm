#include <bits/stdc++.h>
#define MAXDIS 200001
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> graph(n+1, vector<int>(n+1, MAXDIS));
	for (int i=1; i<=n; i++) graph[i][i] = 0;
	for (int i=0; i<m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a][b] = c;
		graph[b][a] = c;
	}
	
	vector<vector<int>> answer(n+1, vector<int>(n+1));
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			answer[i][j] = j;
		}
	}
	
	for (int k=1; k<=n; k++) {
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
					answer[i][j] = answer[i][k];
				}
			}
		}
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (i==j) cout << '-' << " ";
			else cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}