#include <cliext/set>

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
    System::Console::WriteLine("****************");
    System::Console::WriteLine("* set Examples *"); 
    System::Console::WriteLine("****************");

    set<Pet^> pets; 
    Pet^ King = gcnew Pet("King");  // Use later in find method

    pets.insert(pets.end(), gcnew Pet("Zipper"));
    pets.insert(King); 
    pets.insert(gcnew Pet("Buster"));

    // --------------------------------------------------------------------
    System::Console::WriteLine("\nInserting duplicate elements to set" + 
                               " display by for loop using reverse_iterator:"); 

//  pair<set<Pet^>::iterator, bool> success; /** Does not work **/
    set<Pet^>::pair_iter_bool success;

    success = pets.insert(gcnew Pet("New_Puppy"));
    Console::WriteLine("First Time {0} is added {1}", success.first->Name, 
        success.second ? "successfully" : "unsuccessfully");

    success = pets.insert(gcnew Pet("New_Puppy"));
    Console::WriteLine("Second Time {0} is added {1}", success.first->Name,
        success.second ? "successfully" : "unsuccessfully");

    set<Pet^>::reverse_iterator pet_ri;
    for(pet_ri = pets.rbegin(); pet_ri != pets.rend(); pet_ri++)
        System::Console::Write("{0} ", pet_ri->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nInsert pets from .NET generic List<T>" + 
                               " display by IEnumerator<> interface:"); 

    List<Pet^>^ morepets = gcnew List<Pet^>();
    morepets->Add(gcnew Pet("Daisy"));
    morepets->Add(gcnew Pet("Lady"));
    pets.insert(morepets);

    for each (Pet^ pet in pets) 
        System::Console::Write("{0} ", pet->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nInsert pets into copy set" + 
                               " less 2nd, last & 'Lady'" + 
                               " display by IEnumerator<> interface:"); 

    set<Pet^> copy;
    set<Pet^>::iterator pets_e = pets.end();
    copy.insert(pets.begin(), --pets_e);

    set<Pet^>::iterator pets_cb = copy.begin();
    copy.erase(++pets_cb);

    copy.erase(gcnew Pet("Lady"));

    for each (Pet^ pet in copy) 
        System::Console::Write("{0} ", pet->Name); 

    // --------------------------------------------------------------------
    Console::WriteLine("\n\nFound = {0}", copy.find(King)->Name);

    set<Pet^>::iterator Lady = copy.find(gcnew Pet("Lady"));
    Console::WriteLine("Did {0}Find = Lady", (Lady == copy.end()) ? "not " : "");

    // ********************************************************************
    System::Console::WriteLine("\n*********************");
    System::Console::WriteLine("* multiset Examples *"); 
    System::Console::WriteLine("*********************");

    multiset<Pet^> mpets; 
    mpets.insert(gcnew Pet("King")); 
    mpets.insert(gcnew Pet("Buster"));
    mpets.insert(mpets.end(), gcnew Pet("Zipper"));

    // --------------------------------------------------------------------
    System::Console::WriteLine("\nInsert elements (with duplicate) to multiset" + 
                               " display by IEnumerator<> interface:"); 

    mpets.insert(gcnew Pet("New_Puppy"));
    multiset<Pet^>::iterator New_Puppy = mpets.insert(gcnew Pet("New_Puppy"));

    mpets.insert(morepets);  // generic List<Pet^> from above

    for each (Pet^ pet in mpets) 
        System::Console::Write("{0} ", pet->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nUpper/Lower bound of duplicate multiset" + 
                               " display by for loop:"); 

    multiset<Pet^>::iterator puppiesL = mpets.lower_bound(*New_Puppy);
    multiset<Pet^>::iterator puppiesU = mpets.upper_bound(*New_Puppy);

    for(; puppiesL != puppiesU; puppiesL++)
        System::Console::Write("{0} ", puppiesL->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nequal_range of duplicate multiset" + 
                               " display by for loop:"); 

    multiset<Pet^>::pair_iter_iter FindSE = mpets.equal_range(*New_Puppy); 

    for (; FindSE.first != FindSE.second; ++FindSE.first) 
        System::Console::Write("{0} ", FindSE.first->Name); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nequal_range of non-duplicate multiset" + 
                               " display by for loop:"); 

    FindSE = mpets.equal_range(King); 

    for (; FindSE.first != FindSE.second; ++FindSE.first) 
        System::Console::Write("{0} ", FindSE.first->Name); 

    // --------------------------------------------------------------------
	int count = mpets.erase(*New_Puppy);
    System::Console::WriteLine("\n\nErasing {0} New Puppies from container", count);

    System::Console::WriteLine("\n\n"); 

    return (0);
}
