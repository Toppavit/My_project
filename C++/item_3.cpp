#include <iostream>
#include <format>

int main () {
using namespace std;
int A = 100;
int B = 20;
    cout << format("Before swap : A = {},B = {}\n",A,B); 
    A = A+B;
    B = A-B;
    A = A-B;
    cout << format("After swap : A = {} ,B = {}\n ",A,B);
return 0;
}
