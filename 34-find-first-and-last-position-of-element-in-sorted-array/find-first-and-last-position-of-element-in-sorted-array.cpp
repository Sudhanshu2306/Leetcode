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
        vector<int> ans;
        int x=fOcc(nums,target);
        if(x==-1) return {-1,-1};
        int y=lOcc(nums,target);
        
        return {x,y};
       
    }
};