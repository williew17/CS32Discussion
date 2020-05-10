//
//  main.cpp
//  5disc
//
//  Created by Willie Wu on 2/6/20.
//  Copyright © 2020 Willie Wu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;


// Return true if num is a power of 4
// e.g 1, 4, 16, 64...
// return false otherwise
bool isPowerOfFour(int num)
{
    if (num == 1) //base case for 4^0
        return true;
    if (num == 0 || num % 4 != 0)
        return false;
    
    return isPowerOfFour(num/4);
}
//64 -> 16 -> 4 -> 1 -> true

/* Function to count subtrings with same first and
  last characters
 i = start index for substring
 j = end index for substr
 n = number of elements in the array*/

//abca ->  a b c a abca <- matches

// not matchea: ab abc bc bca ca

//original string is abca
//split into 2 case
// abc         bca        b c
//"b" "c"         //"b" "c"      "b" "c" are taken out

int countSubstrs(string str, int i, int j, int n)
{
    if (n == 1) //when length of array is 1 always match 1 substring
        return 1;
    if (n <= 0) //empty string case
        return 0;
    int res = 0;
    if (str[i] == str[j]) //this the most outer layer
        res++;
    res = res + countSubstrs(str, i+1, j, n-1) +
                countSubstrs(str, i, j-1, n-1) -
                countSubstrs(str, i+1, j-1, n-2);
    return res;
}

//res = 1 + 4 = 5

//abc -> 3 +
//bca -> 3 -
//bc -> b c -> 2



int main(int argc, const char * argv[]) {
    cout << "start" << endl;
    assert(isPowerOfFour(16));
    
    string str = "abcab";
    int n = int(str.length());
    assert(countSubstrs(str, 0, n-1, n) == 7);
    int a[5] = {1,2,8,4,5};
    assert(sumOverThreshold(a, 5, 10) == 11);
    assert(sumOverThreshold(a, 5, 40) == -1);
    assert(sumOverThreshold(a, 5, 0) == 1);
    assert(sumOverThreshold(a, 5, 20) == -1);
    assert(sumOverThreshold(a, 5, 14) == 15);
}

































