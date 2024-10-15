#include "./userInput.hpp"
#include "./sumOfArray.hpp"
#include <iostream>
#include <memory>

using namespace std;

namespace input{
    void userInput(){
        int size = 1;
        unique_ptr<int[]> numbers = make_unique<int[]>(size);
        int entries = 0;


        while(true){
            cout << "number: " << endl;
            cin >> numbers[entries];
            if(cin.fail()){
                entries--;
                break;
            }
            entries++;
            if(entries == size){
                size *= 2;
                unique_ptr<int[]> temporaryArray = make_unique<int[]>(size);
                for(int i = 0; i < entries; i++){
                    temporaryArray[i] = numbers[i];
                }
                numbers = make_unique<int[]>(size);
                for(int i = 0; i < entries; i ++){
                    numbers[i] = temporaryArray[i];
                }
                int sum = arraySum::sumOfArray(numbers, entries);
                cout << "sum of ints: " <<  sum << endl;
            }
        }
    }
}