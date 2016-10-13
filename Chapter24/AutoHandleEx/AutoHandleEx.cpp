// AutoHandleEx.cpp : main project file.

#include <msclr\auto_handle.h>

using namespace System;
using namespace msclr;

ref class DeleteMe : public IDisposable
{
private:
    String^ Name;
public:
    DeleteMe(String^ name) : Name(name) 
    { 
        Console::WriteLine("Constructor - {0}", Name); 
    }

    ~DeleteMe() 
    { 
        Console::WriteLine("Destructor  - {0}", Name); 
        Name = nullptr;
    }
protected:
    !DeleteMe() 
    { 
        Console::WriteLine("Finalize    - {0}", Name);  
        Name = nullptr;
    }
};


int main(array<System::String ^> ^args)
{
    // Falling out of scope without delete
    {
        DeleteMe^ NonAuto = gcnew DeleteMe("Non Auto no finally");
    }

    // Falling out of scope with finally delete
    DeleteMe^ NonAutoWFinally;
    try
    {
        NonAutoWFinally = gcnew DeleteMe("Non Auto with finally");
    }
    finally
    {
        delete NonAutoWFinally;
    }

    // using auto_handle
    {
        auto_handle<DeleteMe> Auto = gcnew DeleteMe("Auto");
    }

    return 0;
}
