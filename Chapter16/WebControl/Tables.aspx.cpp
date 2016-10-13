// Tables.aspx.cpp : main project file.

#include "StdAfx.h"
#include "Tables.aspx.h"

namespace WebControl 
{
    void Tables::Page_Load(Object ^sender, EventArgs ^e)
    {
        LiteralControl^ lit; 
        TableCell^      cell; 

        array<String^>^ files = Directory::GetFiles(Server->MapPath(".")); 

        for (int i = 0; i < files->Length; i++) 
        {
            FileInfo^ finfo = gcnew FileInfo(files[i]); 

            if (!finfo->Exists) 
                continue; 

            // Create a TableRow (Step 2)
            TableRow^ row = gcnew TableRow(); 

            // Create a TableCell (Step 3)
            cell = gcnew TableCell(); 

            // Create a Web Form control (Step 4)
            // Creating a hyperlink control
            HyperLink^ link = gcnew HyperLink(); 
            link->Text = finfo->Name; 
            link->NavigateUrl = finfo->Name;

            // Place the control in the TableCell (Step 5)
            cell->Controls->Add(link); 

            // Place the TableCell in the TableRow (Step 6)
            row->Cells->Add(cell); 

            // Repeat steps 3 through 6 (Step 7)
            // Creating a literal control
            lit = gcnew LiteralControl( 
                String::Concat(finfo->CreationTime.ToShortDateString(), 
                               " ", 
                               finfo->CreationTime.ToLongTimeString())); 
            cell = gcnew TableCell(); 
            cell->Controls->Add(lit); 
            row->Cells->Add(cell); 

            lit = gcnew LiteralControl(finfo->Length.ToString()); 
            cell = gcnew TableCell(); 
            cell->Controls->Add(lit); 
            row->Cells->Add(cell); 

            lit = gcnew LiteralControl(finfo->Attributes.ToString()); 
            cell = gcnew TableCell(); 
            cell->Controls->Add(lit); 
            row->Cells->Add(cell); 

            // Creating an image button control
            ImageButton^ ibn = gcnew ImageButton(); 
            ibn->Command += gcnew CommandEventHandler(this, &Tables::btnHappy); 
            ibn->ImageUrl = "Images/Happy.gif"; 
            ibn->CommandArgument = finfo->Name; 
            cell = gcnew TableCell(); 
            cell->HorizontalAlign = HorizontalAlign::Center; 
            cell->Controls->Add(ibn); 
            row->Cells->Add(cell); 

            // Place Row in Table (Step 8)
            FilesTable->Rows->Add(row); 

        // Repeat steps 2 through 8 (Step 9)
        } 
    }

    void Tables::btnHappy(Object ^sender, CommandEventArgs ^e)
    {
        PageTitle->Text = "The file " + e->CommandArgument + " is now happy";
    }
}

