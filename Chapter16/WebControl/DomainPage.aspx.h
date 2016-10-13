// DomainPage.aspx.h

#pragma once

using namespace System;
using namespace System::Web;
using namespace System::Web::UI;
using namespace System::Web::UI::WebControls;

#include "myMaster.master.h"

namespace WebControl 
{
	public ref class DomainPage : public System::Web::UI::Page
	{
	protected:
		void Page_Load(Object ^sender, EventArgs ^e);
	};
}
