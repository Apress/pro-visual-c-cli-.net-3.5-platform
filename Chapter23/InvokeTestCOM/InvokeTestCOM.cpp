// #using <TestCom.dll>  // Add if you are not referencing using VS .NET

using namespace System;
using namespace TestCOM;

int main(array<System::String ^> ^args)
{
    CTestCOMClass^ test = gcnew CTestCOMClass();

    long ret = test->Square(4);

    Console::WriteLine("The Square of 4 is {0}", ret);

	try
	{
		long ret = test->Square(0x10000);
	}
	catch (Exception^ ex)
	{
		Console::WriteLine("Oops an exception occurred: {0}", ex->Message);
	}

    return 0;
}
