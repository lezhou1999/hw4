#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;


vector<int> largest_divisible_pairs(vector<int> input) {
  sort(input.begin(), input.end());

  vector<int> marks(input.size(), 0);
  vector<int> dp(input.size(), 1);
  vector<int> results;

  int maxCount = 1;
  int maxIndex = 0;
  for (std::vector<int>::size_type i = 1; i < input.size(); i++) {
    int max = 0;
    long long unsigned int markIndex = i;
    for (std::vector<int>::size_type j = 0; j < i; j++) {
      if (input[i] % input[j] == 0 && dp[j] > max) {
        max = dp[j];
        markIndex = j;
      }
    }

    if (markIndex != i) {
      dp[i] += max;
      marks[i] = markIndex;

      if (dp[i] > maxCount) {
        maxCount = dp[i];
        maxIndex = i;
      }
    } else {
      marks[i] = markIndex;
    }
  }


  int index = maxIndex;
  while (true) {
    results.push_back(input[index]);
    if (index == marks[index]) {
      break;
    }
    index = marks[index];
  }
  std::reverse(results.begin(), results.end());
  return results;
}


string vec_to_string(vector<int> n){
    
    std::string toInsert = std::to_string(n.at(0));
    //std::vector<int>::size_type a = n.at(0);
    string stringOut ("[");

    for(std::vector<int>::size_type i=0;i<n.size()-1;i++){
        std::string toInsert = std::to_string(n.at(i));
        toInsert=toInsert+", ";
        stringOut.append(toInsert);

    }
    std::string finalNum = std::to_string(n.at(n.size()-1));
    stringOut.append(finalNum);
    stringOut.append("]");
    return stringOut;
}

int main() {
  vector<int> input;
  input.push_back(28);
  input.push_back(22);
  input.push_back(7);
  input.push_back(1);
  input.push_back(8);
  input.push_back(14);
  input.push_back(24);
  input.push_back(56);

  cout << "the sample is:" << vec_to_string(input)<<endl;
  cout<<"Result1: "<<vec_to_string( largest_divisible_pairs(input))<<endl;

  
  return 0;
}


