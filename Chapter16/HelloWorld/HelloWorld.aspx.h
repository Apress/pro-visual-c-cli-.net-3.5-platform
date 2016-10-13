// HelloWorld.aspx.h

#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Configuration;
using namespace System::Data;
using namespace System::Web;
using namespace System::Web::Security;
using namespace System::Web::UI;
using namespace System::Web::UI::HtmlControls;
using namespace System::Web::UI::WebControls;
using namespace System::Web::UI::WebControls::WebParts;
using namespace System::Xml;

namespace HelloWorld {

	public ref class _Default : public System::Web::UI::Page
	{
	protected:
		void Page_Load(Object ^sender, EventArgs ^e);
	};
}
