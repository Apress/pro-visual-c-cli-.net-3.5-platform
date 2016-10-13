#include "TestCOM.h"
#include <msclr/com/ptr.h>

#import "TestCOM.dll" raw_interfaces_only

using namespace System;
using namespace msclr;

ref class rcTestCOM
{
private:
    com::ptr<ITestCOM> test;
public:
    rcTestCOM()
    {
//		test.CreateInstance(L"CTestCOM.CTestCOM");
// or
        test.CreateInstance(__uuidof(CTestCOM));
    }

    long Square(int val)
    {
        long ret;
        HRESULT hr = test->Square(val, &ret);
        return ret;
    }
};

int main(array<System::String ^> ^args)
{
    rcTestCOM^ test = gcnew rcTestCOM();

    long ret = test->Square(4);

    Console::WriteLine("The Square of 4 is {0}", ret);

    Console::WriteLine("\n\n\n");

    return 0;
}

