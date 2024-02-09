class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q;
        int top=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(students[i]==sandwiches[top]){
                top++;
            }
            else q.push(students[i]);
        }

        while(ans!=q.size()){
            int temp=q.front();
            if(sandwiches[top]==temp){
                ans=0;
                q.pop();
                top++;
            }
            else{
                q.push(temp);
                q.pop();
                ans++;
            }
        }
        return ans;
    }
};