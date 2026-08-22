#include <iostream>
#include <format> 



int main () {
    int num[100]  = {}; 
    int number = 0;
    for (int i = 0; i < 100 ;i++){

        num[i] = i;
    }  
std::cout << std::format("Enter number between 1-100 : "); 
std::cin >> number;
    for (int k = 0 ; k < 100 ;k++){
        if (number == num[k]){
            std::cout << std::format("Amazing!! that my favourite number too\n");
            std::cout << std::format("Not really {} is my favourite number",number);
            break;
        }
    
    } 
 
    return 0;
} 
