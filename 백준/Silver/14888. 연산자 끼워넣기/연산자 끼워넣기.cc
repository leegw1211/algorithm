#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c, d;
vector<int> nums;
vector<int> oper;
int maxans = -1000000001;
int minans = 1000000001;

void calc() {
	int answer = nums[0];
	for (int i=1; i<nums.size(); i++) {
		if (oper[i-1] == '+') {
			answer += nums[i];
		}
		else if (oper[i-1] == '-') {
			answer -= nums[i];
		}
		else if (oper[i-1] == 'x') {
			answer *= nums[i];
		}
		else {
			answer /= nums[i];
		}
	}
	maxans = max(maxans, answer);
	minans = min(minans, answer);
}
void dfs() {
	if (nums.size()-1 == oper.size()) {
		calc();
		return;
	}
	
	if (a>0) {
		oper.push_back('+');
		a--;
		dfs();
		oper.pop_back();
		a++;
	}
	if (b>0) {
		oper.push_back('-');
		b--;
		dfs();
		oper.pop_back();
		b++;
	}
	if (c>0) {
		oper.push_back('x');
		c--;
		dfs();
		oper.pop_back();
		c++;
	}
	if (d>0) {
		oper.push_back('/');
		d--;
		dfs();
		oper.pop_back();
		d++;
	}
}

int main() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		int k; cin >> k;
		nums.push_back(k);
	}
	cin >> a >> b >> c >> d;
	dfs();
	cout << maxans << " " << minans;
}