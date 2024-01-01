class Solution {
public:
    /*
    string getPermutation(int n, int k) {
        vector<char> s(n);
        iota(s.begin(), s.end(), '1');
        for(int i=1; i<k; i++)
           next_permutation(s.begin(), s.end()); 
        return string(s.begin(), s.end());
    }
    */
    long long fact(int n){
        if(n==1 || n==0){
            return 1;
        }
        return n*fact(n-1);
    }
    
    string getPermutation(int n, int k){
        long long x=fact(n-1);
        vector<int> num;
        for(int i=1;i<=n;i++){
            num.push_back(i);
        }
        string ans="";
        k-=1;
        while(1){
            ans+=to_string(num[k/x]);
            num.erase(num.begin()+(k/x));
            if(num.size()==0)
                break;
            k%=x;
            x/=num.size();
        }
        return ans;
    }
};