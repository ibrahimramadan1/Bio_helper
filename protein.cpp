#include "codonstable.h"
#include "rna.h"
#include "dna.h"
#include "sequence.h"
#include "protein.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

Protein::Protein() // empty constructor.
{
    seq= new char [100]; // Initialize seq
}

Protein :: Protein (char * p) // Para constructor.
{
    seq=new char [100];
    strcpy(seq,p);  // Copy the content of rhs.seq to seq.

}

Protein::Protein(const Protein & rhs) // Copy constructor.
{
    seq=new char [100];
    strcpy(seq,rhs.seq);
}


Protein :: Protein (char * p, Protein_Type atype) // Para constructor take sequence and type from user.
{
    type= atype;
    seq=new char [100];
    strcpy(seq,p);

}

Protein::~Protein()
{
    delete[]seq; //delete sequence from heap
}


ostream& operator<<(ostream& out,Protein& obj)
{
    out<<obj.seq<<endl;
    return out;
}


istream& operator>>(istream& inp,Protein& obj)
{

    inp>>obj.seq;
    return inp;

}

bool Protein::operator==(Protein& seq1)
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



bool Protein::operator!=(Protein& seq1)
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



Protein Protein::operator+(Protein & seq1)
{
    int length = strlen(seq1.seq);// the length of seq1
    int length1 = strlen(seq); // the length of seq
    Protein temp; // object from Protein to add concatenate any two sequences in it.
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



DNA* Protein::GetDNAStrandsEncodingMe(DNA & bigDNA)
{
    DNA * ret;  // pointer object from DNA.
    RNA obj(bigDNA.ConvertToRNA()); // convert DNA first to RNA.

    CodonsTable a; //object from CodonsTable.
    a.LoadCodonsFromFile("RNA_codon_table.txt"); //Load Codons FromFile
    Protein obj1(obj.ConvertToProtein(a)); // convert RNA to protein.

    int length= strlen(seq); // length of seq.
    int length1= strlen(obj1.seq); // length of obj1.seq.


    if (length1<length)
    {
        cout<<"u can't get the protein !!\n";
        return ret;
    }

    else if (length1==length)
    {

        for (int i=0; i<length; i++)
        {
            if (seq[i]!=obj1.seq[i])
            {
                cout<<"u can't get the protein !\n";
                return ret;
            }
        }
        ret = new DNA[1];
        ret[0] = bigDNA;
        return ret;

    }


    else if (length1 > length)
    {
        // save seq and obj1.seq ton strings
        string a, b;

        ret= new DNA [20];
        a = seq;
        b = obj1.seq;

        int c = 0;

        for (int i=0; i<length1; i+=length)
        {
            if (b.substr(i,i+a.size())==a)
            {
                int coo=0;
                ret[c].seq=new char[length*3];
                //      cout<<i*3<<"         "<<(i+length)*3<<endl;
                for (int counter=(i*3); counter<((i+length)*3); counter++)
                {
                    ret[c].seq[coo++]=bigDNA.seq[counter];
                }

                c++;
            }
        }
        return ret;
    }


}

// Exception handling to check if DNA strand is valid or no.
string Protein :: checkvalidity()
{
    string a = "";
    for (int i = 0; i < strlen(seq); i++)
    {
        if (strlen(seq) % 3!= 0)
        {
            a = "number of chars %3 !=0";
            throw a;
        }
        if (seq[i] == 'K'||
                seq[i] == 'N'||
                seq[i] == 'T'||
                seq[i] == 'R'||
                seq[i] == 'S'||
                seq[i] == 'I'||
                seq[i] == 'M'||
                seq[i] == 'Q'||
                seq[i] == 'H'||
                seq[i] == 'P'||
                seq[i] == 'L'||
                seq[i] == 'E'||
                seq[i] == 'D'||
                seq[i] == 'A'||
                seq[i] == 'G'||
                seq[i] == 'V'||
                seq[i] == 'Y'||
                seq[i] == 'C'||
                seq[i] == 'W'||
                seq[i] == 'F')
        {
            continue;
        }
        else
        {

            a += seq[i];

        }
    }

    if (a.length() == 0)
        throw "this is a valid protein";
    else
        throw a;
}



void Protein::Print()
{

    for (int i=0;i<strlen(seq);i++)
    {
        cout<<seq[i];
    }
    cout<<endl;

}

void Protein::Readfromfile()
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



void Protein::Printtofile()
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



