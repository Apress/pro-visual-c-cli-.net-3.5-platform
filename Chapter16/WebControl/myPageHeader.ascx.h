// myPageHeader.ascx.h

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

namespace WebControl {

	namespace uc
	{
		public ref class myPageHeader abstract : public System::Web::UI::UserControl
		{
        public:
            property String^ Level;  // A trivial property

        protected:
            Image^ imgHeader; 

			void Page_Load(Object ^sender, EventArgs ^e);
		};
	}
}
