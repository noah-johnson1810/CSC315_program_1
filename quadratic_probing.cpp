/*
Noah Johnson and Drew Norby
CSC315
10/17/2021
Dr. Rohan Loveland
*/


#include "quadratic_probing.h"
#include <iostream>
using namespace std;


int main()
{
    HashTable<int> H;

    const int NUMS = 4000;
    const int GAP = 37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
        H.insert(i);
    for (i = 1; i < NUMS; i += 2)
        H.remove(i);

    for (i = 2; i < NUMS; i += 2)
        if (!H.contains(i))
            cout << "Contains fails " << i << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (H.contains(i))
            cout << "OOPS!!! " << i << endl;
    }

    return 0;
}

/**
 * Internal method to test if a positive number is prime.
 * Not an efficient algorithm.
 */
bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n == 1 || n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime(int n)
{
    if (n <= 0)
        n = 3;

    if (n % 2 == 0)
        n++;

    for (; !isPrime(n); n += 2)
        ;

    return n;
}

/**
 * A hash routine for string objects.
 */
int hash(const string& key)
{
    int hashVal = 0;

    for (int i = 0; i < key.length(); i++)
        hashVal = 37 * hashVal + key[i];

    return hashVal;
}

/**
 * A hash routine for ints.
 */
int hash(int key)
{
    return key;
}

