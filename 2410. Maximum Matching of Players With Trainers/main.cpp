#include <iostream>
// 2410. Maximum Matching of Players With Trainers
//You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.
//The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.
//Return the maximum number of matchings between players and trainers that satisfy these conditions.

int matchPlayersAndTrainers(std::vector<int>& players,std::vector<int>& trainers){
    const size_t playersCount = players.size();
    const size_t trainersCount = trainers.size();
    std::sort(players.begin(),players.end());
    std::sort(trainers.begin(),trainers.end());
    int playersIndex = 0;
    int trainerIndex = 0;
    int matches = 0;
    
    while(playersIndex < playersCount && trainerIndex < trainersCount){
        if(players[playersIndex] <= trainers[trainerIndex]){
            matches++;
            playersIndex++;
            trainerIndex++;
        }
        else
            trainerIndex++;
    }
    return matches;
}

int main(int argc, const char * argv[]) {
    std::vector<int> players = {4,7,9};
    std::vector<int> trainers = {8,2,5,8};
    std::cout<<matchPlayersAndTrainers(players, trainers)<<std::endl;
}
