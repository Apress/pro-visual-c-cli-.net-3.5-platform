// Tables.aspx.h

#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Web::UI;
using namespace System::Web::UI::WebControls;
using namespace System::Web::UI::HtmlControls;

namespace WebControl {

	public ref class Tables : public System::Web::UI::Page
	{
	protected:
        Table^ FilesTable; 
		HtmlTitle^ PageTitle;

		void Page_Load(Object ^sender, EventArgs ^e);
		void btnHappy(Object ^sender, CommandEventArgs ^e);
	};
}
