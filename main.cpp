#include <iostream>
#include <vector>
#include <unordered_set>
#include <memory>

int main() {
    std::vector<int> vec{1,2,3,4,1,5,2,7,7,0,9,1,7,7,7};

    auto lambdaFunction([] (std::vector<int>& vec){
       std::unordered_set<int> unSet;
        auto ptrVec = std::make_unique<std::vector<int>>();
       unSet.insert(vec.at(0));
       ptrVec->emplace_back(vec.at(0));
       for(auto & el : vec){
           if(unSet.find(el) == unSet.end()){
               unSet.insert(el);
               ptrVec->emplace_back(el);
          }
       }
        return ptrVec;
    });

    auto ptrVec = lambdaFunction(vec);
    for(auto& el : vec )
        std::cout << el << " " ;
    std::cout << std::endl;
    for(auto& el : *ptrVec.get())
        std::cout << el << " ";
    std::cout << std::endl;
    return 0;
}
