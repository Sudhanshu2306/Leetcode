class Solution {
private:
int fOcc(vector<int>nums,int target){
    int s=0,e=nums.size()-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(nums[mid]==target){
            ans=mid;
            e=mid-1;
        }
        if(target>nums[mid]){
            s=mid+1;
        }
        else if(target<nums[mid]){
            e=mid-1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

int lOcc(vector<int>nums,int target){
    int s=0,e=nums.size()-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        if(nums[mid]==target){
            ans=mid;
            s=mid+1;
        }
        if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // vector<int> ans;
        int n=nums.size();
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(x>n-1 || nums[x]>target) return {-1,-1};
        int y=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(!(y-1>=0 && nums[y-1]==target)) y=-1;
        return {x,y-1};
       
    }
};