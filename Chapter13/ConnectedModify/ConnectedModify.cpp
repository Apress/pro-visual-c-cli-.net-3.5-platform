using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Configuration;

void main()
{
    String ^Name = "Doors";

    SqlConnection ^connection = gcnew SqlConnection();

    connection->ConnectionString = 
    ConfigurationManager::ConnectionStrings["SQLConnection"]->ConnectionString;

    try
    {
       SqlCommand ^cmd = gcnew SqlCommand();
       cmd->Connection = connection;
       connection->Open();

       cmd->CommandType = CommandType::StoredProcedure;
       cmd->CommandText = "InsertAuthor";

      cmd->Parameters->Add(gcnew SqlParameter("@LastName", SqlDbType::VarChar));
      cmd->Parameters->Add(gcnew SqlParameter("@FirstName",SqlDbType::VarChar));

       cmd->Parameters["@LastName"]->Value  = "Dope";
       cmd->Parameters["@FirstName"]->Value = "John";

       int affected = cmd->ExecuteNonQuery();
       Console::WriteLine("Insert - {0} rows are affected", affected);

       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "UPDATE Authors SET LastName = 'Doe'"
                          "WHERE LastName = 'Dope'";

       affected = cmd->ExecuteNonQuery();
       Console::WriteLine("Update - {0} rows are affected", affected);

       cmd->CommandType = CommandType::Text;
       cmd->CommandText = "DELETE FROM Authors WHERE LastName = 'Doe'";

       affected = cmd->ExecuteNonQuery();
       Console::WriteLine("Delete - {0} rows are affected", affected);
    }
    catch (SqlException ^e)
    {
        Console::WriteLine("No connection the following error occurred: {0}",
            e->Message);
    }
    finally
    {
        connection->Close();
    }
}
