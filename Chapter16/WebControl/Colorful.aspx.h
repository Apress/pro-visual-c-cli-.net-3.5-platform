// Colorful.aspx.h

#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Web::UI::WebControls;

namespace WebControl 
{
	public ref class Colorful : public System::Web::UI::Page
	{
	protected:
		Label^ Label;
		void Page_Load(Object ^sender, EventArgs ^e);
	};
}
