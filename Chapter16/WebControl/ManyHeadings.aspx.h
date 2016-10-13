// ManyHeadings.aspx.h

#pragma once

#include "myPageHeader.ascx.h"

using namespace System;
using namespace System::Web;
using namespace System::Web::UI;
using namespace System::Web::UI::WebControls;

using namespace ::WebControl::uc;

namespace WebControl {

    public ref class ManyHeadings : public System::Web::UI::Page
    {
    protected:
        TableCell^ cell00; 
        TableCell^ cell01; 

        void Page_Load(Object ^sender, EventArgs ^e);
    };
}
