class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int sum=0,odd=0,even=0;
        for(auto it:arr){
            if(it%2==0) even++;
            else{
                swap(odd,even);
                odd++;
            }
            sum=(sum+odd)%1000000007;
        }
        return sum;
    }
};