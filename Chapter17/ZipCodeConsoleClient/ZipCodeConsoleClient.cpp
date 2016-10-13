#include "FindZipCode.h"

using namespace System;

void main()
{
    FindZipCode::FindZipCodeClass ^fzc = gcnew FindZipCode::FindZipCodeClass();

    try
    {
        Console::WriteLine(fzc->GetZip("Louisville", "KY").ToString());
        Console::WriteLine(fzc->GetZip("Irvine", "CA").ToString());
        Console::WriteLine(fzc->GetZip("xx", "cc").ToString());
    }

    catch (Exception ^e)
    {
        Console::WriteLine(e->Message);
    }
}
