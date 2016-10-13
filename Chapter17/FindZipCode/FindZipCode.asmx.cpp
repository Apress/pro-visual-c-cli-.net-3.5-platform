// FindZipCode.asmx.cpp : main project file.

#include "stdafx.h"
#include "FindZipCode.asmx.h"

namespace FindZipCode {


	FindZipCodeClass::FindZipCodeClass()
	{
		//
		//TODO: Add the constructor code here
		//
	}

	FindZipCodeClass::~FindZipCodeClass()
	{
		//
		//TODO: Add the destructor code here
		//
	}
    
    int FindZipCodeClass::GetZip(String ^city, String ^state)
    {
        // Obviously very simplified 
        if (city->Equals("Louisville") && state->Equals("KY"))
            return 40241;
        else if (city->Equals("Irvine") && state->Equals("CA"))
            return 92612;
        else
            throw gcnew Exception("Zip Code not found");
    }

}
