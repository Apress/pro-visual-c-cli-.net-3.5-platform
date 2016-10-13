#pragma once


namespace ArrayOfRadios {

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

            array<String^>^ rbText = gcnew array<String^> {
                L"Can", L"You", L"Click", L"More", L"Than", L"One"
            };
            radios = gcnew array<RadioButton^>(6); 
            label  = gcnew Label(); 

            for (int i = 0; i < radios->Length; i++)
            {
                int j = 50*i;
                radios[i] = gcnew RadioButton();
                radios[i]->BackColor = Color::FromArgb(255,j+5,j+5,j+5);
                radios[i]->ForeColor = Color::FromArgb(255,250-j,250-j,250-j);
                radios[i]->Location = Drawing::Point(90, 10+(40*i)); 
                radios[i]->TabIndex = i; 
                radios[i]->TabStop = true; 
                radios[i]->Text = rbText[i]; 
                radios[i]->CheckedChanged += 
                    gcnew EventHandler(this, &Form1::radioCheckedChanged);
            }
            Controls->AddRange(radios);

            label->Location = Drawing::Point(90, 10+(40*radios->Length)); 
            Controls->Add(label);
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
        array<RadioButton^>^ radios; 
        Label       ^label; 

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
            this->SuspendLayout();
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"An Array Of Radios";
            this->ResumeLayout(false);
		}
#pragma endregion

    private:
        void radioCheckedChanged(Object ^sender, EventArgs ^e)
        {
            RadioButton ^rb = (RadioButton^)sender;

            if (rb->Checked == true)
                label->Text = rb->Text; 
        }
	};
}

