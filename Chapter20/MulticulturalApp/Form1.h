#pragma once


namespace MulticulturalApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Threading;

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
			Thread::CurrentThread->CurrentCulture = gcnew CultureInfo("fr-fr");
			Thread::CurrentThread->CurrentUICulture = Thread::CurrentThread->CurrentCulture;
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
	private: System::Windows::Forms::Label^  lbHello;
	protected: 

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->lbHello = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbHello
			// 
			this->lbHello->AccessibleDescription = nullptr;
			this->lbHello->AccessibleName = nullptr;
			resources->ApplyResources(this->lbHello, L"lbHello");
			this->lbHello->BackColor = System::Drawing::SystemColors::Control;
			this->lbHello->Name = L"lbHello";
			// 
			// Form1
			// 
			this->AccessibleDescription = nullptr;
			this->AccessibleName = nullptr;
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = nullptr;
			this->Controls->Add(this->lbHello);
			this->Font = nullptr;
			this->Icon = nullptr;
			this->Name = L"Form1";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

