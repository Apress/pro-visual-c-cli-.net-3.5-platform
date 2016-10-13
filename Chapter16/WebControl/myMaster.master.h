// myMaster.master.h

#pragma once

#include "myPageHeader.ascx.h"

using namespace System;
using namespace System::Web::UI;

namespace WebControl 
{
    public ref class myMaster : public System::Web::UI::MasterPage
    {
    public:
        property String^ PageLevel
        {
            void set(String^ value);
        }

    protected:
        ::WebControl::uc::myPageHeader^ myPageHeader1;

        void Page_Load(Object ^sender, EventArgs ^e);
    };
}
