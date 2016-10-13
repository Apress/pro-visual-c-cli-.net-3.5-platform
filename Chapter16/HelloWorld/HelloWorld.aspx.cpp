// HelloWorld.aspx.cpp : main project file.

#include "stdafx.h"
#include "HelloWorld.aspx.h"

namespace HelloWorld {

    void _Default::Page_Load(Object ^sender, EventArgs ^e)
    {
		//
		// TODO: Add the implementation of your Web Page here
		//
		Response->Write (L"<h1>Hello World</h1>");
    }

}

