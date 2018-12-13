#ifndef PROTEIN_H
#define PROTEIN_H

#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "codonstable.h"
#include <iostream>
#include <cstring>
using namespace std;

class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence
{
  	private:
        Protein_Type type;
    public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(const Protein & rhs);
 	 	Protein(char * p);
 	 	Protein (char * p, Protein_Type atype);
 	 	~Protein();

 	 	friend ostream& operator<<(ostream& out,Protein& obj);
        friend istream& operator>>(istream& inp,Protein& obj);
        bool operator== (Protein& obj);//Overloading the == operator should enable you to to check if the two strands are equal or no.

        bool operator!= (Protein& obj);//Overloading the != operator should enable you to to check if the two strands are not equal or no.

        Protein operator+ (Protein& seq1); //Overloading the + operator should enable you to concatenate any two sequences of the same type.

        string checkvalidity();// Exception handling.

        void Readfromfile();
        void Printtofile();
        void Print();


 	 	// return an array of DNA sequences that can possibly
                // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(DNA & bigDNA);
};

#endif // PROTEIN_H
