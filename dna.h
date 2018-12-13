#ifndef DNA_H
#define DNA_H
#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class RNA;

enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
//        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
        DNA * complementary_strand;
 	 	// constructors and destructor
        DNA();
        DNA(char * sequen, DNA_Type atype);
        DNA(char * sequen);
        DNA(const DNA& rhs);
        ~DNA();
        void operator=(const DNA &rhs);

        string checkvalidity();   // Exception handling.

        bool operator== (DNA& obj); //Overloading the == operator should enable you to to check if the two strands are equal or no.

        bool operator!= (DNA& obj); //Overloading the != operator should enable you to to check if the two strands are not equal or no.

        DNA operator+ (DNA& seq1); //Overloading the + operator should enable you to concatenate any two sequences of the same type.

 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();

        void Readfromfile();
        void Printtofile();

        friend ostream& operator <<(ostream& out,DNA& obj);


        friend istream& operator >>(istream& inp,DNA& obj);



  };

#endif // DNA_H
