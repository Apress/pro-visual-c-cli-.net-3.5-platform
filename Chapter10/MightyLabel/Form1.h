#pragma once


namespace MightyLabel {

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
            labelSwitch = true;
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
        System::Windows::Forms::Label^  MightyLabel;
        bool labelSwitch;

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
			this->MightyLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// MightyLabel
			// 
			this->MightyLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->MightyLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->MightyLabel->Location = System::Drawing::Point(63, 91);
			this->MightyLabel->Name = L"MightyLabel";
			this->MightyLabel->Size = System::Drawing::Size(150, 35);
			this->MightyLabel->TabIndex = 1;
			this->MightyLabel->Text = L"This is the mighty label! It will change when you click it";
			this->MightyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->MightyLabel->Click += gcnew System::EventHandler(this, &Form1::MightyLabel_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->MightyLabel);
			this->Name = L"Form1";
			this->Text = L"The Mighty Label";
			this->Click += gcnew System::EventHandler(this, &Form1::MightyLabel_Click);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MightyLabel_Click(System::Object^  sender, System::EventArgs^  e) 
		{
            if (labelSwitch) 
                MightyLabel->Text = L"Ouchie!!!  That hurt."; 
            else 
                MightyLabel->Text = L"Ooo!!!  That tickled."; 
            labelSwitch = !labelSwitch; 
		}
	};
}