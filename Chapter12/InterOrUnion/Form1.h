#pragma once


namespace InterOrUnion {

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

            // Build the rectangles from points and size
            Drawing::Point point1 = Drawing::Point(25,25);
            Drawing::Point point2 = Drawing::Point(100,100);
            Drawing::Size size    = Drawing::Size(200, 150);
            rect1  = Drawing::Rectangle(point1, size); 
            rect2  = Drawing::Rectangle(point2, size);
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

        // intersecting and unions rectangles
        Drawing::Rectangle rect1;
        Drawing::Rectangle rect2;

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
            this->ClientSize = System::Drawing::Size(330, 300);
            this->Name = L"Form1";
            this->Text = L"Click in Window";
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
        System::Void Form1_Paint(System::Object^ sender, 
                                 System::Windows::Forms::PaintEventArgs^ e)
        {
            // Draw a couple of rectangles
            e->Graphics->DrawRectangle(Pens::Black, rect1);
            e->Graphics->DrawRectangle(Pens::Black, rect2);
       }


    private: 
        System::Void Form1_MouseDown(System::Object^ sender, 
                                     System::Windows::Forms::MouseEventArgs^ e)
        {
            // build a point from x,y coords of mouse click
            Point p = Point(e->X, e->Y);

            // did we click in the intersection?
            if (Rectangle::Intersect(rect1, rect2).Contains(p))
                Text = "Intersection and Union";
            // did we click in the union?
            else if (Rectangle::Union(rect1, rect2).Contains(p))
                Text = "Union";
            // did we miss altogether
            else
                Text = "Outside of Both";
        }
	};
}

