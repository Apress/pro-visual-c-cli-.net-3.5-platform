// DomainPage.aspx.cpp : main project file.

#include "StdAfx.h"
#include "DomainPage.aspx.h"

namespace WebControl 
{
    void DomainPage::Page_Load(Object ^sender, EventArgs ^e)
    {
		((::WebControl::myMaster^)this->Master)->PageLevel = "Domain";
    }
}

