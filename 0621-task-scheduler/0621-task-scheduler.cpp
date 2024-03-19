class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        int sum=0;
        int maxi=INT_MIN;
        for(char i:tasks){
            mp[i]++;
            sum++;
            maxi=max(maxi,mp[i]);
        }
        int count=0;
        for(auto i:mp) if(i.second==maxi) count++;
        int x=((n+1)*(maxi-1)+(count)); // (n+1)->including the task itself
        return x<sum?sum:x; 
    }
};