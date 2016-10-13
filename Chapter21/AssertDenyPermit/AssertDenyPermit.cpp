using namespace System;
using namespace System::IO;
using namespace System::Security;
using namespace System::Security::Permissions;

void AssertRead()
{
    CodeAccessPermission ^permission =
        gcnew FileIOPermission(FileIOPermissionAccess::Read, "C:\\Test");

    permission->Assert();
    StreamReader ^sr = File::OpenText("C:\\Test\\TestFile.txt");
    String ^s = sr->ReadLine();
    sr->Close();
    permission->RevertAssert();
    Console::WriteLine("Successful Read");
}

void NoAssertRead()
{
    StreamReader ^sr = File::OpenText("C:\\Test\\TestFile.txt");
    String ^s = sr->ReadLine();
    sr->Close();
    Console::WriteLine("Successful Read");
}

void main()
{
    // Deny Reading C:
    CodeAccessPermission ^permissionRead =
        gcnew FileIOPermission(FileIOPermissionAccess::Read, "C:\\Test");

    permissionRead->Deny();
    try
    {
        AssertRead();
        NoAssertRead();
    }
    catch(SecurityException^)
    {
        Console::WriteLine("Failed To Read");
    }
    permissionRead->RevertDeny();

    // Only allow Writing to C:
    CodeAccessPermission ^permissionWrite =
        gcnew FileIOPermission(FileIOPermissionAccess::Write, "C:\\Test");


    permissionWrite->PermitOnly();
    try
    {
        AssertRead();
        NoAssertRead();
    }
    catch(SecurityException^)
    {
        Console::WriteLine("Failed To Read");
    }
    permissionWrite->RevertPermitOnly();

	Console::WriteLine("");
}
