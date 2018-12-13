#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

CodonsTable::CodonsTable() // empty constructor.
{

}

CodonsTable::~CodonsTable() // destructor
{

}


void CodonsTable::LoadCodonsFromFile(string name)
{
    ifstream file; // file to read.
    file.open(name.c_str(), ios::in); // open the file

    if (!file) // check there error in file.
        cout<<"error loading file\n";
    else
    {
        string line;
        int k = 0;
        while (!file.eof()) // while file not ended.
        {
            getline(file,line); //read from file

            if (line.length()==5) // if there is two space.
            {
                for(int i=0; i<4; i++)
                {
                    codons[k].value[i]=line[i];
                }
                codons[k].AminoAcid=line[4];
                k++;
            }
            else
            {
                for(int i=0; i<4; i++) // if there is one space
                {
                    codons[k].value[i]=line[i];
                }
                codons[k].AminoAcid=line[3];
                k++;

            }
        }

    }
}

Codon CodonsTable::getAminoAcid(char* value)
{
    for (int i=0; i<64; i++)
    {
        if (value[0]==codons[i].value[0]&& value[1]==codons[i].value[1]&& value[2]==codons[i].value[2])
        {
            return codons[i];
        }
    }
}


void CodonsTable ::  setCodon(char * value, char AminoAcid, int index)
{
    codons[index].value[0]=value[0];
    codons[index].value[1]=value[1];
    codons[index].value[2]=value[2];
    codons[index].value[3]=' ';

    codons[index].AminoAcid=AminoAcid;
}
// function to be overridden to print all the RNA information.
void CodonsTable :: print()
{
    for (int i=0; i<64; i++)
    {
        for (int j=0; j<4; j++)
            cout<<codons[i].value[j];

        cout<<"    "<<codons[i].AminoAcid<<endl;
    }
}
