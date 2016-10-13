//#define UseSafeBool

#include <msclr/safebool.h>

using namespace System;
using namespace msclr;

ref class myClass
{
private: 
    bool IsInitialized;

public: 
    myClass()
    {
        IsInitialized = false;
    }

    void Initialize()
    {
        IsInitialized = true;
    }

#ifdef UseSafeBool

    // Check to see if this class has been initialized
    operator _detail_class::_safe_bool()
    {
        return IsInitialized ? _detail_class::_safe_true 
                             : _detail_class::_safe_false;
    }
#else

    operator bool() 
    {
        return IsInitialized; 
    }
#endif
};


void main()
{
    myClass^ mc = gcnew myClass();

#ifndef UseSafeBool // works without _safe_bool
    int i = (mc + 2) << 1;
    double d = mc * 3.2;  
    Console::WriteLine("b=[{0}] d=[{1}]", i.ToString(), d.ToString());
#endif

    if (mc)
        Console::WriteLine("Is Initialized");
    else
        Console::WriteLine("Is Not Initialized");

    mc->Initialize();

    Console::WriteLine(mc ? "Is Initialized" : "Is Not Initialized");

#ifndef UseSafeBool // works without _safe_bool
    i = (mc + 2) << 1;
    d = mc * 3.2;  
    Console::WriteLine("b=[{0}] d=[{1}]\n\n\n", i.ToString(), d.ToString());
#endif
}
