#pragma once


namespace MinuteTimer {

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
        System::Windows::Forms::ProgressBar^  progressBar;
        System::Windows::Forms::Label^  lbsecs;
        System::Windows::Forms::Timer^  timer;

        int seconds;

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
            this->components = (gcnew System::ComponentModel::Container());
            this->progressBar = (gcnew System::Windows::Forms::ProgressBar());
            this->lbsecs = (gcnew System::Windows::Forms::Label());
            this->timer = 
                (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();
            // 
            // progressBar
            // 
            this->progressBar->Location = System::Drawing::Point(61, 16);
            this->progressBar->Maximum = 60;
            this->progressBar->Name = L"progressBar";
            this->progressBar->Size = System::Drawing::Size(326, 23);
            this->progressBar->TabIndex = 3;
            // 
            // lbsecs
            // 
            this->lbsecs->AutoSize = true;
            this->lbsecs->Location = System::Drawing::Point(19, 25);
            this->lbsecs->Name = L"lbsecs";
            this->lbsecs->Size = System::Drawing::Size(13, 13);
            this->lbsecs->TabIndex = 2;
            this->lbsecs->Text = L"0";
            this->lbsecs->TextAlign = 
                System::Drawing::ContentAlignment::MiddleRight;
            // 
            // timer
            // 
            this->timer->Enabled = true;
            this->timer->Tick += 
                gcnew System::EventHandler(this, &Form1::timer_Tick);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(407, 55);
            this->Controls->Add(this->progressBar);
            this->Controls->Add(this->lbsecs);
            this->Name = L"Form1";
            this->Text = L"One minute timer";
            this->ResumeLayout(false);
            this->PerformLayout();
		}
#pragma endregion

    private: 
        System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e)
        {
            // Write current tick count (int 10th of second) to label
            seconds++; 
            seconds %= 600; 
            lbsecs->Text = String::Format("{0}.{1}", (seconds/10).ToString(),
                                                     (seconds%10).ToString());
            // Update ProgressBar
            progressBar->Value = seconds/10; 
        }
	};
}

