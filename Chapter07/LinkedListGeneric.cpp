#using <system.dll>

using namespace System;
using namespace System::Collections::Generic;

int main()
{
    array<String^>^ arrList = gcnew array<String^> {"Two", "Three", "Four"};

    LinkedList<String^>^ list = gcnew LinkedList<String^>((IEnumerable<String^>^)arrList);

    list->AddLast("Six");
    list->AddFirst("Zero");
    list->AddAfter(list->First, "One");
    list->AddBefore(list->Last, "5");

    Console::WriteLine("Write with error");

    LinkedListNode<String^>^ current = list->Last;
    while (current != nullptr)
    {
        Console::WriteLine(current->Value);
        current = current->Previous;
    }

    Console::WriteLine("\nNumber of elements = {0}", list->Count);

    LinkedListNode<String^>^ node = list->Find("5");

    list->AddBefore(node, "Five");
    list->Remove(node);

    list->RemoveFirst();

    Console::WriteLine("\nWrite with corrections");
    for each (String^ str in list)
        Console::WriteLine(str);

    Console::WriteLine("\nNumber of elements = {0}", list->Count);

    Console::WriteLine();

//  list->Add(4);    // Compile time error
}