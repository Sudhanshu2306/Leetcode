// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=0; int j=n;
        while(i<j){
            int mid=i+(j-i)/2;
            if(isBadVersion(mid)) j=mid;
            else i=mid+1;

            if(i==j && isBadVersion(j)) return j; 
        }
        return -1;
    }
};