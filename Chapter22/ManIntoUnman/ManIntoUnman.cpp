#include "stdio.h"

using namespace System;
using namespace System::Runtime::InteropServices;

ref class MClass
{
public:
    int x;
    ~MClass() { Console::WriteLine("MClass disposed"); }
protected:
    !MClass() { Console::WriteLine("MClass finalized\n\n\n"); }
};

#pragma unmanaged  // works with or without this line

class UMClass
{
public:
    void* mclass;

    ~UMClass() { printf("UMClass deleted\n"); }
};

#pragma managed

void main()
{
    UMClass *umc = new UMClass();

    // Place ref class on unmanaged void* pointer
    umc->mclass = GCHandle::ToIntPtr(GCHandle::Alloc(gcnew MClass())).ToPointer();

    // access int variable x by typecasting void*
	((MClass^)GCHandle::FromIntPtr(System::IntPtr(umc->mclass)).Target)->x = 4;

    // Manage print int variable x
    Console::WriteLine("Managed Print {0}", 
      ((MClass^)(GCHandle::FromIntPtr(System::IntPtr(umc->mclass))).Target)->x);

    // Unmanage print int variable x 
    printf("Unmanaged Print %d\n", 
	  ((MClass^)(GCHandle::FromIntPtr(System::IntPtr(umc->mclass))).Target)->x);

    delete umc;
}
