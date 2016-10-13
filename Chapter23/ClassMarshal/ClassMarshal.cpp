using namespace System;
using namespace System::Runtime::InteropServices;

[StructLayout(LayoutKind::Sequential)]
value class vRec
{
public:
    int width;
    int height;


    vRec(int iwidth, int iheight)
    {
        width = iwidth;
        height = iheight;
    }
};

[StructLayout(LayoutKind::Sequential)]
ref class rRec
{
public:
    int width;
    int height;

    rRec(int iwidth, int iheight)
    {
        width = iwidth;
        height = iheight;
    }
};

// By value
[DllImportAttribute("NativeCode.dll")]
extern "C" bool vIsSquare(vRec rec);

// by reference
[DllImportAttribute("NativeCode.dll")]
extern "C" bool rIsSquare(rRec^ rec);

void main()
{
    // By Value
    vRec vrec(2,3);
    Console::WriteLine("value class rec a square? {0}", vIsSquare(vrec));

    // By Reference
    rRec ^rrec = gcnew rRec(3,3);
    Console::WriteLine("ref class rec a square? {0}", rIsSquare(rrec));

    Console::WriteLine("\n\n");
}
