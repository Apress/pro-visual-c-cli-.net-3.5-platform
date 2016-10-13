using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

[DllImport("msvcrt", CharSet=CharSet::Ansi)]
extern "C" int strcpy([MarshalAs(UnmanagedType::LPStr)] StringBuilder^ dest,
                      [MarshalAs(UnmanagedType::LPStr)] String^ source);

void main()
{
    StringBuilder^ dest = gcnew StringBuilder();
    String^ source = "Hello";

    strcpy(dest, source);
    Console::WriteLine(dest);
}
