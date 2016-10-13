// ManyHeadings.aspx.cpp : main project file.

#include "StdAfx.h"
#include "ManyHeadings.aspx.h"

namespace WebControl 
{
    void ManyHeadings::Page_Load(Object ^sender, EventArgs ^e)
    {
        myPageHeader^ header; 

        header = (myPageHeader^)(LoadControl("myPageHeader.ascx")); 
        header->Level = "Home"; 
        cell00->Controls->Add(header); 

        header = (myPageHeader^)(LoadControl("myPageHeader.ascx")); 
        header->Level = "Domain"; 
        cell01->Controls->Add(header); 
    }
}

