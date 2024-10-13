class Node{
    public:
        int data;
        int row;
        int col;

        Node(int d,int r, int c){
            this->data=d;
            this->row=r;
            this->col=c;
        }
};

class compare{
    public: 
        bool operator()(Node* a, Node* b){
            return a->data>b->data;
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        vector<int> ans;

        int k=nums.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;

        for(int i=0;i<k;i++){
            int element=nums[i][0];
            maxi=max(maxi,element);
            mini=min(mini,element);
            minHeap.push(new Node(element,i,0));
        }

        int start=mini, end=maxi;

        while(!minHeap.empty()){
            Node* temp=minHeap.top();
            minHeap.pop();
            mini=temp->data;
            int row=temp->row;

            if((maxi-mini)<(end-start)){
                start=mini;
                end=maxi;
            }

            if((temp->col)+1 < nums[row].size()){
                maxi=max(maxi,nums[row][temp->col+1]);
                minHeap.push(new Node(nums[row][temp->col+1],row,temp->col+1));
            }
            else{
                break;
            }
        }
        ans.push_back(start);
        ans.push_back(end);

        return ans;
    }
};