// Lists.aspx.h

#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System::Drawing;
using namespace System::Web;
using namespace System::Web::UI::WebControls;

namespace WebControl {

	public ref class Lists : public System::Web::UI::Page
	{
	protected:
        ListBox^      selListBox; 
        DataGrid^     dataGrid; 
        DropDownList^ colorList;

		void Page_Load(Object ^sender, EventArgs ^e);
	};
}
