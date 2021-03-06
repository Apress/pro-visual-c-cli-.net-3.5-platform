#pragma once


namespace OptimizedHappyFace {

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

            Head  = Drawing::Rectangle(125, 25, 250, 250);
            Mouth = Drawing::Rectangle(200, 175, 100, 50);
            LEye  = Drawing::Rectangle(200, 100, 25, 25);
            REye  = Drawing::Rectangle(275, 100, 25, 25);

            b4pen = gcnew Pen(Color::Black, 4);
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

        System::Drawing::Rectangle Head;
        System::Drawing::Rectangle Mouth;
        System::Drawing::Rectangle LEye;
        System::Drawing::Rectangle REye;
        Pen^ b4pen;

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

            this->AutoScrollMinSize = System::Drawing::Size(400,400);

            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(292, 273);
            this->Name = L"Form1";
            this->Text = L"Optimized Happy Face";
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

            Drawing::Rectangle ClipRect = e->ClipRectangle;
            ClipRect.Offset(-AutoScrollPosition.X, -AutoScrollPosition.Y);

            g->TranslateTransform((float)AutoScrollPosition.X, 
                                  (float)AutoScrollPosition.Y);

            if (!(Rectangle::Intersect(ClipRect, Head)).IsEmpty)
            {
                g->FillEllipse(Brushes::Yellow, Head);
                g->DrawEllipse(b4pen, Head);

                if (!(Rectangle::Intersect(ClipRect, Mouth)).IsEmpty)
                {
                    g->FillPie(Brushes::White, Mouth, 0, 180);
                    g->DrawPie(b4pen, Mouth, 0, 180);
                }
                if (!(Rectangle::Intersect(ClipRect, LEye)).IsEmpty)
                {
                    g->FillEllipse(Brushes::White, LEye);
                    g->DrawEllipse(b4pen, LEye);
                }
                if (!(Rectangle::Intersect(ClipRect, REye)).IsEmpty)
                {
                    g->FillEllipse(Brushes::White, REye);
                    g->DrawEllipse(b4pen, REye);
                }
            }
        }
	};
}

