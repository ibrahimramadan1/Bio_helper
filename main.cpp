// Program: Bio_helper
// Purpose: using inheritance, polymorphism, templates, and exception handling among other OOP concepts in C++.
// Author:  Ibrahim Ramadan 
// Date:    13 Dec.  2018
// Version: 1.0


#include <iostream>
#include "sequence.h"
#include "dna.h"
#include "rna.h"
#include "protein.h"
#include "codonstable.h"
#include <fstream>
#include <string>
using namespace std;


int main()
{

    int choice,choice1;
    DNA obj;
    RNA obj1;
    Protein obj2;
    cout<<"Aloha there ! \n";
    while (2+1==3){

    cout<<"what's your input! \n"
        <<"1- DNA input \n"
        <<"2- RNA input \n"
        <<"3- Protein input \n"
        <<"4- Exit \n"
        <<"your choice: ";
        cin>>choice;
        if (choice==1)
        {
            backtoDNA:

            cout<<"1-input DNA \n2-Read from file\n"
            <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter DNA strand: ";
                cin>>obj;
            }
            else if (choice1==2)
            {
                obj.Readfromfile();
            }
            else {

                cout<<"invalid input !\n";
                goto backtoDNA;
            }


            cout<<"what function u wanna do ? \n"<<
            "1-convert to RNA \n"<<
            "2-check validity and output will be bad chars \n"<<
            "3- build ComplementaryStrand \n"<<
            "4- print \n"<<
            "5-print to file \n"<<
            "6-check if your DNA = another DNA \n"<<
            "7-check if your DNA != another DNA \n"<<
            "8-your DNA + another DNA \n"<<
            "your choice : ";

            cin>>choice1;

            if (choice1==1)
            {
                obj1=obj.ConvertToRNA();
                cout<<"the RNA strand = "<<obj1<<endl;
            }

            else if (choice1==2)
            {
                try {
                obj.checkvalidity();
                }
                catch (string a)
                {
                    cout<<a;
                }
            }
            else if (choice1==3)
            {
                obj.BuildComplementaryStrand();
                cout<<"complementary strand: ";
                obj.complementary_strand->Print();
            }
            else if (choice1 == 4)
            {
                cout<<"the DNA strand : "<<obj<<endl;
            }
            else if (choice1==5)
            {
                obj.Printtofile();
                cout<<"file printed ! \n";
            }
            else if (choice1==6)
            {
                DNA obj3;
                cout<<"Enter the other DNA: ";
                cin>>obj3;
                if (obj==obj3)
                    cout<<"your DNA = the other DNA \n";
            }


            else if (choice1==7)
            {
                DNA obj3;
                cout<<"Enter the other DNA: ";
                cin>>obj3;
                if (obj!=obj3)
                    cout<<"your DNA != the other DNA \n";
            }


            else if (choice1==8)
            {
                DNA obj3;
                cout<<"Enter the other DNA: ";
                cin>>obj3;

                DNA obj4(obj+obj3);
                    cout<<"your DNA + another DNA = "<<obj4<<endl;
            }

        }

        else if (choice==2)
        {

            backtoRNA:

            cout<<"1-input RNA \n2-Read from file\n"
            <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter DNA strand: ";
                cin>>obj1;
            }
            else if (choice1==2)
            {
                obj1.Readfromfile();
            }
            else {

                cout<<"invalid input !\n";
                goto backtoRNA;
            }


            cout<<"what function u wanna do ? \n"<<
            "1-convert to DNA \n"<<
            "2-convert to protein \n"<<
            "3- check validity and output will be bad chars  \n"<<
            "4- print \n"<<
            "5-print to file \n"<<
            "6-check if your RNA = another RNA \n"<<
            "7-check if your RNA != another RNA \n"<<
            "8-your RNA + another RNA \n"
            << "your choice : ";
            cin>>choice1;

            if (choice1==1)
            {
                obj=obj1.ConvertToDNA();
                cout<<"the DNA strand = "<<obj<<endl;
            }
             else if (choice1==2)
            {
                CodonsTable a;
                a.LoadCodonsFromFile("RNA_codon_table.txt");
                obj2=obj1.ConvertToProtein(a);
                cout<<"the protein strand : "<<obj2<<endl;

             }


            else if (choice1==3)
            {
                try {
                obj1.checkvalidity();
                }
                catch (string a)
                {
                    cout<<a;
                }
            }
            else if (choice1 == 4)
            {
                cout<<"the RNA strand : "<<obj1<<endl;
            }
            else if (choice1==5)
            {
                obj1.Printtofile();
                cout<<"file printed ! \n";
            }
            else if (choice1==6)
            {
                RNA obj3;
                cout<<"Enter the other RNA: ";
                cin>>obj3;
                if (obj1==obj3)
                    cout<<"your RNA = the other RNA \n";
            }


            else if (choice1==7)
            {
                RNA obj3;
                cout<<"Enter the other RNA: ";
                cin>>obj3;
                if (obj1!=obj3)
                    cout<<"your RNA != the other RNA \n";
            }


            else if (choice1==8)
            {
                RNA obj3;
                cout<<"Enter the other DNA: ";
                cin>>obj3;

                RNA obj4(obj1+obj3);
                    cout<<"your RNA + another RNA = "<<obj4<<endl;
            }






        }


        else if (choice==3)
        {

            backtoprotein:

            cout<<"1-input protein \n2-Read from file\n"
            <<"Enter choice:  ";
            cin>>choice1;

            if (choice1==1)
            {
                cout<<"Enter protein strand: ";
                cin>>obj2;
            }
            else if (choice1==2)
            {
                obj2.Readfromfile();
            }
            else {

                cout<<"invalid input !\n";
                goto backtoprotein;
            }

            cout<<"what function u wanna do ? \n"<<
            "1- check validity and output will be bad chars  \n"<<
            "2 print \n"<<
            "3-print to file \n"<<
            "4-check if your protein = another protein \n"<<
            "5-check if your protein != another protein \n"<<
            "6-your protein + another protein \n"<<
            "7- GetDNAStrandsEncodingMe(DNA & bigDNA) \n"<<
             "your choice : ";
            cin>>choice1;


             if (choice1==1)
            {
                try {
                obj2.checkvalidity();
                }
                catch (string a)
                {
                    cout<<a;
                }
            }
            else if (choice1 == 2)
            {
                cout<<"the protein strand : "<<obj2<<endl;
            }
            else if (choice1==3)
            {
                obj2.Printtofile();
                cout<<"file printed ! \n";
            }
            else if (choice1==4)
            {
                Protein obj3;
                cout<<"Enter the other RNA: ";
                cin>>obj3;
                if (obj2==obj3)
                    cout<<"your protein = the other protein \n";
            }


            else if (choice1==5)
            {
                Protein obj3;
                cout<<"Enter the other RNA: ";
                cin>>obj3;
                if (obj2!=obj3)
                    cout<<"your protein != the other protein \n";
            }


            else if (choice1==6)
            {
                Protein obj3;
                cout<<"Enter the other DNA: ";
                cin>>obj3;

                Protein obj4(obj2+obj3);
                    cout<<"your protein + another protein = "<<obj4<<endl;
            }

            else if (choice1==7)
            {

                DNA objj;
                cout<<"enter the bigdna : ";
                cin>>objj;
                obj2.GetDNAStrandsEncodingMe(objj);

            }










        }

        else
            break;

    }
    return 0;
}
