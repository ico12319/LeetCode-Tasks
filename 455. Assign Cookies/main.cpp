#include <iostream>

//455. Assign Cookies
// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.

int findContentChidren(std::vector<int>& g,std::vector<int>& s){
    std::sort(g.begin(),g.end());
    std::sort(s.begin(),s.end());
    const size_t gSize = g.size();
    const size_t sSize = s.size();
    int matches = 0;
    int gIndex = 0;
    int sIndex = 0;
    
    while(gIndex < gSize && sIndex < sSize){
        if(g[gIndex] <= s[sIndex]){
            matches++;
            gIndex++;
            sIndex++;
        }
        else
            sIndex++;
    }
    return matches;
}

int main(int argc, const char * argv[]) {
    std::vector<int> g = {1,2};
    std::vector<int> s = {1,2,3};
    std::cout<<findContentChidren(g, s)<<std::endl;
}
