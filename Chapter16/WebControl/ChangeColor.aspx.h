// ChangeColor.aspx.h

#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Web::UI::WebControls;

namespace WebControl 
{
    public ref class ChangeColor : public System::Web::UI::Page
    {
    protected:
        TextBox^ tbChanger; 
        void tbChanger_TextChanged(Object ^sender, EventArgs ^e);
    };
}
