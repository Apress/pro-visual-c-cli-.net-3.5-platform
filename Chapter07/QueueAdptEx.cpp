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

    // equality operator.
    bool operator==(const Pet^ rhs)
    {
        return (Name->Equals(rhs->Name));
    }
};

int main(array<System::String ^> ^args)
{
    queue<Pet^> petq;

    petq.push(gcnew Pet("King"));
    petq.push(gcnew Pet("Zipper"));
    petq.push(gcnew Pet("Buster"));
    petq.push(gcnew Pet("Lady"));

    queue<Pet^>::value_type lastpet = petq.back();
    System::Console::WriteLine("The last pet in queue is:\n{0}", lastpet->Name); 

    System::Console::WriteLine("\nPush pets onto queue and" +
                               " display by IEnumerator<> interface:");

    for each (Pet^ pet in petq.get_container())
        Console::Write("{0} ", pet->Name);

    System::Console::WriteLine("\n\nPop pets from queue front till empty:"); 

    while (!petq.empty())
    {
        Console::Write("{0} ", petq.front()->Name);
        petq.pop();
    }

    System::Console::WriteLine("\n\n"); 

    return 0;
}
