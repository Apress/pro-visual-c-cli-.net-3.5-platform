#include <msclr/lock.h>

using namespace System;
using namespace System::Collections;
using namespace System::Threading;
using namespace msclr;

ref class App
{
private:
    ArrayList^ myArray;

public:
    App() { myArray = gcnew ArrayList(); }

    void Thread1()
    {
        while (true)
        {
            try
            {
                lock l1 (myArray->SyncRoot, 500);
                Console::WriteLine(L"In Thread 1 Lock");
                Thread::Sleep(1000);
            }
            catch(...) 
            {
                Console::WriteLine(L"Failed to get sync in Thread 1");
            }
        }
    }

    void Thread2()
    {
        lock l2(myArray->SyncRoot, lock_later);
        while (true)
        {
            if (l2.try_acquire(500))
            {
                Console::WriteLine(L"In Thread 2 lock");
                Thread::Sleep(1000);
                l2.release();
            }
            else
            {
                Console::WriteLine(L"Failed to get sync in Thread 2");
            }
        }
    }
};

int main(array<System::String ^> ^args)
{
    App^ app = gcnew App();

    Thread ^th1 = gcnew Thread(gcnew ThreadStart(app, &App::Thread1));
    Thread ^th2 = gcnew Thread(gcnew ThreadStart(app, &App::Thread2));

    th1->IsBackground = true;
    th2->IsBackground = true;

    th1->Start();
    th2->Start();

    Console::ReadLine();
    return 0;
}
