class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>stk;
        unordered_map<int,int>map;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            int ele=nums2[i];
            while(!stk.empty() && stk.top()<=ele ){
                stk.pop();
            }
            int res=(stk.empty())? -1:stk.top();
          
            map.insert({ele,res});
            stk.push(ele);
            
        }
        vector<int>ans;
        for(auto x:nums1){ 
            ans.push_back(map[x]);
        }
        return ans;                
    }
};