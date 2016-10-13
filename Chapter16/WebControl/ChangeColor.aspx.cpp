// ChangeColor.aspx.cpp : main project file.

#include "StdAfx.h"
#include "ChangeColor.aspx.h"


namespace WebControl 
{
    void ChangeColor::tbChanger_TextChanged(Object ^sender, EventArgs ^e)
    {
        array<Char>^ AComma = {','};

        // parse out the colors
        array<String^>^ incolors = tbChanger->Text->Split(AComma); 

        // change the foreground and background
        tbChanger->ForeColor = Color::FromName(incolors[0]); 
        if (incolors->Length > 1)
            tbChanger->BackColor = Color::FromName(incolors[1]); 
    }
}

