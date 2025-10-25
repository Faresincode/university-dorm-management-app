#pragma once

#include <iostream>
#include <vector> 
#include "clsString.h";
#include "clsInputValidate.h";
#include <fstream>

using namespace std;


class clsGlobalFunction
{


private:



public:

    static void AddPaymentRecordToFile(string  stDataLine, string FileName)
    {
        fstream MyFile;
        MyFile.open(FileName, ios::out | ios::app);
        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;
            MyFile.close();
        }
    }


};

