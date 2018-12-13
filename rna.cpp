#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

RNA::RNA() // empty constructor
{
    seq= new char [100]; // Initialize seq
}

RNA::RNA(char * sequen) // Para constructor
{
    seq=new char[100];
    strcpy(seq,sequen); // Copy the content of rhs.seq to seq.


}

RNA::RNA(char * sequen, RNA_Type atype) // Para constructor take sequence and type from user.
{
    type=atype;
    seq=new char[100];
    strcpy(seq,sequen);// Copy the content of rhs.seq to seq.


}

RNA::RNA(const RNA& rhs) // Copy constructor.
{
    type = rhs.type;
    seq=new char[100];
    strcpy(seq,rhs.seq);

}

RNA::~RNA()
{
    delete[]seq; //delete sequence from heap
}

// function printing DNA sequence information to user
void RNA::Print()
{
    int length = strlen(seq); //length of seq.
    for (int i=0; i<=length; i++)
    {
        cout<<seq[i];
    }
}


DNA RNA:: ConvertToDNA()
{
    DNA obj; // object from DNA,
    obj.seq = seq; // and initialize it with the same sequence.
    // loop on the length of seq.
    for (int i=0; i<strlen(seq); i++)
    {
        // Replace every U with T.
        if (seq[i]=='U')
        {
            obj.seq[i]='T';
        }
        else
        {
            obj.seq[i]=seq[i];
        }
    }

    return obj; //return obj.
}


istream& operator>>(istream& inp,RNA & obj)
{
    inp>>obj.seq;
    return inp;
}


ostream& operator<<(ostream& out,RNA& obj)
{
    out<<obj.seq<<endl;
    return out;
}



bool RNA::operator==(RNA& seq1)
{

    bool x = false; // bool variable
    int length1 = strlen(seq1.seq); // the length of seq1
    int length2 = strlen(seq); // the length of seq

    if (length1 == length2)
    {
        for(int i = 0; i < length1; i++)
        {
            if(seq1.seq[i] == seq[i])
                x = true; // x become true.
            else
                x = false;
        }
        if (x) // if x true
            return true;
        else
            return false;

    }
    else
        return false;
}



bool RNA::operator!=(RNA& seq1)
{
    bool x = false; // bool variable
    int length1 = strlen(seq1.seq);// the length of seq1
    int length2 = strlen(seq);  // the length of seq
    if (length1 == length2)
    {
        for(int i = 0; i < length1; i++)
        {
            if(seq1.seq[i] == seq[i])
                x = true; // x become true.
            else
                x = false;
        }
        if (x) // if x true
            return false;
        else
            return true;

    }
    else
        return true;
}


RNA RNA::operator+(RNA & seq1)
{

    int length = strlen(seq1.seq);// the length of seq1
    int length1 = strlen(seq);    // the length of seq
    RNA temp; // object from RNA to add concatenate any two sequences in it.
    temp.seq = new char[length+length1];
    // loop to add first sequence.
    for(int i=0; i<length1; i++)
    {
        temp.seq[i] = seq[i];
    }
    // loop to add second sequence.
    for(int i=length1; i<length+length1; i++)
    {
        temp.seq[i] = seq1.seq[i-length1];
    }


    return temp; // Return temp.
}


Protein RNA::ConvertToProtein(CodonsTable & table)
{
    Codon a; // object from struct codon
    Protein obj; //object from protein
    int length = strlen(seq); // length of seq.
    obj.seq = new char [length/3]; // divide sequence to codon

    char* value= new char[3]; // value = 3 chat like AAA

    int k=0;

    for (int i=0; i<length/3; i++)
    {
        // first codon.
        value[0]=seq[k];
        value[1]=seq[k+1];
        value[2]=seq[k+2];

        // second codon
        k+=3;

        a = table.getAminoAcid(value); // Get amino acid according the value

        obj.seq[i] = a.AminoAcid;  // set every seq to amino acid
    }
    return obj; // return obj
}
// Exception handling to check if DNA strand is valid or no.
string RNA :: checkvalidity()
{
    string a = "";
    for (int i = 0; i < strlen(seq); i++)
    {
        if (strlen(seq) % 3 != 0)
        {
            a = "number of chars %3 !=0";
            throw a;
        }
        if (seq[i] == 'A'||
                seq[i] == 'C'||
                seq[i] == 'G'||
                seq[i] == 'U')
        {
            continue;
        }
        else
        {

            a += seq[i];

        }
    }

    if (a.length() == 0)
        throw "this is a valid RNA";
    else
        throw a;
}


void RNA::Readfromfile()
{

    string name;
    cout<<"name of the file: ";
    cin>>name;

    ifstream file(name.c_str(),ios::in);
    string read;
    if (!file)
    {
        cout<<"error loading file ! \n";
    }
    else{
    while (!file.eof())
    {
        getline(file,read);
    }
    cout<<"i am here \n";
    seq=new char[read.length()+1];

    for (int i=0;i<read.length();i++)
    {
        seq[i]=read[i];
    }
    file.close();
    seq[read.length()]='\0';
}
}



void RNA::Printtofile()
{
    string name;
    cout<<"name of the file: ";
    cin>>name;

    ofstream file(name.c_str(),ios::out);


    for (int i=0;i<strlen(seq);i++)
    {
        file<<seq[i];
    }

    file.close();


}


