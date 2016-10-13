#include <cliext/vector>
#include <cliext/functional>
#include <cliext/algorithm>

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

bool BeforeCaesar(Pet^ value)
{
    Pet^ Caesar = gcnew Pet("Caesar");
    return value > Caesar;  // Note sorted in decending order 
}

int main(array<System::String ^> ^args)
{
    vector<Pet^> pets; 
    pets.push_back(gcnew Pet("King")); 
    pets.push_back(gcnew Pet("Buster"));
    pets.push_back(gcnew Pet("Caesar"));
    pets.push_back(gcnew Pet("Daisy"));

    Console::Write("initial -- vector:\n   ");
    for each (Pet^ pet in pets) 
        Console::Write("{0} ", pet->Name);

    Console::Write("\n\nreverse(F,L):\n   ");
    reverse(pets.begin(), pets.end());
    for each (Pet^ pet in pets) 
        Console::Write("{0} ", pet->Name);

    Console::Write("\n\nsort(F,L):\n   ");
    sort(pets.begin(), pets.end());
    for each (Pet^ pet in pets) 
        Console::Write("{0} ", pet->Name);

    Console::Write("\n\nrandom_shuffle(F,L):\n   ");
    random_shuffle(pets.begin(), pets.end());
    for each (Pet^ pet in pets) 
        Console::Write("{0} ", pet->Name);

    Console::Write("\n\nsort(F,L, functor):\n   ");
    sort(pets.begin(), pets.end(), greater<Pet^>());
    for each (Pet^ pet in pets) 
        Console::Write("{0} ", pet->Name);

    Console::Write("\n\nmax_element(F,L):\n   ");
    vector<Pet^>::iterator maxPet = max_element(pets.begin(), pets.end());
    Console::Write("{0}", maxPet->Name);

    Console::Write("\n\nbinary_search(F,L, v, functor):\n   ");
    Console::Write("Caesar was {0}.", 
        binary_search(pets.begin(), pets.end(), 
                      gcnew Pet("Caesar"), greater<Pet^>()) 
                          ? "found" : "not found");

    Console::Write("\n\ncount_if(F,L, BeforeCaesar()) is:\n   ");
    Console::Write(count_if(pets.begin(), pets.end(), BeforeCaesar).ToString());

    System::Console::WriteLine("\n\n");

    return 0;
}
