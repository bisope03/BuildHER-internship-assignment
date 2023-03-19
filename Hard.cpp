#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
You are given an array of integers nums, there is a sliding window of size k which is moving from 
the very left of the array to the very right. You can only see the k numbers in the window. 
Each time the sliding window moves right by one position.

Return the max sliding window.

Time complexity: O(n) where is the number of elements in the array
Space complexity: O(k) where k is the numbers in the window
*/

int main(){
    // array input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
  
    // k input
    int k;
    cin >> k;

    // solution
    deque<int> dq;
    vector<int> result;
    
    int i = 0;
    int j = 0;
    
    while (j < nums.size()) {
        while (!dq.empty() && nums[dq.back()] < nums[j]) {
            dq.pop_back();
        }
        dq.push_back(j);
        
        if (i > dq.front()) {
            dq.pop_front();
        }
        
        if (j + 1 >= k) {
            result.push_back(nums[dq.front()]);
            i++;
        }
        j++;
    }
    
    for(int num: result){
        cout << num << " ";
    }

    return 0;
}
