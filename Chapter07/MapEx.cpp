#include <cliext/map>

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
    System::Console::WriteLine("* map Examples *"); 
    System::Console::WriteLine("****************");

    map<Pet^, double> pets; 
    Pet^ King = gcnew Pet("King");  // Use later in find method

    pets.insert(pets.end(), map<Pet^, double>::make_value(gcnew Pet("Zipper"), 3.0));
    pets.insert(map<Pet^, double>::make_value(King, 10.0)); 
    pets.insert(map<Pet^, double>::make_value(gcnew Pet("Buster"),9.0));

    // --------------------------------------------------------------------
    System::Console::WriteLine("\nInserting duplicate elements to map" + 
                               " display by for loop using reverse_iterator:"); 

//  pair<set<Pet^>::iterator, bool> success; /** Does not work **/
    map<Pet^, double>::pair_iter_bool success;

    success = pets.insert(map<Pet^, double>::make_value(gcnew Pet("New_Puppy"),0.1));
    Console::WriteLine("First Time {0} age {1} is added {2}", 
        success.first->first->Name, 
        success.first->second, 
        success.second ? "successfully" : "unsuccessfully");

    success = pets.insert(map<Pet^, double>::make_value(gcnew Pet("New_Puppy"),0.2));
    Console::WriteLine("Second Time {0} age {1} is added {2}", 
        success.first->first->Name, 
        success.first->second, 
        success.second ? "successfully" : "unsuccessfully");

    map<Pet^, double>::reverse_iterator pet_ri;
    for(pet_ri = pets.rbegin(); pet_ri != pets.rend(); pet_ri++)
        System::Console::Write("{0} [{1}]  ", pet_ri->first->Name, pet_ri->second); 


    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nInsert pets from .NET Dictionary<T>" + 
                               " display by IDictionary<> interface:"); 

    Dictionary<Pet^, double>^ morepets = gcnew Dictionary<Pet^, double>();
    morepets->Add(gcnew Pet("Daisy"), 5);
    morepets->Add(gcnew Pet("Lady"), 7);

    for each (KeyValuePair<Pet^, double> ^kvp in morepets)  //Yuck!!
        pets.insert(map<Pet^, double>::make_value(kvp->Key, kvp->Value));

    List<map<Pet^, double>::value_type>^ evenmorepets = gcnew List<map<Pet^, double>::value_type>();
    evenmorepets->Add(map<Pet^, double>::make_value(gcnew Pet("Toby"), 1));
    evenmorepets->Add(map<Pet^, double>::make_value(gcnew Pet("Spot"), 2));

    pets.insert(evenmorepets);

    IDictionary<Pet^, double>^ pets_IDict = %pets;

    for each (KeyValuePair<Pet^, double> ^kvp in pets_IDict)
        System::Console::Write("{0} [{1}]  ", kvp->Key->Name, kvp->Value);

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nInsert pets into copy map" + 
                               " less 2nd, last & 'Lady'" + 
                               " display by IEnumerator<> interface:"); 

    map<Pet^, double> copy;
    map<Pet^, double>::iterator pets_e = pets.end();
    copy.insert(pets.begin(), --pets_e);

    map<Pet^, double>::iterator pets_cb = copy.begin();
    copy.erase(++pets_cb);

    copy.erase(gcnew Pet("Lady"));

    for each (KeyValuePair<Pet^, double> ^kvp in (IDictionary<Pet^, double>^)%copy)
        System::Console::Write("{0} [{1}]  ", kvp->Key->Name, kvp->Value);

    // --------------------------------------------------------------------
    Console::WriteLine("\n\nFound = {0}", copy.find(King)->first->Name);

    map<Pet^, double>::iterator Lady = copy.find(gcnew Pet("Lady"));
    Console::WriteLine("Did {0}Find = Lady", (Lady == copy.end()) ? "not " : "");


    // ********************************************************************
    System::Console::WriteLine("\n*********************");
    System::Console::WriteLine("* multimap Examples *"); 
    System::Console::WriteLine("*********************");

    multimap<Pet^, double> mpets; 
    mpets.insert(multimap<Pet^, double>::make_value(gcnew Pet("King"), 10.0)); 
    mpets.insert(multimap<Pet^, double>::make_value(gcnew Pet("Buster"), 9.0));
    mpets.insert(mpets.end(), 
                 multimap<Pet^, double>::make_value(gcnew Pet("Zipper"), 3.0));

    // --------------------------------------------------------------------
    System::Console::WriteLine("\nInsert elements (with duplicate) to multiset" + 
                               " display by IEnumerator<> interface:"); 

    mpets.insert(multimap<Pet^, double>::make_value(gcnew Pet("New_Puppy"), 0.1));
    
    multimap<Pet^, double>::iterator New_Puppy =     
    mpets.insert(multimap<Pet^, double>::make_value(gcnew Pet("New_Puppy"), 0.2));

    for each (KeyValuePair<Pet^, double> ^kvp in morepets)  //Yuck!!
        mpets.insert(multimap<Pet^, double>::make_value(kvp->Key, kvp->Value));

    mpets.insert(evenmorepets);

    for each (multimap<Pet^, double>::value_type pet in mpets)
        System::Console::Write("{0} [{1}]  ", pet->first->Name, pet->second);

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nUpper/Lower bound of duplicate multimap" + 
                               " display by for loop:"); 

    multimap<Pet^, double>::iterator pupsL = mpets.lower_bound(New_Puppy->first);
    multimap<Pet^, double>::iterator pupsU = mpets.upper_bound(New_Puppy->first);

    for(; pupsL != pupsU; pupsL++)
        System::Console::Write("{0} [{1}]  ", pupsL->first->Name, pupsL->second); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nequal_range of duplicate multimap" + 
                               " display by for loop:"); 

    multimap<Pet^, double>::pair_iter_iter FindSE = 
        mpets.equal_range(New_Puppy->first); 

    for (; FindSE.first != FindSE.second; ++FindSE.first) 
        System::Console::Write("{0} [{1}]  ", FindSE.first->first->Name, 
                                              FindSE.first->second); 

    // --------------------------------------------------------------------
    System::Console::WriteLine("\n\nequal_range of non-duplicate multiset" + 
                               " display by for loop:"); 

    FindSE = mpets.equal_range(King); 

    for (; FindSE.first != FindSE.second; ++FindSE.first) 
        System::Console::Write("{0} [{1}]  ", FindSE.first->first->Name, 
                                              FindSE.first->second); 

    // --------------------------------------------------------------------
    int count = mpets.erase(New_Puppy->first);
    System::Console::WriteLine("\n\nErasing {0} New Puppies from container", count);

    System::Console::WriteLine("\n\n"); 

    return (0);
}

