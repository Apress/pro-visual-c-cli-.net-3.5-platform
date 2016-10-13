#pragma once


namespace ToolStripEx {

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
        System::Windows::Forms::Label^  lbOutput;
		System::Windows::Forms::ToolStrip^  toolStrip;
        System::Windows::Forms::ToolStripButton^  tsbnHappy;
        System::Windows::Forms::ToolStripButton^  tsbnSad;
        System::Windows::Forms::ToolStripContainer^  toolStripContainer1;
		System::Windows::Forms::ToolStripSeparator^  Sep1;
		System::Windows::Forms::ToolStripLabel^  Label;
		System::Windows::Forms::ToolStripTextBox^  tstbName;

        System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lbOutput = (gcnew System::Windows::Forms::Label());
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->tsbnHappy = (gcnew System::Windows::Forms::ToolStripButton());
			this->tsbnSad = (gcnew System::Windows::Forms::ToolStripButton());
			this->Sep1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->Label = (gcnew System::Windows::Forms::ToolStripLabel());
			this->tstbName = (gcnew System::Windows::Forms::ToolStripTextBox());
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->TopToolStripPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->toolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbOutput
			// 
			this->lbOutput->AutoSize = true;
			this->lbOutput->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbOutput->Location = System::Drawing::Point(47, 42);
			this->lbOutput->Name = L"lbOutput";
			this->lbOutput->Size = System::Drawing::Size(208, 13);
			this->lbOutput->TabIndex = 7;
			this->lbOutput->Text = L"Enter a name then click an emotion";
			// 
			// toolStripContainer1
			// 
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->lbOutput);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(300, 104);
			this->toolStripContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(300, 129);
			this->toolStripContainer1->TabIndex = 8;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			// 
			// toolStripContainer1.TopToolStripPanel
			// 
			this->toolStripContainer1->TopToolStripPanel->Controls->Add(this->toolStrip);
			// 
			// toolStrip
			// 
			this->toolStrip->Dock = System::Windows::Forms::DockStyle::None;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->tsbnHappy, this->tsbnSad, 
				this->Sep1, this->Label, this->tstbName});
            this->toolStrip->Location = System::Drawing::Point(0, 0);
            this->toolStrip->Name = L"toolStrip";
            this->toolStrip->Size = System::Drawing::Size(300, 25);
            this->toolStrip->Stretch = true;
            this->toolStrip->TabIndex = 6;
            this->toolStrip->Text = L"toolStrip1";
			// 
			// tsbnHappy
			// 
			this->tsbnHappy->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsbnHappy.Image")));
			this->tsbnHappy->Name = L"tsbnHappy";
			this->tsbnHappy->Size = System::Drawing::Size(58, 22);
			this->tsbnHappy->Text = L"Happy";
			this->tsbnHappy->ToolTipText = L"a happy camper";
			this->tsbnHappy->Click += gcnew System::EventHandler(this, &Form1::tsbn_Click);
			// 
			// tsbnSad
			// 
			this->tsbnSad->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tsbnSad.Image")));
			this->tsbnSad->Name = L"tsbnSad";
			this->tsbnSad->Size = System::Drawing::Size(46, 22);
			this->tsbnSad->Text = L"Sad";
			this->tsbnSad->ToolTipText = L"major gloomy";
			this->tsbnSad->Click += gcnew System::EventHandler(this, &Form1::tsbn_Click);
			// 
			// Sep1
			// 
			this->Sep1->Name = L"Sep1";
			this->Sep1->Size = System::Drawing::Size(6, 25);
			// 
			// Label
			// 
			this->Label->Name = L"Label";
			this->Label->Size = System::Drawing::Size(35, 22);
			this->Label->Text = L"Name";
			// 
			// tstbName
			// 
			this->tstbName->Name = L"tstbName";
			this->tstbName->Size = System::Drawing::Size(92, 25);
			this->tstbName->Text = L"Computer";
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->ClientSize = System::Drawing::Size(300, 129);
			this->Controls->Add(this->toolStripContainer1);
			this->Name = L"Form1";
			this->Text = L"Emotional Tool Strip";
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->ContentPanel->PerformLayout();
			this->toolStripContainer1->TopToolStripPanel->ResumeLayout(false);
			this->toolStripContainer1->TopToolStripPanel->PerformLayout();
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

    private:
        System::Void tsbn_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->lbOutput->Text = String::Format("{0} is {1}!",
                 tstbName->Text, ((ToolStripButton^)sender)->ToolTipText);
        }
	};
}

