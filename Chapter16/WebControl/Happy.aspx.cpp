// Happy.aspx.cpp : main project file.

#include "StdAfx.h"
#include "Happy.aspx.h"

namespace WebControl
{
    void Happy::Page_Load(Object ^sender, EventArgs ^e)
    {
        if (!IsPostBack)
        {
            //  Create a session object the first time Web Form is loaded
            Session["cSize"] = 32;
        }

        // Copy the session object to local variable for easy access
        int cSize = (int)Session["cSize"]; 

        if (cSize % 2 == 1) 
        {
            cSize -= 10; 
            if (cSize < 32) 
                cSize = 32; 
        }
        else 
        {
            cSize += 10; 
            if (cSize > 400) 
                cSize -= 1; 
        }
        imgHappy->Width = Unit::Pixel(cSize); 
        imgHappy->Height = Unit::Pixel(cSize); 

        // Update the session object for next post back
        Session["cSize"] = cSize; 
    }
}

