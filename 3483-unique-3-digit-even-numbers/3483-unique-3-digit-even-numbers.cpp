class Solution {
public:
    bool f(int n){
        int x=0;
        while(n){
            x++;
            n/=10;
        }
        return x==3;
    }
    int totalNumbers(vector<int>& a) {
        set<int> st;
        int n=a.size();
        for(int i=0;i<n;i++){
            int x=a[i];
            for(int j=0;j<n;j++){
                if(j!=i){
                    int y=x*10+a[j];
                    for(int k=0;k<n;k++){
                        if(k!=j && k!=i){
                            int z=y*10+a[k];
                            if(f(z) && z%2==0) st.insert(z);
                        }
                    }
                }
            }
        }
        return st.size();
    }
};