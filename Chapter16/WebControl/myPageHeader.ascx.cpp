// myPageHeader.aspx.cpp : main project file.

#include "StdAfx.h"
#include "myPageHeader.ascx.h"


namespace WebControl {

	namespace uc
	{
		void myPageHeader::Page_Load(Object ^sender, EventArgs ^e)
		{
            // Set the image based on passed header level
            imgHeader->ImageUrl = String::Concat("Images/", Level, ".jpg"); 
		}
	}
}

