#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Configuration::Install;


namespace Simple {

	[RunInstaller(true)]

	/// <summary>
	/// Summary for ProjectInstaller
	/// </summary>
	public ref class ProjectInstaller : public System::Configuration::Install::Installer
	{
	public:
		ProjectInstaller(void)
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
		~ProjectInstaller()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ServiceProcess::ServiceProcessInstaller^  serviceProcessInstaller1;
	protected: 
	private: System::ServiceProcess::ServiceInstaller^  serviceInstaller1;
	private: System::Diagnostics::EventLogInstaller^  eventLogInstaller1;

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
			this->serviceProcessInstaller1 = (gcnew System::ServiceProcess::ServiceProcessInstaller());
			this->serviceInstaller1 = (gcnew System::ServiceProcess::ServiceInstaller());
			this->eventLogInstaller1 = (gcnew System::Diagnostics::EventLogInstaller());
			// 
			// serviceProcessInstaller1
			// 
			this->serviceProcessInstaller1->Account = System::ServiceProcess::ServiceAccount::LocalSystem;
			this->serviceProcessInstaller1->Password = nullptr;
			this->serviceProcessInstaller1->Username = nullptr;
			// 
			// serviceInstaller1
			// 
			this->serviceInstaller1->ServiceName = L"SimpleWinService";
			// 
			// eventLogInstaller1
			// 
			this->eventLogInstaller1->CategoryCount = 0;
			this->eventLogInstaller1->CategoryResourceFile = nullptr;
			this->eventLogInstaller1->Log = L"Application";
			this->eventLogInstaller1->MessageResourceFile = nullptr;
			this->eventLogInstaller1->ParameterResourceFile = nullptr;
			this->eventLogInstaller1->Source = L"SimpleWinService";
			// 
			// ProjectInstaller
			// 
			this->Installers->AddRange(gcnew cli::array< System::Configuration::Install::Installer^  >(3) {this->serviceProcessInstaller1, 
				this->serviceInstaller1, this->eventLogInstaller1});

		}
#pragma endregion
	};
}
