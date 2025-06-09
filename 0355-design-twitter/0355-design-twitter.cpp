class Twitter {
public:
    vector<pair<int,int>> posts;
    map<int,map<int,int>> mp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count=0;
        for(int i=posts.size()-1;i>=0;i--){
            if(posts[i].first==userId || mp[userId][posts[i].first]){
                count++;
                feed.push_back(posts[i].second);
            } 
            if(count==10) break;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId][followeeId]=0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */