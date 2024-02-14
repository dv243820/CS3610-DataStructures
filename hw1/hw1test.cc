/**
 *        @file: hw1test
 *      @author: Drew VanAtta
 *        @date: February 08, 2023
 *       @brief: Code for the Standard Deviation
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <cmath> //for square root
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{

   vector<double> numbers;
   int amount;
   cout << "How many numbers do you want to enter?" << endl;
   cin >> amount;
   for (int i = 0; i < amount; i++)
   {
      double addnum;
      cout << "Enter a number to be added" << endl;
      cin >> addnum;
      numbers.push_back(addnum);
   }

   double total = 0; //needed for total
   for (int i = 0; i < amount; i++)
   {
      total = total + numbers[i];
   }
   double mean = total / amount; //gets the mean value

   //standard devation time
   double tmp, tmp2 = 0;
   tmp = (numbers[0] - mean) * (numbers[0] - mean);
   for (int i = 1; i < amount; i++)
   {
   tmp2 = (numbers[i] - mean) * (numbers[i] - mean);
   tmp = tmp + tmp2;
   }
//we should have the correct numerator of the function complete, now to divide by amount and then sqrt
   tmp = tmp / amount;
   tmp = sqrt(tmp);

   cout << "The standard devation of your numbers is: " << tmp << endl;
   






   return 0;
} // main