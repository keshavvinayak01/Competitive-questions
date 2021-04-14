/*
Given a non-empty array of integers, find the top k elements which have the highest frequency in the array. 
If two numbers have the same frequency then the larger number should be given preference. 
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:

    static bool compareCount(pair<int, int> a, pair<int, int> b) {
        return (a.second > b.second || (a.second == b.second && a > b));
    }

    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        vector<pair<int, int>> numCounts;
        sort(nums.begin(), nums.end());
        int j = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(j == 0 || numCounts[j-1].first != nums[i]) {
                numCounts.push_back(make_pair(nums[i], 1));
                j++;
            }
            else    
                numCounts[j-1].second++;
        }
        sort(numCounts.begin(), numCounts.end(), compareCount);
        vector<int> result;
        for(int i = 0 ; i < k; i++)
            result.push_back(numCounts[i].first);
        return result;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends