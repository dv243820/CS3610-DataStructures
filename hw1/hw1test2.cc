/**
 *        @file: Untitled-4
 *      @author: Drew VanAtta
 *        @date: February 9, 2023
 *       @brief: HW 1 Last question from book convert to recursion function
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


//I'm not sure if we need more than this, but I figured this should work

template <class elemType> // from the book
int seqSearch(const elemType list[], int length, const elemType &item)
{

    if (length >= 0)
    {
        if (list[length - 1] == item)
        {
            return length - 1;
        }
        else
        {
            return seqSearch(list, length - 1, item); // recursive call
        }

        return 0;
    }
} // main
