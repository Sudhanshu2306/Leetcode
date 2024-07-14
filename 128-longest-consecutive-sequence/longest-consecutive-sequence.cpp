class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto i:nums) st.insert(i);

        int count=1;int maxi=0;
        
        for(auto i:st){
            int x=i;
            if(st.find(x-1)==st.end()){
                count=1;
                while(st.find(x+1)!=st.end()){
                    count++;
                    x=x+1;
                }
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};