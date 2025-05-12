class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n=digits.size();
        set<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==j || j==k || k==i) continue;
                    int x=digits[i]*100+digits[j]*10+digits[k];
                    if(x>=100 && x%2==0) ans.insert(x);
                }
            }
        }
        vector<int> a;
        for(auto it:ans) a.push_back(it);
        
        return a;
    }
};