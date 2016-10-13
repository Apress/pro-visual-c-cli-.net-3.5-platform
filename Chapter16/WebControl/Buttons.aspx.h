// Buttons.aspx.h

#pragma once

using namespace System;
using namespace System::Web::UI;
using namespace System::Web::UI::WebControls;

namespace WebControl 
{
	public ref class Buttons : public System::Web::UI::Page
	{
	protected:
        // Row 1 Column 1 -- Controls
        RadioButton^ rbColorful; 
        RadioButton^ rbHappy; 
        RadioButton^ rbChange; 

        // Row 1 Column 2 -- Controls
        CheckBox^    cbColorful; 
        CheckBox^    cbHappy; 
        CheckBox^    cbChange; 
        Button^      bnCheckBoxes; 

        // Row 2 Column 1 -- Controls
        Button^      bnColorful; 
        ImageButton^ ibnHappy; 
        Button^      bnChange; 

        // Row 2 Column 2 -- Control
        LinkButton^  lbnChange; 

		void RB_CheckedChanged(Object ^sender, EventArgs ^e);
		void bnCheckBoxes_Click(Object ^sender, EventArgs ^e);
		void bnColorful_Click(Object ^sender, EventArgs ^e);
		void ibnHappy_Click(Object ^sender, ImageClickEventArgs ^e);
		void bnChange_Click(Object ^sender, EventArgs ^e);
		void lbnChange_Click(Object ^sender, EventArgs ^e);
	};
}
