class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        queue<int> q1,q2;
        int ans=0;
        for(int i=0;i<n;i++){
            q1.push(students[i]);
            q2.push(sandwiches[i]);
        }

        while(ans!=q1.size()){
            if(q1.front()==q2.front()){
                q1.pop(); q2.pop();
                ans=0;
            }
            else{
                int temp=q1.front();
                q1.pop();
                q1.push(temp);
                ans++;
            }
        }
        return ans;
    }
};