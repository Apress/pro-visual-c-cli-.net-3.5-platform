#pragma once


namespace MaintAuthors_DGV {

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
		
			Adapter->Fill(AuthorsDS->Authors);
			
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
	private: AuthorDSLib::AuthorsDSTableAdapters::AuthorsTableAdapter ^Adapter;
	private: AuthorDSLib::AuthorsDS^  AuthorsDS;

	protected: 
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  authorIDDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  lastNameDataGridViewTextBoxColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  firstNameDataGridViewTextBoxColumn;
	private: System::Windows::Forms::BindingSource^  AuthorsBindingSource;

	private: System::Windows::Forms::Button^  bnCommit;
	private: System::Windows::Forms::Button^  bnRollback;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->AuthorsDS = (gcnew AuthorDSLib::AuthorsDS());
			this->Adapter = (gcnew AuthorDSLib::AuthorsDSTableAdapters::AuthorsTableAdapter());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->authorIDDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->firstNameDataGridViewTextBoxColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->AuthorsBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->bnCommit = (gcnew System::Windows::Forms::Button());
			this->bnRollback = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsDS))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsBindingSource))->BeginInit();
			this->SuspendLayout();
			// 
			// AuthorsDS
			// 
			this->AuthorsDS->DataSetName = L"AuthorsDS";
			this->AuthorsDS->SchemaSerializationMode = System::Data::SchemaSerializationMode::IncludeSchema;
			// 
			// Adapter
			// 
			this->Adapter->ClearBeforeFill = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoGenerateColumns = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->authorIDDataGridViewTextBoxColumn, 
				this->lastNameDataGridViewTextBoxColumn, this->firstNameDataGridViewTextBoxColumn});
			this->dataGridView1->DataSource = this->AuthorsBindingSource;
			this->dataGridView1->Location = System::Drawing::Point(13, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(428, 202);
			this->dataGridView1->TabIndex = 0;
			// 
			// authorIDDataGridViewTextBoxColumn
			// 
			this->authorIDDataGridViewTextBoxColumn->DataPropertyName = L"AuthorID";
			this->authorIDDataGridViewTextBoxColumn->HeaderText = L"AuthorID";
			this->authorIDDataGridViewTextBoxColumn->Name = L"authorIDDataGridViewTextBoxColumn";
			this->authorIDDataGridViewTextBoxColumn->ReadOnly = true;
			// 
			// lastNameDataGridViewTextBoxColumn
			// 
			this->lastNameDataGridViewTextBoxColumn->DataPropertyName = L"LastName";
			this->lastNameDataGridViewTextBoxColumn->HeaderText = L"LastName";
			this->lastNameDataGridViewTextBoxColumn->Name = L"lastNameDataGridViewTextBoxColumn";
			// 
			// firstNameDataGridViewTextBoxColumn
			// 
			this->firstNameDataGridViewTextBoxColumn->DataPropertyName = L"FirstName";
			this->firstNameDataGridViewTextBoxColumn->HeaderText = L"FirstName";
			this->firstNameDataGridViewTextBoxColumn->Name = L"firstNameDataGridViewTextBoxColumn";
			// 
			// AuthorsBindingSource
			// 
			this->AuthorsBindingSource->DataMember = L"Authors";
			this->AuthorsBindingSource->DataSource = this->AuthorsDS;
			// 
			// bnCommit
			// 
			this->bnCommit->Location = System::Drawing::Point(130, 222);
			this->bnCommit->Name = L"bnCommit";
			this->bnCommit->Size = System::Drawing::Size(75, 23);
			this->bnCommit->TabIndex = 1;
			this->bnCommit->Text = L"Commit";
			this->bnCommit->UseVisualStyleBackColor = true;
			this->bnCommit->Click += gcnew System::EventHandler(this, &Form1::bnCommit_Click);
			// 
			// bnRollback
			// 
			this->bnRollback->Location = System::Drawing::Point(230, 222);
			this->bnRollback->Name = L"bnRollback";
			this->bnRollback->Size = System::Drawing::Size(75, 23);
			this->bnRollback->TabIndex = 2;
			this->bnRollback->Text = L"Rollback";
			this->bnRollback->UseVisualStyleBackColor = true;
			this->bnRollback->Click += gcnew System::EventHandler(this, &Form1::bnRollback_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(453, 273);
			this->Controls->Add(this->bnRollback);
			this->Controls->Add(this->bnCommit);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsDS))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->AuthorsBindingSource))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void bnCommit_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				this->Adapter->Update(this->AuthorsDS->Authors);
				this->AuthorsDS->AcceptChanges();
			 }
private: System::Void bnRollback_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			this->AuthorsDS->RejectChanges();
		 }
};
}

