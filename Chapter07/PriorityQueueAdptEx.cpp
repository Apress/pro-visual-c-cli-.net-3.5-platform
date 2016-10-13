#include <cliext/queue>

using namespace System;
using namespace cliext;
using namespace System::Collections::Generic;

ref class Pet
{
public:
    String^ Name;

    // default public constructor.
    Pet() : Name(String::Empty) { }

    // Okay not needed but makes example easier. :)
    Pet(String^ name) : Name(name) { }

    // public copy constructor.
    Pet(const Pet% orig)
    {
        Name = orig.Name; 
    }

    // public assignment operator.
    Pet% operator=(const Pet% orig)
    {
        if (this != %orig)
            Name = orig.Name;
        return *this;
    }

    // public destructor.
    ~Pet() { }

    // comparison operator.
    bool operator<(const Pet^ rhs)
    {
        return (Name->CompareTo(rhs->Name) < 0);
    }

    // comparison operator.
    bool operator>(const Pet^ rhs)
    {
        return (Name->CompareTo(rhs->Name) > 0);
    }

    // equality operator.
    bool operator==(const Pet^ rhs)
    {
        return (Name->Equals(rhs->Name));
    }
};

int main(array<System::String ^> ^args)
{
    priority_queue<Pet^> petpq;

    petpq.push(gcnew Pet("King"));
    petpq.push(gcnew Pet("Zipper"));
    petpq.push(gcnew Pet("Buster"));
    petpq.push(gcnew Pet("Lady"));

    System::Console::WriteLine("Push pets onto priority queue and" +
                               " display by IEnumerator<> interface:");

    for each (Pet^ pet in petpq.get_container())
        Console::Write("{0} ", pet->Name);

    System::Console::WriteLine("\n\nPop pets from priority queue till empty:"); 

    while (!petpq.empty())
    {
        Console::Write("{0} ", petpq.top()->Name);
        petpq.pop();
    }

    Console::WriteLine("\n\nUse functor greater<Pet^>() as ordering rule");

    priority_queue<Pet^> petpqr = priority_queue<Pet^>(greater<Pet^>());

    petpqr.push(gcnew Pet("King"));
    petpqr.push(gcnew Pet("Zipper"));
    petpqr.push(gcnew Pet("Buster"));
    petpqr.push(gcnew Pet("Lady"));

    System::Console::WriteLine("And Pop pets from priority queue till empty:"); 

    while (!petpqr.empty())
    {
        Console::Write("{0} ", petpqr.top()->Name);
        petpqr.pop();
    }

    System::Console::WriteLine("\n\n"); 

    return 0;
}
