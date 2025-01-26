class Solution {
public:
    long long kadane(vector<int> arr){
        int n=arr.size();
        long long maxi=LONG_MIN;
        long long sum=0;
    
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>maxi) maxi=sum;
            if(sum<0) sum=0;
        }
        return maxi;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        // sort(nums.begin(),nums.end());
        // vector<int> x(n);
        int countk=0; 
        for(int i=0;i<n;i++){ 
            if(nums[i]==k) countk++;
        } 
        int maxi=0; 
        
        for(int i=1;i<=50;i++){ 
            if(i==k) continue; 
            int x=k-i; 
            int curr=0, currmaxi=0; 
            
            for(auto it:nums){ 
                if(it==i) curr++;
                else if(it==k) curr-=1;
                
                if(curr<0) curr=0; 
                else currmaxi=max(curr,currmaxi);
            } 
            maxi=max(maxi,currmaxi); 
        } 
        int ans=countk+maxi; 
        return ans;
    }
};