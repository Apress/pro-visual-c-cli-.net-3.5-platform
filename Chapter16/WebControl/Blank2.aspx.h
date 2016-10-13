// Blank2.aspx.h

#pragma once

#include "myPageHeader.ascx.h"

using namespace System;
using namespace System::Web::UI;

namespace WebControl {

	public ref class Blank2 : public System::Web::UI::Page
	{
	protected:
		::WebControl::uc::myPageHeader^ myPageHeader1;

		void Page_Load(Object ^sender, EventArgs ^e);
	};
}
