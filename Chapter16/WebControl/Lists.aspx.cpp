// Lists.aspx.cpp : main project file.

#include "StdAfx.h"
#include "Lists.aspx.h"


namespace WebControl 
{
    void Lists::Page_Load(Object ^sender, EventArgs ^e)
    {
        OleDbConnection^ con;

        try 
        {

//			<connectionStrings>
//			    <add name="OLEDBConnection" 
//			         connectionString="Provider=SQLOLEDB.1;Persist Security Info=False; 
//			                           Integrated Security=SSPI;Data Source=localhost; 
//									   Initial Catalog=DCV_DB;" 
//                   providerName="SQLOLEDB"/>
//			</connectionStrings>

            con = gcnew OleDbConnection(
                ConfigurationManager::ConnectionStrings["OLEDBConnection"]->ConnectionString); 
            con->Open(); 

            if (!IsPostBack) 
            {
                // Set up database table list box
                array<Object^>^ restrict = {nullptr, nullptr, nullptr, "TABLE"};
                DataTable^ dt = 
                    con->GetOleDbSchemaTable(OleDbSchemaGuid::Tables, 
                                             restrict); 

                selListBox->DataSource = dt->DefaultView; 
                selListBox->DataTextField = "TABLE_NAME"; 
                selListBox->DataBind(); 

                // Set up Background color list box
                colorList->Items->Add("Yellow");
                colorList->Items->Add(gcnew ListItem("Green","LightGreen"));
                colorList->Items->Add("Red");
            }
            else
            {
                // Build data grid from selected database table
                String^ selectedTable = selListBox->SelectedItem->Value; 
                String^ Cmd = 
                    String::Concat("SELECT * FROM ", selectedTable);
                OleDbDataAdapter^ dAdapt = gcnew OleDbDataAdapter(Cmd, con); 
                DataSet^ dSet = gcnew DataSet(); 
                dAdapt->Fill(dSet); 

                dataGrid->DataSource = dSet; 
                dataGrid->DataBind(); 
//                dataGrid->BackColor = 
//                    Color::FromName(colorList->SelectedItem->Value);
                dataGrid->BackColor = 
                    Color::FromName(colorList->Items[colorList->SelectedIndex]->Value);

                // enable background color list box
                colorList->Enabled = true;
            }
        }
        catch(Exception^ exp) 
        {
            // Do Exception handling
            throw exp; 
        }
        finally
        {
            // Close down the database
            con->Close(); 
        }
    }
}

