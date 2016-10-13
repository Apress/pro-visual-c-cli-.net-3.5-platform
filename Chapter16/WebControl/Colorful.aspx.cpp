// Colorful.aspx.cpp : main project file.

#include "StdAfx.h"
#include "Colorful.aspx.h"

namespace WebControl 
{
    void Colorful::Page_Load(Object ^sender, EventArgs ^e)
    {
        Random^ r = gcnew Random(); 
        Label->ForeColor = 
            Color::FromArgb(r->Next(255),r->Next(255),r->Next(255)); 
        Label->BackColor = 
            Color::FromArgb(r->Next(255),r->Next(255),r->Next(255)); 
        Label->Text = 
            "Let's randomly change <b>colors</b> until you get sick "
            "of watching it";
        Label->Font->Italic = true;
    }
}

