#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <cstring>
using namespace std;


class Sequence  // Base class.
{
    public:
        char * seq;

        Sequence();                      // Empty constructor.
        Sequence(int length);            // Para constructor to get length.
        Sequence(const Sequence& rhs);   // Copy constructor.


        virtual ~Sequence();             // Virtual destructor to delete sequence from heap

        virtual void Print()= 0;
        void operator=(const Sequence& rhs);
        friend string Align(Sequence&  s1, Sequence& s2);  // LCS function to get the longest common subsequence of two strings.




};

#endif // SEQUENCE_H
