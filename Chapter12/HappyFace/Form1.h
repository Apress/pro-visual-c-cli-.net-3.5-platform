#pragma once


namespace HappyFace {

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
            this->ClientSize = System::Drawing::Size(300, 300);
            this->Name = L"Form1";
            this->Text = L"Happy Face";
            this->Paint += 
                gcnew System::Windows::Forms::PaintEventHandler(this, 
                                                         &Form1::Form1_Paint);
            this->ResumeLayout(false);
        }
#pragma endregion

    private: 
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            Pen^ b4pen = gcnew Pen(Color::Black, 4);

            // Head
            Rectangle rect = Drawing::Rectangle(25, 25, 250, 250);
            g->FillEllipse(Brushes::Yellow, rect);
            g->DrawEllipse(b4pen, rect);

            // Mouth
            g->FillPie(Brushes::White, 100, 175, 100, 50, 0, 180);
            g->DrawPie(b4pen, 100, 175, 100, 50, 0, 180);

            // Left Eye
            rect = Drawing::Rectangle(100, 100, 25, 25);
            g->FillEllipse(Brushes::White, rect);
            g->DrawEllipse(b4pen, rect);


            // Right Eye
            rect = Drawing::Rectangle(175, 100, 25, 25);
            g->FillEllipse(Brushes::White, rect);
            g->DrawEllipse(b4pen, rect);

            // Get rid of pen Created
            delete b4pen;
        }
	};
}

