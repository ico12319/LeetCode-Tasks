#include <iostream>

//1710. Maximum Units on a Truck
//You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi:numberOfBoxesi is the number of boxes of type i.numberOfUnitsPerBoxi is the number of units in each box of the type i.You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

bool cmp(std::vector<int>& v1,std::vector<int>& v2){
    return v1[1] > v2[1];
}

int maximumUnits(std::vector<std::vector<int>>& boxTypes,int truckSize){
    const size_t size = boxTypes.size();
    std::sort(boxTypes.begin(),boxTypes.end(),cmp);
    int currBoxes = 0;
    int maxUnits = 0;
    for(int i = 0;i<size;i++){
        if(currBoxes + boxTypes[i][0] <= truckSize){
            maxUnits+=(boxTypes[i][0] * boxTypes[i][1]);
            currBoxes+=boxTypes[i][0];
        }
        else{
            int remaining = truckSize - currBoxes;
            maxUnits+=(remaining * boxTypes[i][1]);
            break;
        }

    }
    return maxUnits;
}

int main(int argc, const char * argv[]) {
    std::vector<std::vector<int>> arr = {{5,10},{2,5},{4,7},{3,9}};
    std::cout<<maximumUnits(arr, 10)<<std::endl;
}
