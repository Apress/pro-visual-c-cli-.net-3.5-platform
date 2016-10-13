using namespace System;
using namespace System::Runtime::InteropServices;

[DllImportAttribute("..\\Debug\\NativeCode.dll",
                    CallingConvention=CallingConvention::StdCall)]
extern "C" long square(long value);


[DllImport("User32.dll", CharSet=CharSet::Auto,
           CallingConvention=CallingConvention::StdCall)]
extern "C" int MessageBox(int hWnd, String^ text, String^ caption,
                          unsigned int type);

int main(array<System::String ^> ^args)
{
    long Squareof4 = square(4);

    Console::WriteLine(L"The square of 4 is {0}", Squareof4);

    MessageBox(0, L"Hello World!", L"A Message Box", 0);

    return 0;
}
