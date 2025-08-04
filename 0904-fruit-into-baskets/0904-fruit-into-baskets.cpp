class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // maximum length of subarray with at most 2 types of numbers.
        unordered_map<int,int> mp;
        int maxi=INT_MIN;
        int n=fruits.size();
        int i=0,j=0;

        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()>2){
                if(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                    i++;
                }
                // if(mp.size()<=2)maxi=max(maxi,j-i+1);
            }

            if(mp.size()<=2){
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};