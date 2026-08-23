#include <iostream>
#include <format>



int main () {
using namespace std;
  

   int s_room = 0;
   cout << format("Number of small room : "); 
   cin >> s_room;
   int l_room = 0;
   cout << format("Number of large room : ");
   cin >> l_room;
   cout << format("Price per small room : $25\n");
   cout << format("Price per large room : $35\n");
   int cost = s_room*25+l_room*35;
   float tax = 0.06*cost;
   cout << format("Cost : {}\n",cost);
   cout << format("Tax : {}\n",tax);

    return 0;
}
