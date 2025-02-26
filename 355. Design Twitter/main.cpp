#include <iostream>
#include <unordered_set>
#include <forward_list>

//355. Design Twitter
//Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

class twitter{
private:
    std::unordered_map<int, std::unordered_set<int>> user_followers;
    std::forward_list<std::pair<int,int>> tweets;
    
public:
    twitter() = default;
    void follow(int follower_id,int followee_id){ // O(1)
        user_followers[follower_id].insert(followee_id);
    }
    
    void unfollow(int follower_id,int followee_id){ // O(1)
        if(user_followers.contains(follower_id)){
            if(user_followers[follower_id].contains(followee_id))
                user_followers[follower_id].erase(followee_id);
        }
    }
    
    void post_tweet(int user_id,int tweet_id){ // O(1)
        tweets.push_front(std::make_pair(user_id, tweet_id));
    }
    
    std::vector<int> get_news_feed(int user_id){ // O(n)
        std::vector<int> news_feed;
        int max_size = 0;
        for(const auto& pair : tweets){
            if(max_size == 10)
                break;
            if(user_followers[user_id].contains(pair.first) || pair.first == user_id){
                news_feed.push_back(pair.second);
                max_size++;
            }
        }
        return news_feed;
        
    }
    
};


int main(int argc, const char * argv[]) {
    twitter* tw = new twitter();
    tw->post_tweet(1, 5);
    auto v1 = tw->get_news_feed(1);
    tw->follow(1, 2);
    tw->post_tweet(2, 6);
    auto v2 = tw->get_news_feed(1);
    tw->unfollow(1, 2);
    auto v3 = tw->get_news_feed(1);
    delete tw;
}
