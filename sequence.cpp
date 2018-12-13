#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

Sequence::Sequence()
{

    seq = new char [100];  // Initialize seq

}

Sequence::Sequence(int length)
{
    seq = new char [length]; // Get length from user and Initialize seq with it.
}


Sequence ::Sequence(const Sequence & rhs)
{
    seq = new char [100];
    strcpy(seq,rhs.seq);  // Copy the content of rhs.seq to seq(shallow copy).

}

void Sequence::operator=(const Sequence& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq); // Copy the content of rhs.seq to seq(deep copy).
}

Sequence :: ~Sequence()
{
    delete []seq; //delete sequence from heap
}

string Align(Sequence& s1, Sequence&  s2)
{
    // DP for LCS.
    int row = strlen(s1.seq); // Length of first sequence.
    int col = strlen(s2.seq); // Length of second sequence.
    string LCS[row+1][col+1]; // Create matrix with size first and second sequence to get lCS.

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j<= col; j++)
        {
            if (i == 0 || j == 0)
                LCS[i][j] = "";  // Initialize first row and col empty.

            else if (s1.seq[i-1] == s2.seq[j-1])
                LCS[i][j] = LCS[i-1][j-1] + s1.seq[i-1];

            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    /* LCS[row][col] contains length of LCS for s1.seq[0..col-1] and s2.seq[0..row-1] */
    return LCS[row][col];


}

