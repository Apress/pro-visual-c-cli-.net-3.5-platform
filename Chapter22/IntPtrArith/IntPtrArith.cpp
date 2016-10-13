using namespace System;

void main()
{
    array<int>^ primes = gcnew array<int> {1,2,3,5,7,11,13,17};

    interior_ptr<int> ip = &primes[0];        // Create the interior pointer

    int total = 0;
    while(ip != &primes[0] + primes->Length)  // Comparing pointers
    {
        total += *ip;
        ip++;                                // Add size of int to ip not 1
    }

    Console::WriteLine("Sum of the first 8 prime numbers is {0}", total);
}
