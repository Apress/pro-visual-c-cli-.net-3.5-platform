// Buttons.aspx.cpp : main project file.

#include "StdAfx.h"
#include "Buttons.aspx.h"

namespace WebControl 
{
    void Buttons::RB_CheckedChanged(Object ^sender, EventArgs ^e)
    {
        if (rbColorful->Checked) 
            Response->Redirect("Colorful.aspx"); 
        else if (rbHappy->Checked) 
            Response->Redirect("Happy.aspx"); 
        else if (rbChange->Checked) 
            Response->Redirect("ChangeColor.aspx"); 
    }

    void Buttons::bnCheckBoxes_Click(Object ^sender, EventArgs ^e)
    {
        if (cbColorful->Checked) 
            Response->Redirect("Colorful.aspx"); 
        else if (cbHappy->Checked) 
            Response->Redirect("Happy.aspx"); 
        else if (cbChange->Checked) 
            Response->Redirect("ChangeColor.aspx"); 
    }

    void Buttons::bnColorful_Click(Object ^sender, EventArgs ^e)
    {
        Response->Redirect("Colorful.aspx"); 
    }

    void Buttons::ibnHappy_Click(Object ^sender, ImageClickEventArgs ^e)
    {
        Response->Redirect("Happy.aspx"); 
    }

    void Buttons::bnChange_Click(Object ^sender, EventArgs ^e)
    {
        Response->Redirect("ChangeColor.aspx"); 
    }

    void Buttons::lbnChange_Click(Object ^sender, EventArgs ^e)
    {
        Response->Redirect("ChangeColor.aspx"); 
    }
}

