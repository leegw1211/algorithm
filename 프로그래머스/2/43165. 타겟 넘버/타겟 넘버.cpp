#include <string>
#include <vector>

using namespace std;
int tar;
int cur;
int answer;

void dfs(vector<int> &nums, int index) {
    cur += nums[index];
    if (index == nums.size()-1) {
        if (cur == tar) answer++;
    }
    else dfs(nums, index+1);
    
    cur = cur - 2*nums[index];
    if (index == nums.size()-1) {
        if (cur == tar) answer++;
    }
    else dfs(nums, index+1);
    
    cur += nums[index];
}

int solution(vector<int> numbers, int target) {
    tar = target;
    dfs(numbers, 0);
    return answer;
}