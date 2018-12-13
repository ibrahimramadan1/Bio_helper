#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

DNA::DNA() // empty constructor
{
    seq= new char [100]; // Initialize seq

}

DNA::DNA(char * sequen) // Para constructor
{
    seq=new char[100];
    strcpy(seq,sequen); // Copy the content of rhs.seq to seq.


}

DNA::DNA(char * sequen, DNA_Type atype) // Para constructor take sequence and type from user.
{
    seq=new char[100];
    strcpy(seq,sequen);  // Copy the content of rhs.seq to seq.
    type= atype;
}

DNA::DNA(const DNA& rhs) // Copy constructor.
{
    seq=new char [100];
    strcpy(seq,rhs.seq);

}
void DNA::operator=(const DNA& rhs)
{
    seq=new char [strlen(rhs.seq)+1];
    strcpy(seq,rhs.seq);
}

// function printing DNA sequence information to user
void DNA:: Print()
{
    for (int i = 0; i < strlen(seq) ; i++)
    {
        cout << seq[i];
    }
}

DNA::~DNA()
{
    delete[]seq; //delete sequence from heap
}

ostream& operator <<(ostream& out, DNA& obj)
{
    out << obj.seq;
    return out;
}

istream& operator >>(istream& inp, DNA& obj)
{


    inp >> obj.seq;
    return inp;
}

bool DNA::operator==(DNA& seq1)
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



bool DNA::operator!=(DNA& seq1)
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


DNA DNA::operator+(DNA & seq1)
{
    int length  = strlen(seq1.seq); // the length of seq1
    int length1 = strlen(seq);   // the length of seq
    DNA temp; // object from DNA to add concatenate any two sequences in it.
    temp.seq = new char[length + length1]; // Initialize seq with lengths of two sequences.
    // loop to add first sequence.
    for(int i = 0; i < length1; i++)
    {
        temp.seq[i] = seq[i];
    }
    // loop to add second sequence.
    for(int i = length1; i < length + length1; i++)
    {
        temp.seq[i] = seq1.seq[i - length1];
    }


    return temp; // Return temp.
}

RNA DNA::ConvertToRNA()
{
    RNA obj; // object from RNA,
    obj.seq = seq;// and initialize it with the same sequence.
    // loop on the length of seq.
    for (int i = 0; i < strlen(seq); i++)
    {
        if (seq[i] == 'T') // Replace every T with U.
        {
            obj.seq[i] = 'U';
        }
        else
        {
            obj.seq[i] = seq[i];
        }
    }

    return obj; //return obj.
}

void DNA::BuildComplementaryStrand()
{
    // create new object to save it as complement strand in DNA and print it.

    int length=strlen(seq); // length of seq
    complementary_strand= new DNA;
    complementary_strand->seq = new char [length+1];
    //complementary_strand->startIndex = endIndex;
    //complementary_strand->endIndex   = startIndex;
    // loop on the length of seq.

    for (int i=0 ; i<length ; i++)
    {
        // for every A in sequence replace with T , C with G and vice versa.
        if (seq[i]=='A')
           complementary_strand-> seq[i]='T';


        else if (seq[i]=='T')
            complementary_strand->seq[i]='A';

        else if (seq[i]=='C')
            complementary_strand->seq[i]='G';

        else if (seq[i]=='G')
            complementary_strand->seq[i]='C';
    }
    complementary_strand->seq[length]='\0';


}


string DNA :: checkvalidity()
{
    // Exception handling to check if DNA strand is valid or no.
    string a = "";
    for (int i = 0; i < strlen(seq); i++)
    {
        if (strlen(seq)%3!=0)
        {
            a = "number of chars %3 !=0";
            throw a;
        }
        if (seq[i] == 'A'||
                seq[i] == 'C'||
                seq[i] == 'G'||
                seq[i] == 'T')
        {
            continue;
        }
        else
        {

            a += seq[i];

        }
    }

    if (a.length() == 0)
        throw "this is a valid DNA";
    else
        throw a;
}


void DNA::Readfromfile()
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
    seq[read.length()]='\0';
    file.close();
}
}



void DNA::Printtofile()
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




