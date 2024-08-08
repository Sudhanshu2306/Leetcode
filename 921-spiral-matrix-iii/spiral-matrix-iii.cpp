class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int tot=rows*cols;
        int sr=rStart;
        int sc=cStart;
        
        int count=1;
        int size=1;
        ans.push_back({sr,sc});
        while(count<tot){
            int x=1;
            while(x<=size){
                sc++;
                if(sr<rows && sr>=0 && sc>=0 && sc<cols){
                    ans.push_back({sr,sc}); count++;
                }
                x++;
            }

            x=1;
            while(x<=size){
                sr++;
                if(sr<rows && sr>=0 && sc>=0 && sc<cols){
                    ans.push_back({sr,sc}); count++;
                }
                x++;
            }
            size++;
            x=1;
            while(x<=size){
                sc--;
                if(sr<rows && sr>=0 && sc>=0 && sc<cols){
                    ans.push_back({sr,sc}); count++;
                }
                x++;
            }

            x=1;
            while(x<=size){
                sr--;
                if(sr<rows && sr>=0 && sc>=0 && sc<cols){
                    ans.push_back({sr,sc}); count++;
                }
                x++;
            }
            size++;
        }
        return ans;
    }
};