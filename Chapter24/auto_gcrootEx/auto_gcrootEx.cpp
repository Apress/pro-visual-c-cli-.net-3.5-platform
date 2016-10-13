#include "stdio.h"
#include <msclr/auto_gcroot.h>

using namespace System;
using namespace msclr;

ref class MClass
{
public:
    int x;
  ~MClass() { Console::WriteLine("MClass disposed"); }
protected:
   !MClass() { Console::WriteLine("MClass finalized"); }
};

#pragma unmanaged

class UMClass
{
public:
    auto_gcroot<MClass^> mclass;
   ~UMClass() { printf("UMClass deleted\n"); }
};

#pragma managed

void main()
{
    UMClass *umc = new UMClass();
    umc->mclass = gcnew MClass();

    umc->mclass->x = 4;
    Console::WriteLine("Managed Print {0}", umc->mclass->x);
    printf("Unmanaged Print %d\n", umc->mclass->x);

    delete umc;
}
