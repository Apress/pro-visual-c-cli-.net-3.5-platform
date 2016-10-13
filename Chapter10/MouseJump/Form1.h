#pragma once


namespace MouseJump {

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
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(450, 300);
			this->Name = L"Form1";
			this->Text = L"Mouse Jump";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
            // Get mouse x and y coordinates
            int x = e->X;
            int y = e->Y;

            // Get Forms upper left location
            Point loc = DesktopLocation;

            // Handle left button mouse click
            if (e->Button == Windows::Forms::MouseButtons::Left)
            {
                Text = String::Format("Mouse Jump - Left Button at {0},{1}", 
                                       x, y);

                DesktopLocation = Drawing::Point(loc.X + x, loc.Y +y); 
            }
            // Handle right button mouse click
            else if (e->Button == Windows::Forms::MouseButtons::Right)
            {
                Text = String::Format("Mouse Jump - Right Button at {0},{1}", 
                                      x, y);

                DesktopLocation = Point((loc.X+1) - (ClientSize.Width - x), 
                                    (loc.Y+1) - (ClientSize.Height - y)); 
            }
            // Handle middle button mouse click
            else
            {
                Text = String::Format("Mouse Jump - Middle Button at {0},{1}",
                                        x, y);
                DesktopLocation = Point((loc.X+1) - ((ClientSize.Width/2) - x),
                                    (loc.Y+1) - ((ClientSize.Height/2) - y)); 
            }
		}
	};
}

