class Solution {
public:
long  getpalindrome(long left,bool even){
        long res=left;
        if(!even)
        left/=10;
        while(left>0){
            res=(res*10)+(left%10);
            left/=10;
        }
        return res;
    }
    string nearestPalindromic(string n) {
        int ind=n.size()/2;
        bool even=n.size()%2==0;
        if(even)
        ind--;
        long left=stol(n.substr(0,ind+1));
        //5 cases
        vector<long>list;
        //converting ending digits to beggining one
        list.push_back(getpalindrome(left,even));
        //incrementing digits
        list.push_back(getpalindrome(left+1,even));
        //decrementing digits
        list.push_back(getpalindrome(left-1,even));
        //reduce digit by 1
        list.push_back((long)pow(10,n.size()-1)-1);
        //increase digit by 1
        list.push_back((long)pow(10,n.size())+1);

        long res=0,diff=INT_MAX,num=stol(n);
        for(long c:list){
            if(c==num)
            continue;
            long curr=abs(num-c);
            if(diff>curr){
                diff=curr;
                res=c;
            }
            else if(diff==curr){
                res=min(res,c);
            }
        }
        return to_string(res);
    }
};