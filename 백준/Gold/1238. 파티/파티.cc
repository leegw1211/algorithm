#include <iostream>
#define inf 100000000
using namespace std;

int main() {
	int n, m, x, max = 0;
	int a, b, l;
	cin >> n >> m >> x;
	
	int** array = new int*[n+1];
	for (int i=0; i<n+1; i++) {
		array[i] = new int[n+1];
		for (int j=0; j<n+1; j++) {
			array[i][j] = inf;
		}
	}
	
	for (int i=0; i<m; i++) {
		cin >> a >> b >> l;
		array[a][b] = l;
	}

	for (int k=1; k<n+1; k++) { // k를 경유 
		for (int i=1; i<n+1; i++) {
			for (int j=1; j<n+1; j++) { // i에서 j로 가는 최단 경로와 비교 
				if (array[i][j] > array[i][k] + array[k][j]) {
					array[i][j] = array[i][k] + array[k][j];
				}
			}
		}
	}

	for (int i=1; i<n+1; i++) {
		if (i == x) continue;
		if (max < array[i][x] + array[x][i]) max = array[i][x] + array[x][i];
	}
	cout << max;
	
	for (int i=0; i<n+1; i++) delete[] array[i];
	delete[] array;
}