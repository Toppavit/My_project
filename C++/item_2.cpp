#include <iostream>
#include <format>



int main () {
using namespace std;


    int num_1,num_2 ;
    cout << format("Enter first interger : ");
    cin >> num_1;
    cout << format("Enter second number : ");
    cin >> num_2;

    cout << format("Result\n");
    cout << format("Sum : {}\n",num_1+num_2);
    cout << format("Differnce : {}\n",num_1-num_2);
    cout << format("Product : {}\n",num_1*num_2);
    cout << format("Quotent (Interger Divison) : {}\n",num_1/num_2); 

    return 0;
}
