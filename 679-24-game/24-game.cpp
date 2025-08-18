class Solution {
public:
    vector<double> cal(double x, double y){
        return {x-y,y-x,x+y,x*y,x/y,y/x};
    }
    bool f(vector<double> &cards){
        int n=cards.size();
        if(n==1) return abs(cards.back()-24.0)<0.0001; // upto 3 decimal places

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double n1=cards[i], n2=cards[j];
                vector<double> x=cal(n1,n2);
                vector<double> y; for(int k=0;k<n;k++) if(k!=i && k!=j) y.push_back(cards[k]);
                for(auto it:x){
                    y.push_back(it);
                    bool next=f(y);
                    y.pop_back();
                    if(next) return true;
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> x;
        for(auto it:cards) x.push_back(it);
        sort(x.begin(),x.end());

        return f(x);
    }
};