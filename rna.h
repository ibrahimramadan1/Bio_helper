#ifndef RNA_H
#define RNA_H
#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class DNA;
class CodonsTable;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};
//template <typename T>
class RNA : public Sequence//<T>
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * sequen, RNA_Type atype);
        RNA(char * sequen);
        RNA(const RNA& rhs);
        ~RNA();
        friend istream& operator>>(istream& inp,RNA & obj);
        friend ostream& operator<<(ostream& out,RNA& obj);

        bool operator== (RNA& seq1); //Overloading the == operator should enable you to to check if the two strands are equal or no.

        bool operator!= (RNA& seq1); //Overloading the != operator should enable you to to check if the two strands are not equal or no.

        RNA operator+ (RNA& seq1); //Overloading the + operator should enable you to concatenate any two sequences of the same type.

        string checkvalidity(); // Exception handling.
 	 	// function to be overridden to print all the RNA information
        void Print();

        void Readfromfile();
        void Printtofile();


 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein(CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};
#endif // RNA_H
