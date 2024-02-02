class Solution {
public:

    void f(int start, int low, int high, vector<int> &ans){
        if(start>high) return;
        if(start>=low) ans.push_back(start);

        int last=start%10;
        if(last<9)
            return f(start*10+(last+1),low, high, ans);
    }
    // this is recursive solution
    /*
    vector<int> sequentialDigits(int low, int high){
        vector<int> ans;
        for(int start=1;start<10;start++){
            f(start,low,high,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    */

    // iterative solution
    vector<int> sequentialDigits(int low, int high){
        vector<int> ans;
        for(int start=1;start<10;start++){
            int num=start;
            int next=start+1;
            while(num<=high && next<=9){
                num*=10; num+=next;
                if(num>=low && num<=high) ans.push_back(num);
                next++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    // this is pure observation, but this is more of manual work!
    /*
    vector<int> sequentialDigits(int low, int high) {
        set<int> st = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,
        789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,
        234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789};

        vector<int> ans;
        for(auto i:st){
            if(i>=low && i<=high){
                ans.push_back(i);
            }
        }
        return ans;
    }
    */
};