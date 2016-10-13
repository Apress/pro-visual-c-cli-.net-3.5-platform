#include <cliext/list>

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

ref class MyGreaterThanFunctor
{
public:
    bool operator()(Pet^ a, Pet^ b)
    {
        return a > b;
    }
};

int main(array<System::String ^> ^args)
{
    list<Pet^> pets; 
    pets.push_front(gcnew Pet("King")); 
    pets.push_front(gcnew Pet("Buster"));
    pets.push_front(gcnew Pet("Caesar"));
    pets.push_front(gcnew Pet("Daisy"));

    // --------------------------------------------------------------------
    System::Console::WriteLine("\nfor loop -- Using iterator" + 
                               " with insert: "); 

    list<Pet^>::iterator pet_i = pets.begin();   
    pets.insert(++pet_i, gcnew Pet("Jack"));

    for(pet_i = pets.begin(); pet_i != pets.end(); pet_i++)
        System::Console::Write("{0} ", pet_i->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nfor each loop --" + 
                               " From typecast to ICollection<>" + 
                               " with Add() and sort():"); 

    ICollection<Pet^>^ genericIList = %pets;

    genericIList->Add(gcnew Pet("Queen"));

	pets.sort();

    for each (Pet^ pet in genericIList) 
        System::Console::Write("{0} ", pet->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nfor each loop --" +
                               " merging puppies with reverse sorted pets"
                               " display by built in IEnumerator<> interface:"); 
    list<Pet^> puppies; 

    puppies.push_front(gcnew Pet("Lady")); 
    puppies.push_front(gcnew Pet("Chalk"));

	pets.sort(gcnew MyGreaterThanFunctor());
	puppies.sort(greater<Pet^>());
    pets.merge(puppies, greater<Pet^>());

    for each (Pet^ pet in pets) 
        System::Console::Write("{0} ", pet->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nfor each loop --" +
                               " spliced a random pet"
                               " display by built in IEnumerator<> interface:"); 
    list<Pet^> RanPet; 

    list<Pet^>::iterator pet_ir = pets.begin();
    int randPetNo = (gcnew Random())->Next(pets.size());
    for (int i = 0; i < randPetNo; i++)
        pet_ir++;

    RanPet.splice(RanPet.begin(), pets, pet_ir);

    for each (Pet^ pet in pets) 
        System::Console::Write("{0} ", pet->Name); 
    Console::Write("<- Splice -> ");
    for each (Pet^ pet in RanPet) 
        System::Console::Write("{0} ", pet->Name); 

    System::Console::WriteLine("\n\n"); 

    return (0);
}
