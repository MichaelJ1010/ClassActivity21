#include "./sumOfArray.hpp"
#include <iostream>

namespace sumArray{
    int sumOfArray(int* list, int size){ //sums up all items
        int sum = 0;

        for(int i = size; i >= 0; i--){
            sum += *list;
            list++;
        }
        return sum;
    }
}