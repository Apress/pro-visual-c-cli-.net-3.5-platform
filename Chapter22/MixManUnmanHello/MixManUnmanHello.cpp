#include "stdio.h"
#include <msclr\all.h>

using namespace System;

void main()
{
    String ^hstr = "Hello World!";

    pin_ptr<const wchar_t> pstr = PtrToStringChars(hstr);

    wprintf(pstr);
}
