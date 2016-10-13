#pragma once


namespace CorrectingCoords {

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
            coords = gcnew ArrayList();  // Instantiate coords array
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
        ArrayList ^coords;

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
            this->Text = L"Click and see coords";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                          &Form1::Form1_Paint);
            this->MouseDown += 
                gcnew System::Windows::Forms::MouseEventHandler(this, 
                                                      &Form1::Form1_MouseDown);
            this->ResumeLayout(false);
		}
#pragma endregion

    private: 
        System::Void Form1_MouseDown(System::Object^ sender, 
                                     System::Windows::Forms::MouseEventArgs^ e)
        {
            coords->Add(Point(e->X, e->Y));
            Invalidate();
        }

    private: 
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            for each (Point^ p in coords)
            {
                 e->Graphics->DrawString(String::Format("({0},{1})",p->X,p->Y),
                    gcnew Drawing::Font("Courier New", 8),
                    Brushes::Black, (Single)p->X, (Single)p->Y);
            }
        }
	};
}

