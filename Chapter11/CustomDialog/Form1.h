#pragma once

#include "MyDialog.h"

namespace CustomDialog {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
        System::Windows::Forms::Label^  lbRetString;
        System::Windows::Forms::Label^  lbRetVal;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->lbRetString = (gcnew System::Windows::Forms::Label());
            this->lbRetVal = (gcnew System::Windows::Forms::Label());
            this->SuspendLayout();
            //
            // lbRetString
            //
            this->lbRetString->Location = System::Drawing::Point(34, 119);
            this->lbRetString->Name = L"lbRetString";
            this->lbRetString->Size = System::Drawing::Size(225, 19);
            this->lbRetString->TabIndex = 3;
            //
            // lbRetVal
            //
            this->lbRetVal->Location = System::Drawing::Point(34, 77);
            this->lbRetVal->Name = L"lbRetVal";
            this->lbRetVal->Size = System::Drawing::Size(225, 19);
            this->lbRetVal->TabIndex = 2;
            //
            // Form1
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Controls->Add(this->lbRetString);
            this->Controls->Add(this->lbRetVal);
            this->Name = L"Form1";
            this->Text = L"Click Form to get dialog";
            this->Click +=
                gcnew System::EventHandler(this, &Form1::Form1_Click);
            this->ResumeLayout(false);
		}
#pragma endregion

    private:
        System::Void Form1_Click(System::Object^ sender, System::EventArgs^ e)
        {
            MyDialog ^mydialog = gcnew MyDialog();
            mydialog->PassedValue = "This has been passed from Form1";

            if (mydialog->ShowDialog() ==
                System::Windows::Forms::DialogResult::OK)
                lbRetVal->Text = "OK";
            else if (mydialog->DialogResult ==
                System::Windows::Forms::DialogResult::Abort)
                lbRetVal->Text = "Abort";
            else
                lbRetVal->Text = "Cancel";

            lbRetString->Text = mydialog->PassedValue;
        }
	};
}

