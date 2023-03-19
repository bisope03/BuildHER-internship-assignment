#include <iostream>
#include <vector>
using namespace std;

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Time complexity: O(n) where n is the number of elements in the array;
Space complexity: O(1)

*/

int main(){
    // array input
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    
    // solution
    int num1=-1, num2=-1, count1=0, count2=0;
    int majority = nums.size()/3;

    for(int i=0; i<nums.size(); i++){
        if(nums[i]==num1){
            count1++;
        }else if(nums[i]==num2){
            count2++;
        }else if(count1==0){
            num1 = nums[i];
            count1=1;
        }else if(count2==0){
            num2 = nums[i];
            count2=1;
        }else{
            count1--;
            count2--;
        }
    }

    count1 = count2 = 0;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] == num1){
            count1++;
        }
        else if(nums[i] == num2){
            count2++;
        }
    }
    if(count1 > majority){
       cout << num1 << " ";
    }
    if(count2 > majority){
       cout << num2;
    }
    return 0;
}
