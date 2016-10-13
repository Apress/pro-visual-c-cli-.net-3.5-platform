// FindZipCode.asmx.h

#pragma once

using namespace System;
using namespace System::Web;
using namespace System::Web::Services;

namespace FindZipCode {

	[WebServiceBinding(ConformsTo=WsiProfiles::BasicProfile1_1,EmitConformanceClaims = true)]
	[WebService(Namespace="http://procppcli.net", Description = "Zip code retrieval service")]
    public ref class FindZipCodeClass : public System::Web::Services::WebService
    {
    public:
		/// <summary>
		/// Default Constructor
		/// </summary>
		FindZipCodeClass();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FindZipCodeClass();

	public:
       [WebMethod(Description = "Get the zip code from city and state")] 
       int GetZip(String ^city, String ^state);

        // TODO: Add the methods of your Web Service here
	};
}
