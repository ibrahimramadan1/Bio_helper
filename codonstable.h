#ifndef CODONSTABLE_H
#define CODONSTABLE_H


#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};
// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	protected:
        Codon codons[64];
   	public:
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);
        // function to be overridden to print all the RNA information
        void print();
};

#endif // CODONSTABLE_H
