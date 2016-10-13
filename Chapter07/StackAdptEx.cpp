#include <cliext/stack>

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

    // equality operator.
    bool operator==(const Pet^ rhs)
    {
        return (Name->Equals(rhs->Name));
    }
};

int main(array<System::String ^> ^args)
{
    stack<Pet^> pets;

    pets.push(gcnew Pet("King"));
    pets.push(gcnew Pet("Zipper"));
    pets.push(gcnew Pet("Buster"));
    pets.push(gcnew Pet("Lady"));

    System::Console::WriteLine("Push pets onto stack and" +
                               " display by IEnumerator<> interface:");

    for each (Pet^ pet in pets.get_container())
        Console::Write("{0} ", pet->Name);

    System::Console::WriteLine("\n\nPop pets from stack top till empty:"); 

    while (!pets.empty())
    {
        Console::Write("{0} ", pets.top()->Name);
        pets.pop();
    }

    System::Console::WriteLine("\n\n"); 

    return 0;
}
