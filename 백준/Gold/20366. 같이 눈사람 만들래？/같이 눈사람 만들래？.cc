#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
//sol1 : 투포인터
/* 
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	
	int answer = 1000000001;
	for (int i=0; i<n; i++) {
		for (int j=i+3; j<n; j++) {
			int height = a[i] + a[j];
			int small = i+1, big = j-1;
			while (small != big) {
				answer = min(answer, abs(height - (a[small] + a[big])));
				if (answer == 0) {
					cout << 0;
					return 0;
				}
				else if (a[small] + a[big] < height) small++;
				else big--;
			}
		}
	}
	cout << answer;
}
*/

//sol2 : 가능한 눈사람 모두 만들기
struct snowman {
	int size;
	int i;
	int j;
	snowman (int _size, int _i, int _j) {
		size = _size;
		i = _i;
		j = _j;
	}
	bool operator < (snowman s) {
		return size < s.size;
	}
};
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++) cin >> a[i];
	
	vector<snowman> snowmans;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			snowmans.emplace_back(a[i]+a[j], i, j);
		}
	}
	sort(snowmans.begin(), snowmans.end());
	
	int answer = 1000000001;
	for (int i=0; i<snowmans.size(); i++) {
		for (int j=i+1; j<snowmans.size(); j++) {
			if (snowmans[i].i == snowmans[j].i || snowmans[i].i == snowmans[j].j) continue;
			if (snowmans[i].j == snowmans[j].i || snowmans[i].j == snowmans[j].j) continue;
			answer = min(answer, abs(snowmans[i].size-snowmans[j].size));
			break;
		}
	}
	cout << answer;
}