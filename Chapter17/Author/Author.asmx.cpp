// Author.asmx.cpp : main project file.

#include "stdafx.h"
#include "Author.asmx.h"

namespace Author {


	AuthorClass::AuthorClass()
	{
        this->sqlConnection = gcnew SqlConnection();

		this->sqlConnection->ConnectionString = 
			ConfigurationManager::ConnectionStrings["SQLConnection"]->ConnectionString;
	}

	AuthorClass::~AuthorClass()
	{
		//
		//TODO: Add the destructor code here
		//
	}
    
	DataSet^ AuthorClass::GetAuthors() 
	{
		SqlDataAdapter ^dAdapt;
		DataSet ^dSet;

		dAdapt = gcnew SqlDataAdapter();
		dAdapt->MissingSchemaAction = MissingSchemaAction::AddWithKey;
	    
		dAdapt->SelectCommand = 
			gcnew SqlCommand("SELECT AuthorID, LastName, FirstName FROM Authors", sqlConnection);
		dSet = gcnew DataSet();
		dAdapt->Fill(dSet, "Authors");

		return dSet;
	}

	void AuthorClass::UpdateAuthors(DataSet ^dSet) 
	{
		SqlDataAdapter ^dAdapt;

		dAdapt = gcnew SqlDataAdapter();
		dAdapt->MissingSchemaAction = MissingSchemaAction::AddWithKey;
	    
		dAdapt->InsertCommand = 
			gcnew SqlCommand("INSERT INTO Authors (LastName, FirstName) " 
							 "VALUES (@LastName, @FirstName)", 
							 sqlConnection);
		dAdapt->InsertCommand->Parameters->Add("@LastName", SqlDbType::VarChar, 
											   50, "LastName");
		dAdapt->InsertCommand->Parameters->Add("@FirstName", SqlDbType::VarChar, 
											   50, "FirstName");
	    
		dAdapt->UpdateCommand = 
			gcnew SqlCommand("UPDATE Authors SET LastName = @LastName," 
												"FirstName = @FirstName " 
							 "WHERE AuthorID = @AuthorID", 
							 sqlConnection);
		dAdapt->UpdateCommand->Parameters->Add("@LastName", SqlDbType::VarChar, 
											   50, "LastName");
		dAdapt->UpdateCommand->Parameters->Add("@FirstName", SqlDbType::VarChar, 
											   50, "FirstName");
		dAdapt->UpdateCommand->Parameters->Add("@AuthorID", SqlDbType::Int, 
											   4, "AuthorID");

		dAdapt->DeleteCommand = 
			gcnew SqlCommand("DELETE FROM Authors WHERE AuthorID = @AuthorID", 
							 sqlConnection);
		dAdapt->DeleteCommand->Parameters->Add("@AuthorID", SqlDbType::Int, 
											   4, "AuthorID");

		dAdapt->Update(dSet, "Authors");
	}

}
