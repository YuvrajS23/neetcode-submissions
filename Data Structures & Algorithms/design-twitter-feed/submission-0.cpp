class Twitter {
    long int timeStamp;
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pair<int, int>>> userTweet;
public:
    Twitter() {
        timeStamp = 0;
        for(int i = 1; i <= 500; i++) {
            followList[i].insert(i);
        }
        for(int i = 1; i <= 500; i++) {
            userTweet[i] = {};
        }
    }
    
    void postTweet(int userId, int tweetId) {
        timeStamp++;
        userTweet[userId].push_back({timeStamp, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int>& followers = followList[userId];
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& follower: followers) {
            vector<pair<int, int>>& tweets = userTweet[follower];
            for(const auto& tweet: tweets) {
                maxHeap.push(tweet);
            }
        }
        vector<int> res;
        for(int i=0; i<10; i++){
            if(!maxHeap.empty()){
                pair<int, int> tweet = maxHeap.top();
                maxHeap.pop();
                res.push_back(tweet.second);  
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followList[followerId].erase(followeeId);
    }
};
