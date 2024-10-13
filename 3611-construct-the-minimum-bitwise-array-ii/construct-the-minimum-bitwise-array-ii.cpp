class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,-1);
        for(int j=0;j<n;j++){
            int it=nums[j];
            // bool flag = false;
            // // smallest x taaki x | (x+1)==num
            // for(int j=0;j<=30;j++){
            //     int x=(num&~(1<<j))-1;
            // }
            // if(!flag) ans[i]=-1;
            vector<int> temp;
            // int x=(num-1);
            // if(x|(x+1)==num) ans[i]=x;
            // else{
                for(int i=0;i<32;i++){
                    if(it&(1<<i)){
                        // smallest x taaki x | (x+1)==num
                        // int x=(num&~(1<<j))-1;
                        int x=it & ~(1<<i);
                        if((x|(x+1))==it){
                            temp.push_back(x);
                        }
                    }
                }
                if(temp.empty()) ans[j]=-1;
                else{
                    int mini=*min_element(temp.begin(), temp.end());
                    ans[j]=(mini);
                }
            // }
        }
        return ans;
    }
};