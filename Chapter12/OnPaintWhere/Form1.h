#pragma once


namespace OnPaintWhere {

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
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Form1";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                           &Form1::Form1_Paint);
            this->ResumeLayout(false);
		}
#pragma endregion

    protected:
        virtual void OnPaint(System::Windows::Forms::PaintEventArgs ^e) override
        {
//          Form::OnPaint(e);

            e->Graphics->DrawString("Hello GDI+", 
               gcnew Drawing::Font("Arial", 16), Brushes::Black, 75.0, 110.0);

            Form::OnPaint(e);
        }

    private: 
        System::Void Form1_Paint(System::Object^ sender,
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->DrawString("Hello GDI+", 
                gcnew Drawing::Font("Arial", 16), Brushes::Purple, 75.0, 110.0);
        }
	};
}

