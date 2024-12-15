#include <iostream>
#include <queue>

//1451. Rearrange Words in a Sentence
//Given a sentence text (A sentence is a string of space-separated words) in the following format:First letter is in upper case.Each word in text are separated by a single space.Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.Return the new text following the format shown above.

struct custom_compare{
    bool operator()(const std::pair<std::string,std::pair<size_t,int>>& p1,const std::pair<std::string,std::pair<size_t,int>>& p2) const{
        if(p1.second.first == p2.second.first)
            return p1.second.second > p2.second.second;
        return p1.second.first > p2.second.first;
    }
};

std::string arrange_words(std::string& text){
    using type = std::pair<size_t,int>;
    std::vector<std::string> parsed_string;
    text+=' ';
    std::string temp;
    for(const auto& el : text){
        if(el != ' ')
            temp+=std::tolower(el);
        else{
            parsed_string.push_back(temp);
            temp.clear();
        }
    }
    
    std::vector<std::pair<std::string, std::pair<size_t, int>>> v;
    
    for(int i = 0; i < parsed_string.size(); i++)
        v.emplace_back(parsed_string[i], std::make_pair(parsed_string[i].length(), i));
    
    std::priority_queue<std::pair<std::string,std::pair<size_t,int>>, std::vector<std::pair<std::string,std::pair<size_t,int>>>,custom_compare> pq(v.begin(),v.end());
  
    std::string to_return;
    while(!pq.empty()){
        to_return+=pq.top().first;
        pq.pop();
        if(pq.empty())
            break;
        to_return+=' ';
    }
    char first_symbol = to_return.at(0);
    to_return.at(0) = std::toupper(first_symbol);
    return to_return;
    
}

int main(int argc, const char * argv[]) {
    std::string text = "Leetocde is cool";
    std::cout<<arrange_words(text)<<std::endl;
}
