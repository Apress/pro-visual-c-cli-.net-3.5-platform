// HomePage.aspx.cpp : main project file.

#include "StdAfx.h"
#include "HomePage.aspx.h"

namespace WebControl 
{
    void HomePage::Page_Load(Object ^sender, EventArgs ^e)
    {
        ((::WebControl::myMaster^)this->Master)->PageLevel = "Home";
    }
}

