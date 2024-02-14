/**
 *        @file: project1.cc
 *      @author: Drew VanAtta
 *        @date: January 25, 2023
 *       @brief: CS3610 Project One - Prime Number Sort (The Sieve of Eratosthenes)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

/// function prototypes

int main(int argc, char const *argv[])
{
    // FIRST DEALING WITH THE INPUT
    if (argv[1] == NULL) // If no arguments
    {
        cout << "Missing arguments" << endl;
        return 0;
    }
    if (argv[2] != NULL)
    {
        cout << "Too many arguments" << endl;
        return 0;
    }
    // convert the string "10" into an int
    int num = stoi(argv[1]);

    if (!(num <= 30000 && num >= 2)) // if it isn't in the range, exit
    {
        cout << "Out of range" << endl;
        return 0;
    }
    // DONE DEALING WITH INPUT, IT IS NOW AN INT

    bool arr[num - 2]; // create our array with -2 because we start at 2 instead of 0

    // this for loop fills up the array
    for (int i = 0; i <= num - 2; i++) // start at 0, go until end of array
    {
        arr[i] = true; // this sets everything to true
    }


    // now we need to start in the first spot (2, which is prime), and go every i+2 until the end

    for (int i = 0; i * i <= num; i++)
    {
        if (arr[i] == true)
        {
            for (int j = i * i; j <= num; j += i)
            {
                arr[j+2] = false;
            }
        }
    }

    for (int i = 0; i <= num - 2; i++) // OUTPUTTING THE PRIMES IN A ROW
    {
        if (arr[i] == true)
        {
            cout << (i + 2) << " ";
        }
    }
    cout << endl
         << endl
         << endl;
    bool copyarr[num - 2];
    for (int i = 0; i <= num - 2; i++)
    {
        copyarr[i] = arr[i];
    }

    for (int i = 0; i <= num - 2; i++) // OUTPUTTING THE PRIMES IN A ROW
    {
        if (copyarr[i] == false)
        {
            cout << (i + 2) << " ";
        }
    }

    return 0;
} // main