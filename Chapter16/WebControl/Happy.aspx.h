// Happy.aspx.h

#pragma once

using namespace System;
using namespace System::Web::UI::WebControls;

namespace WebControl 
{
    public ref class Happy : public System::Web::UI::Page
    {
    protected:
        Image^ imgHappy; 
        void Page_Load(Object ^sender, EventArgs ^e);
    };
}
