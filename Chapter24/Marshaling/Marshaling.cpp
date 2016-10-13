#include "stdio.h"
#include "msclr\marshal.h"

using namespace System;
using namespace msclr::interop;

void main()
{
    String ^hstr = gcnew String("Marshaling String^ to wchar_t*");

	marshal_context^ context = gcnew marshal_context();
	const wchar_t* pstr = context->marshal_as<const wchar_t*>(hstr); 

    wprintf(L"%s\n", pstr);
	delete context;  // from here on pstr is invalid

	const char* message = "Marshaling const char* to String^";
	Console::WriteLine(marshal_as<String^>(message));
}

