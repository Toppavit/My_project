#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <cctype>
#include <cstring> 


int main () {

 using namespace std; 
/* char first_name[20] {} ;
char last_name [50]{} ;
 char full_name [50] {};
 char temp [50] {} ;


   cout << format ("Please enter your first name : ");
   cin >> first_name;

   cout << format("Please enter your surname : ");
   cin >> last_name;

   cout << format ("Hello {} your first name has {} characters\n",first_name,strlen(first_name)); 

   cout << format ("and your last name {} has {} characters\n",last_name,strlen(last_name)); 


       strcpy(full_name , first_name);
       strcat(full_name, " "); 
       strcat(full_name,last_name);
       cout << format("{}",full_name);*/
  char full_name[50] {} ;
 cout << "Enter your full name :  " << endl;
 cin.getline(full_name,50); 
 cout << "Your full name is " << full_name << endl;
       
return  0;
} 
