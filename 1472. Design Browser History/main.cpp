#include <iostream>
#include <list>

//1472. Design Browser History
//You have a browser of one tab where you start on the homepage and you can visit another url, get back in the history number of steps or move forward in the history number of steps.
//BrowserHistory(string homepage) Initializes the object with the homepage of the browser.
//void visit(string url) Visits url from the current page. It clears up all the forward history.
//string back(int steps) Move steps back in history. If you can only return x steps in the history and steps > x, you will return only x steps. Return the current url after moving back in history at most steps.
//string forward(int steps) Move steps forward in history. If you can only forward x steps in the history and steps > x, you will forward only x steps. Return the current url after forwarding in history at most steps.

class browser_history{
private:
    std::list<std::string> data;
    std::list<std::string>::iterator curr_tab;
    
public:
    browser_history(const std::string& hompe_page){
        data.push_front(hompe_page);
        curr_tab = data.begin();
    }
    void visit(const std::string& url){
        if(curr_tab != --data.end()){
            auto next = std::next(curr_tab);
            data.erase(next, data.end());
        }
        data.push_back(url);
        curr_tab = --data.end();
    }
    
    std::string back(int steps){
        for(int i = 0;i<steps;i++){
            if(curr_tab!=data.begin())
                curr_tab--;
            else
                return *curr_tab;
        }
        return *curr_tab;
    }
    
    std::string forward(int steps){
        for(int i = 0;i<steps;i++){
            if(curr_tab != --data.end())
                curr_tab++;
            else
                return *curr_tab;
        }
        return *curr_tab;
    }
};

int main(int argc, const char * argv[]) {
    browser_history history("leetocode.com");
    history.visit("google.com");
    history.visit("facebook.com");
    history.visit("youtube.com");
    std::cout<<history.back(1)<<std::endl;
    std::cout<<history.back(1)<<std::endl;
    std::cout<<history.forward(1)<<std::endl;
    history.visit("linkedin.com");
    std::cout<<history.forward(2)<<std::endl;
    std::cout<<history.back(2)<<std::endl;
    std::cout<<history.back(2)<<std::endl;
    
}
