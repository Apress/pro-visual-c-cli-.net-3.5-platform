using namespace System;
using namespace System::Collections;

ref class myReverserClass: public IComparer
{
public:
   virtual int Compare(Object^ x, Object^ y) = IComparer::Compare
   {
       return (String::Compare((String^)y, (String^)x));
   }
};

void main()
{
    ArrayList ^alist = gcnew ArrayList(4); // will double to 8
    alist->Add("One");
    alist->Add("-");
    alist[1] = "Three";

    alist->Insert(1, "Two");

    array<String^>^ morenums = gcnew array<String^> {"Four", "Five"};

    alist->AddRange(morenums);

    alist->Reverse();

    Console::WriteLine("*** The ArrayList ***");
    for (int i = 0; i < alist->Count; i++)
    {
        Console::Write("{0} ", alist[i]);
    }

    Console::WriteLine("\n\nCapacity is: {0}", alist->Capacity.ToString());

    alist->Capacity = 10;
    Console::WriteLine("New capacity is: {0}", alist->Capacity.ToString());

    Console::WriteLine("Count is: {0}", alist->Count.ToString());

    IComparer^ myComparer = gcnew myReverserClass;
    alist->Sort(myComparer);
    
    int indx = alist->BinarySearch("Four", myComparer);
    Console::WriteLine("Four found at index: {0}", indx.ToString());

    bool fnd = alist->Contains("One");
    Console::WriteLine("ArrayList contains a 'One': {0}", fnd.ToString());

    Console::WriteLine();
}
