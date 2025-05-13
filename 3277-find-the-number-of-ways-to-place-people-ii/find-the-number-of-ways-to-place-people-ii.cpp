#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;  // find_by_order, order_of_key

class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        return a[1]>b[1];
    }
    int numberOfPairs(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),comp);
        int n=a.size();
        long long count=0;
        for(int i=0;i<n;i++){
            set<int> st;
            for(int j=i+1;j<n;j++){
                int x1=a[i][0],x2=a[j][0];
                int y1=a[i][1],y2=a[j][1];
                if(y1<y2) continue;

                if(st.lower_bound(y2)!=st.end()) continue;
                count++;
                st.insert(y2);
            }
        }
        return count;
    }
};