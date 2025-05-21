class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool fcol=false;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                fcol=true;
            }
            
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        // first row aur first column ko chor ke saare case cover ho rahe h, tabhi i=1 aur j=1 se start ho raha h
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }

        // first row mein agar zero hain toh vo cover kar raha h ye case
        if(matrix[0][0]==0){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        // first column mein zero ho toh vo cover kar raha h ye case
        if(fcol==true){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};