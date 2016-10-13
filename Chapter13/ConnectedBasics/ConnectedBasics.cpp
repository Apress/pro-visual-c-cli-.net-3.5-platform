using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

void main()
{
    SqlConnection^ connection = gcnew SqlConnection();

	connection->ConnectionString = 
	ConfigurationManager::ConnectionStrings["SQLConnection"]->ConnectionString;

	try
    {
        connection->Open();
        Console::WriteLine("We got a connection!");
    }
    catch (SqlException ^e)
    {
        Console::WriteLine("No connection the following error occurred: {0}",
            e->Message);
    }
    finally
    {
        connection->Close();
        Console::WriteLine("The connection to the database has been closed");
    }
}
