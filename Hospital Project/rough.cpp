// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     fstream myFile;
//     string file = "30112022";
//     file.append("-Appointment.csv");
//     cout << file;
//     myFile.open(file, ios::out);
//     myFile << "ABHAY";
//     myFile.close();

//     return 0;
// }



// C++ program to demonstrate getline() function
  
#include <iostream>
#include <string>
using namespace std;
  
int main()
{
    string str;
  
    cout << "Please enter your name: \n";
    getline(cin, str);
    cout << "Hello, " << str
         << " welcome to GfG !\n";
  
    return 0;
}