// myMaster.master.cpp : main project file.

#include "StdAfx.h"
#include "myMaster.master.h"

namespace WebControl 
{
	void myMaster::PageLevel::set(String^ value)
	{
		myPageHeader1->Level = value;
	}

    void myMaster::Page_Load(Object ^sender, EventArgs ^e)
    {
    }
}

