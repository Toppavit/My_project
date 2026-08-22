#include <iostream>
#include <string>
#include <format>




int main() {

using namespace std;

int num_1 = 0 ;
     cout << format("Enter first number : ");
     cin >> num_1;
char op;
     cout << format("Enter operator (+,-,*,/): "); 
     cin  >> op;
int num_2 = 0;
     cout << format("Enter second number : ");
     cin >> num_2;

   int result = 0;
switch (op) {
    case '+':
        result = num_1 + num_2;
        cout << format("{} + {} = {}\n", num_1, num_2, result);
        break;
    case '-':
        result = num_1 - num_2;
        cout << format("{} - {} = {}\n", num_1, num_2, result);
        break;
    case '*':
        result = num_1 * num_2;
        cout << format("{} * {} = {}\n", num_1, num_2, result);
        break;
    case '/':
        result = num_1 / num_2;
        cout << format("{} / {} = {}\n", num_1, num_2, result); // added semicolon
        break;
    default:
        cout << "Invalid operator\n";
        break;
}
return 0;
}
