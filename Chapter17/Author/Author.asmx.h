// Author.asmx.h

#pragma once

using namespace System;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Web;
using namespace System::Web::Services;

namespace Author {

	[WebServiceBinding(ConformsTo=WsiProfiles::BasicProfile1_1,EmitConformanceClaims = true)]
	[WebService(Namespace="TODO: Enter Unique URL", Description = "TODO: Enter Description")]
    public ref class AuthorClass : public System::Web::Services::WebService
    {
	private: 
		SqlConnection^  sqlConnection;

	public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		AuthorClass();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AuthorClass();

	public:
        [WebMethod(Description = "Method to retrieve All Authors from the database")]
        DataSet ^GetAuthors(); 

        [WebMethod(Description = "Method to Commit changed made on client with Server database")]
        void UpdateAuthors(DataSet ^dSet);
	};
}
