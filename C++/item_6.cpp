#include <iostream>
#include <vector>
#include <format>



int main () {
using namespace std;
    vector <int> vector_1 {};
    vector <int> vector_2 {};

    vector_1.push_back(10);
    vector_1.push_back(20);

    cout << format("{} {} {}",vector_1.at(0),vector_1.at(1),vector_1.size());
    


    return 0;
} 
