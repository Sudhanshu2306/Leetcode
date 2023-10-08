class Solution {
private:
int fOcc(vector<int>nums,int target){
    int s=0,e=nums.size()-1;
    int mid=(s+e)/2;
    int ans=-1;
    while(s<=e){
        
        if(nums.at(mid)==target){
            ans=mid;
            e=mid-1;
        }
        if(target>nums.at(mid)){
            s=mid+1;
        }
        else if(target<nums.at(mid)){
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
        
        if(nums.at(mid)==target){
            ans=mid;
            s=mid+1;
        }
        if(nums.at(mid)>target){
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
        int y=lOcc(nums,target);
        ans.push_back(x);
        ans.push_back(y);
        
        return ans;
    }
};