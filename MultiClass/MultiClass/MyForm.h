#pragma once
#include <math.h>
namespace MultiClass {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	public:
		Pen^ pen;
		int sinif_sayi = 1, secilen_sinif = 1, *renk, ornek_sayi = 0, bias = 1, c = 1, lamda = 1;
		double *ornekler, *ws, *normalized, hata_payi;
		bool cizildi = false, ogrenildi = false;
	private: System::Windows::Forms::CheckBox^  NormalizeCheck;
	private: System::Windows::Forms::NumericUpDown^  HataPayiNumeric;

	private: System::Windows::Forms::Label^  Hatapayilabel;
	private: System::Windows::Forms::TrackBar^  ZoomTrack;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  ZoomLabel;
	private: System::Windows::Forms::ErrorProvider^  errorProvider1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  perceptionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  discreteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  continuousToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  SinifLabel;
	private: System::Windows::Forms::Label^  OrnekLabel;
	private: System::Windows::Forms::NumericUpDown^  SinifSayiNumeric;
	private: System::Windows::Forms::NumericUpDown^  OrneksecNumeric;


	private: System::Windows::Forms::Label^  iterationlabel;
	private: System::Windows::Forms::Button^  RandomButton;

	private: System::Windows::Forms::Button^  ClearButton;
	private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->perceptionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->discreteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->HataPayiNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->Hatapayilabel = (gcnew System::Windows::Forms::Label());
			this->SinifLabel = (gcnew System::Windows::Forms::Label());
			this->OrnekLabel = (gcnew System::Windows::Forms::Label());
			this->SinifSayiNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->OrneksecNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->iterationlabel = (gcnew System::Windows::Forms::Label());
			this->RandomButton = (gcnew System::Windows::Forms::Button());
			this->ClearButton = (gcnew System::Windows::Forms::Button());
			this->NormalizeCheck = (gcnew System::Windows::Forms::CheckBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->ZoomTrack = (gcnew System::Windows::Forms::TrackBar());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ZoomLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HataPayiNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SinifSayiNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrneksecNumeric))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomTrack))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::DimGray;
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Cross;
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(400, 400);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(669, 25);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// menuToolStripMenuItem
			// 
			this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->perceptionToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->menuToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			this->menuToolStripMenuItem->Size = System::Drawing::Size(52, 21);
			this->menuToolStripMenuItem->Text = L"Menü";
			// 
			// perceptionToolStripMenuItem
			// 
			this->perceptionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->discreteToolStripMenuItem,
					this->continuousToolStripMenuItem
			});
			this->perceptionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->perceptionToolStripMenuItem->Name = L"perceptionToolStripMenuItem";
			this->perceptionToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->perceptionToolStripMenuItem->Text = L"Öðrenme Metotlarý";
			// 
			// discreteToolStripMenuItem
			// 
			this->discreteToolStripMenuItem->Name = L"discreteToolStripMenuItem";
			this->discreteToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->discreteToolStripMenuItem->Text = L"Ayrýk";
			this->discreteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::discreteToolStripMenuItem_Click);
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->continuousToolStripMenuItem->Text = L"Sürekli";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, System::Drawing::FontStyle::Italic,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"Çýkýþ";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				67.2956F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				32.7044F)));
			this->tableLayoutPanel1->Controls->Add(this->HataPayiNumeric, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->Hatapayilabel, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->SinifLabel, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->OrnekLabel, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->SinifSayiNumeric, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->OrneksecNumeric, 1, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(440, 37);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(206, 75);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// HataPayiNumeric
			// 
			this->HataPayiNumeric->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HataPayiNumeric->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HataPayiNumeric->DecimalPlaces = 2;
			this->HataPayiNumeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->HataPayiNumeric->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->HataPayiNumeric->Location = System::Drawing::Point(147, 51);
			this->HataPayiNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->HataPayiNumeric->Name = L"HataPayiNumeric";
			this->HataPayiNumeric->Size = System::Drawing::Size(50, 20);
			this->HataPayiNumeric->TabIndex = 9;
			this->HataPayiNumeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->HataPayiNumeric->ValueChanged += gcnew System::EventHandler(this, &MyForm::HataPayiNumeric_ValueChanged);
			// 
			// Hatapayilabel
			// 
			this->Hatapayilabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Hatapayilabel->AutoSize = true;
			this->Hatapayilabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Hatapayilabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->Hatapayilabel->Location = System::Drawing::Point(31, 53);
			this->Hatapayilabel->Name = L"Hatapayilabel";
			this->Hatapayilabel->Size = System::Drawing::Size(76, 17);
			this->Hatapayilabel->TabIndex = 10;
			this->Hatapayilabel->Text = L"Hata Payý:";
			// 
			// SinifLabel
			// 
			this->SinifLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SinifLabel->AutoSize = true;
			this->SinifLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SinifLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->SinifLabel->Location = System::Drawing::Point(25, 3);
			this->SinifLabel->Name = L"SinifLabel";
			this->SinifLabel->Size = System::Drawing::Size(87, 17);
			this->SinifLabel->TabIndex = 0;
			this->SinifLabel->Text = L"Sýnýf Sayýsý:";
			// 
			// OrnekLabel
			// 
			this->OrnekLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrnekLabel->AutoSize = true;
			this->OrnekLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OrnekLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->OrnekLabel->Location = System::Drawing::Point(22, 27);
			this->OrnekLabel->Name = L"OrnekLabel";
			this->OrnekLabel->Size = System::Drawing::Size(93, 17);
			this->OrnekLabel->TabIndex = 1;
			this->OrnekLabel->Text = L"Örnek Sýnýfý:";
			this->OrnekLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// SinifSayiNumeric
			// 
			this->SinifSayiNumeric->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->SinifSayiNumeric->Cursor = System::Windows::Forms::Cursors::Hand;
			this->SinifSayiNumeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->SinifSayiNumeric->ForeColor = System::Drawing::Color::MidnightBlue;
			this->SinifSayiNumeric->Location = System::Drawing::Point(147, 3);
			this->SinifSayiNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->SinifSayiNumeric->Name = L"SinifSayiNumeric";
			this->SinifSayiNumeric->Size = System::Drawing::Size(50, 20);
			this->SinifSayiNumeric->TabIndex = 2;
			this->SinifSayiNumeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->SinifSayiNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->SinifSayiNumeric->ValueChanged += gcnew System::EventHandler(this, &MyForm::SinifSayiNumeric_ValueChanged);
			// 
			// OrneksecNumeric
			// 
			this->OrneksecNumeric->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OrneksecNumeric->Cursor = System::Windows::Forms::Cursors::Hand;
			this->OrneksecNumeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->OrneksecNumeric->ForeColor = System::Drawing::Color::MidnightBlue;
			this->OrneksecNumeric->Location = System::Drawing::Point(147, 27);
			this->OrneksecNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->OrneksecNumeric->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->OrneksecNumeric->Name = L"OrneksecNumeric";
			this->OrneksecNumeric->Size = System::Drawing::Size(50, 20);
			this->OrneksecNumeric->TabIndex = 3;
			this->OrneksecNumeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->OrneksecNumeric->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->OrneksecNumeric->ValueChanged += gcnew System::EventHandler(this, &MyForm::OrneksecNumeric_ValueChanged);
			// 
			// iterationlabel
			// 
			this->iterationlabel->AutoSize = true;
			this->iterationlabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->iterationlabel->Location = System::Drawing::Point(437, 359);
			this->iterationlabel->Name = L"iterationlabel";
			this->iterationlabel->Size = System::Drawing::Size(0, 17);
			this->iterationlabel->TabIndex = 5;
			// 
			// RandomButton
			// 
			this->RandomButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->RandomButton->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->RandomButton->Location = System::Drawing::Point(440, 145);
			this->RandomButton->Name = L"RandomButton";
			this->RandomButton->Size = System::Drawing::Size(87, 32);
			this->RandomButton->TabIndex = 6;
			this->RandomButton->Text = L"Random";
			this->RandomButton->UseVisualStyleBackColor = true;
			this->RandomButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::RandomButton_MouseClick);
			// 
			// ClearButton
			// 
			this->ClearButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ClearButton->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->ClearButton->Location = System::Drawing::Point(559, 145);
			this->ClearButton->Name = L"ClearButton";
			this->ClearButton->Size = System::Drawing::Size(87, 32);
			this->ClearButton->TabIndex = 7;
			this->ClearButton->Text = L"Clear";
			this->ClearButton->UseVisualStyleBackColor = true;
			this->ClearButton->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::ClearButton_MouseClick);
			// 
			// NormalizeCheck
			// 
			this->NormalizeCheck->AutoSize = true;
			this->NormalizeCheck->Cursor = System::Windows::Forms::Cursors::Hand;
			this->NormalizeCheck->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->NormalizeCheck->Location = System::Drawing::Point(498, 205);
			this->NormalizeCheck->Name = L"NormalizeCheck";
			this->NormalizeCheck->Size = System::Drawing::Size(94, 21);
			this->NormalizeCheck->TabIndex = 8;
			this->NormalizeCheck->Text = L"Normalize";
			this->NormalizeCheck->UseVisualStyleBackColor = true;
			this->NormalizeCheck->CheckedChanged += gcnew System::EventHandler(this, &MyForm::NormalizeCheck_CheckedChanged);
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			this->errorProvider1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"errorProvider1.Icon")));
			// 
			// ZoomTrack
			// 
			this->ZoomTrack->BackColor = System::Drawing::SystemColors::Control;
			this->ZoomTrack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ZoomTrack->Location = System::Drawing::Point(3, 30);
			this->ZoomTrack->Maximum = 100;
			this->ZoomTrack->Minimum = 1;
			this->ZoomTrack->Name = L"ZoomTrack";
			this->ZoomTrack->Size = System::Drawing::Size(200, 31);
			this->ZoomTrack->TabIndex = 9;
			this->ZoomTrack->Value = 1;
			this->ZoomTrack->Scroll += gcnew System::EventHandler(this, &MyForm::ZoomTrack_Scroll);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->ZoomTrack, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->ZoomLabel, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(440, 244);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42.30769F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 57.69231F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(206, 64);
			this->tableLayoutPanel2->TabIndex = 10;
			// 
			// ZoomLabel
			// 
			this->ZoomLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ZoomLabel->AutoSize = true;
			this->ZoomLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ZoomLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->ZoomLabel->Location = System::Drawing::Point(60, 4);
			this->ZoomLabel->Name = L"ZoomLabel";
			this->ZoomLabel->Size = System::Drawing::Size(86, 18);
			this->ZoomLabel->TabIndex = 10;
			this->ZoomLabel->Text = L"Zoom Oraný";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 446);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->NormalizeCheck);
			this->Controls->Add(this->ClearButton);
			this->Controls->Add(this->RandomButton);
			this->Controls->Add(this->iterationlabel);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"YSA";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HataPayiNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SinifSayiNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->OrneksecNumeric))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomTrack))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	e->Graphics->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	e->Graphics->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
	renk = new int[3];
	renk[0] = 25;
	renk[1] = 25;
	renk[2] = 112;
	ornekler = new double[sinif_sayi+2];
	hata_payi = double(HataPayiNumeric->Value);
}

private: System::Void SinifSayiNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	if (sinif_sayi < SinifSayiNumeric->Value) {
		Random^ rand = gcnew Random();
		int *temp = new int[sinif_sayi * 3];
		for (int i = 0; i < sinif_sayi * 3; i++) {
			temp[i] = renk[i];
		}
		delete renk;
		renk = new int[int(SinifSayiNumeric->Value) * 3];
		for (int i = 0; i < sinif_sayi * 3; i++) {
			renk[i] = temp[i];
		}
		delete temp;
		for (int i = (sinif_sayi * 3) ; i < (int(SinifSayiNumeric->Value) * 3); i += 3) {
			int red = rand->Next(0, 255), green = rand->Next(0, 255), blue = rand->Next(0, 255);
			renk[i] = red;
			renk[i + 1] = green;
			renk[i + 2] = blue;
		}
		if (ornek_sayi > 0) {
			double *temp2 = new double[(sinif_sayi + 2)*ornek_sayi];
			for (int j = 0; j < ((sinif_sayi + 2)*ornek_sayi); j++) {
				temp2[j] = ornekler[j];
			}
			delete ornekler;
			ornekler = new double[(int(SinifSayiNumeric->Value) + 2)*ornek_sayi];
			int k = 0;
			for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j++) {
				ornekler[k] = temp2[j];
				k++;
				if (k % (int(SinifSayiNumeric->Value) + 2) == (sinif_sayi + 2)) {
					for (int p = 0; p < (int(SinifSayiNumeric->Value) - sinif_sayi); p++) {
						ornekler[k] = -1;
						k++;
					}					
				}
			}
			delete temp2;
			sinif_sayi = int(SinifSayiNumeric->Value);
		}
		else {
			sinif_sayi = int(SinifSayiNumeric->Value);
			delete ornekler;
			ornekler = new double[sinif_sayi + 2];
		}
		SinifSayiNumeric->ForeColor=Color::FromArgb(renk[(sinif_sayi - 1) * 3], renk[(sinif_sayi - 1) * 3 + 1], renk[(sinif_sayi - 1) * 3 + 2]);
	}
	else {
		if (ornek_sayi > 0) {
			int silinen_say = 0, temp2_say = 0;
			for (int j = (int(SinifSayiNumeric->Value) + 2); j < (sinif_sayi + 2)*ornek_sayi; j += (sinif_sayi + 2)) {
				for (int k = 0; k < (sinif_sayi - int(SinifSayiNumeric->Value)); k++) {
					if (ornekler[j + k] == 1) {
						silinen_say++;
					}
				}
			}
			double *temp2 = new double[(ornek_sayi - silinen_say)*(int(SinifSayiNumeric->Value)+2)];
			for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j += (sinif_sayi + 2)) {
				bool silinecek = false;
				for (int p = (j + (int(SinifSayiNumeric->Value)) + 2); p < (j + (sinif_sayi + 2)); p++) {
					if (ornekler[p] == 1)
						silinecek = true;
				}
				if (!silinecek) {
					for (int k = j; k < (j + (int(SinifSayiNumeric->Value)) + 2); k++) {
						temp2[temp2_say] = ornekler[k];
						temp2_say++;
					}
				}
			}
			sinif_sayi=int(SinifSayiNumeric->Value); ornek_sayi -= silinen_say;
			delete ornekler;
			ornekler = new double[(sinif_sayi + 2)*ornek_sayi];
			for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j++) {
				ornekler[j] = temp2[j];
			}
			delete temp2;
			pictureBox1->CreateGraphics()->Clear(Color::DimGray);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			ornekciz(ornekler);
			if (cizildi) {
				double *temp2 = new double[sinif_sayi*3];
				for (int j = 0; j < sinif_sayi * 3; j++) {
					temp2[j] = ws[j];
				}
				delete ws;
				ws = new double[sinif_sayi * 3];
				for (int j = 0; j < sinif_sayi * 3; j++) {
					ws[j] = temp2[j];
				}
				delete temp2;
				Dogruciz(ornekler,ws);
			}
		}
		else {
			sinif_sayi = int(SinifSayiNumeric->Value);
			delete ornekler;
			ornekler = new double[sinif_sayi + 2];
		}

		int *temp = new int[(sinif_sayi) * 3];
		for (int i = 0; i < (sinif_sayi) * 3; i++) {
			temp[i] = renk[i];
		}
		delete renk;
		renk = new int[sinif_sayi * 3];
		for (int i = 0; i < sinif_sayi * 3; i++) {
			renk[i] = temp[i];
		}
		delete temp;
		SinifSayiNumeric->ForeColor = Color::FromArgb(renk[(sinif_sayi - 1) * 3], renk[(sinif_sayi - 1) * 3 + 1], renk[(sinif_sayi - 1) * 3 + 2]);
	}

	OrneksecNumeric->Maximum = sinif_sayi;
	if (sinif_sayi < OrneksecNumeric->Value)
		OrneksecNumeric->Value = sinif_sayi;
}

private: System::Void OrneksecNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	secilen_sinif = int(OrneksecNumeric->Value);
	OrneksecNumeric->ForeColor = Color::FromArgb(renk[(secilen_sinif - 1) * 3], renk[(secilen_sinif - 1) * 3 + 1], renk[(secilen_sinif - 1) * 3 + 2]);
}

private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	pen = gcnew Pen(Color::FromArgb(renk[(secilen_sinif - 1) * 3], renk[(secilen_sinif - 1) * 3 + 1], renk[(secilen_sinif - 1) * 3 + 2]));
	ornek_sayi++;
	if (ornek_sayi == 1) {
		ornekler[0] = e->X - (pictureBox1->Width / 2);
		ornekler[1] = ((pictureBox1->Height / 2) - e->Y);
		for (int j = 1; j < sinif_sayi + 1; j++) {
			if (j == secilen_sinif)
				ornekler[j + 1] = 1;
			else
				ornekler[j + 1] = -1;
			}
	}
	else {
		double *yeniorn=new double[sinif_sayi + 2];
		yeniorn[0] = e->X - (pictureBox1->Width / 2);
		yeniorn[1] = ((pictureBox1->Height / 2) - e->Y);
		for (int j = 1; j < sinif_sayi + 1; j++) {
			if (j == secilen_sinif)
				yeniorn[j + 1] = 1;
			else
				yeniorn[j + 1] = -1;
		}
		ornekekle(yeniorn);
		delete yeniorn;
	}
	pictureBox1->CreateGraphics()->DrawLine(pen, e->X - 2, e->Y, e->X + 2, e->Y);
	pictureBox1->CreateGraphics()->DrawLine(pen, e->X, e->Y - 2, e->X, e->Y + 2);
}

private: System::Void RandomButton_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Random^ random = gcnew Random();
	if(ws)
		delete ws;
	ws = new double[sinif_sayi*3];
	for (int j = 0; j < sinif_sayi * 3; j++) {
		if (j % 3 == 0) {
			ws[j] = random->Next(-1, 1) == -1 ? random->NextDouble()*(-1) : random->NextDouble();
		}
		else
			ws[j] = random->NextDouble();
	}
	pictureBox1->CreateGraphics()->Clear(Color::DimGray);
	if (NormalizeCheck->Checked)
			Dogruciz(normalized,ws);
	else
		Dogruciz(ornekler,ws);
}

private: System::Void discreteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ornek_sayi == 0)
		MessageBox::Show("Alýnmýþ örnek yok");
	else if (!cizildi)
		MessageBox::Show("Referans doðru yok");
	bool error;
	int iterations = 0;
	do {
		error = false;
		for (int i = 0; i < sinif_sayi; i++) {
			double output;
			for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j += (sinif_sayi + 2)) {
				if (NormalizeCheck->Checked) {
					ogrenildi = false;
					output = (ws[i * 3] * normalized[j] + (ws[i * 3 + 1] * normalized[j + 1]) + (ws[i * 3 + 2] * bias)) > 0 ? 1 : (-1);
					if (normalized[j + 2 + i] - output != 0) {
						error = true;
						ws[i * 3] = ws[i * 3] + c * ((normalized[j + 2 + i]) - output) * (normalized[j]) / 2;
						ws[i * 3 + 1] = ws[i * 3 + 1] + c * ((normalized[j + 2 + i]) - output) * (normalized[j + 1]) / 2;
						ws[i * 3 + 2] = ws[i * 3 + 2] + c * ((normalized[j + 2 + i]) - output) * bias / 2;
					}
				}
				else {
					output = (ws[i * 3] * ornekler[j] + (ws[i * 3 + 1] * ornekler[j + 1]) + (ws[i * 3 + 2] * bias)) > 0 ? 1 : (-1);
					if (ornekler[j + 2 + i] - output != 0) {
						error = true;
						ws[i * 3] = ws[i * 3] + c * ((ornekler[j + 2 + i]) - output) * (ornekler[j]) / 2;
						ws[i * 3 + 1] = ws[i * 3 + 1] + c * ((ornekler[j + 2 + i]) - output) * (ornekler[j + 1]) / 2;
						ws[i * 3 + 2] = ws[i * 3 + 2] + c * ((ornekler[j + 2 + i]) - output) * bias / 2;
					}
				}
				
			}

		}
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		if (NormalizeCheck->Checked){
			Dogruciz(normalized,ws);
		}
		else
			Dogruciz(ornekler,ws);
		iterations++;
	} while (error);
	if(NormalizeCheck->Checked)
		ogrenildi = true;
	iterationlabel->Text = "Iterations: " + iterations.ToString();

}

private: System::Void continuousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ornek_sayi == 0)
		MessageBox::Show("Alýnmýþ örnek yok");
	else if (!cizildi)
		MessageBox::Show("Referans doðru yok");
	else if (HataPayiNumeric->Value == 0)
		MessageBox::Show("Hata payý belirleyiniz!");
	else if (!NormalizeCheck->Checked) {
		if (MessageBox::Show("Örnekleri normalize etmeden devam etmek istiyor musunuz?", "Uyarý", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes) {
			double error;
			int iterations = 0;
			do {
				error = 0;
				for (int i = 0; i < sinif_sayi; i++) {
					double output;
					for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j += (sinif_sayi + 2)) {
						output = (2 / (1 + exp(-lamda * (ws[i * 3] * ornekler[j] + (ws[i * 3 + 1] * ornekler[j + 1]) + (ws[i * 3 + 2] * bias))))) - 1;
						ws[i * 3] += c * ((ornekler[j + 2 + i]) - output) * (ornekler[j]);
						ws[i * 3 + 1] += c * ((ornekler[j + 2 + i]) - output) * (ornekler[j + 1]);
						ws[i * 3 + 2] += c * ((ornekler[j + 2 + i]) - output) * bias;
						error += pow((ornekler[j + 2 + i] - output), 2) / 2;
					}
				}
				pictureBox1->CreateGraphics()->Clear(Color::DimGray);
				Dogruciz(ornekler,ws);
				iterations++;
			} while (error > hata_payi);
			iterationlabel->Text = "Iterations: " + iterations.ToString();
		}
	}
	else if (NormalizeCheck->Checked) {
		ogrenildi = false;
		double error;
		int iterations = 0;
		do {
			error = 0;
			for (int i = 0; i < sinif_sayi; i++) {
				double output;
				for (int j = 0; j < (sinif_sayi + 2)*ornek_sayi; j += (sinif_sayi + 2)) {
					output = (2 / (1 + exp(-lamda * (ws[i * 3] * normalized[j] + (ws[i * 3 + 1] * normalized[j + 1]) + (ws[i * 3 + 2] * bias))))) - 1;
					ws[i * 3] += c * ((normalized[j + 2 + i]) - output) * ((1 - pow(output, 2)) / 2) * (normalized[j]);
					ws[i * 3 + 1] += c * ((normalized[j + 2 + i]) - output) * ((1 - pow(output, 2)) / 2) * (normalized[j + 1]);
					ws[i * 3 + 2] += c * ((normalized[j + 2 + i]) - output) * ((1 - pow(output, 2)) / 2) * bias;
					error += pow((normalized[j + 2 + i] - output), 2) / 2;
				}
			}
			pictureBox1->CreateGraphics()->Clear(Color::DimGray);
			Dogruciz(normalized,ws);
			iterations++;
		} while (error > hata_payi);
		ogrenildi = true;
		iterationlabel->Text = "Iterations: " + iterations.ToString();
	}
}

private: System::Void NormalizeCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (NormalizeCheck->Checked) {
		if (ornek_sayi > 0) {
			double ssx = 0, ssy = 0, ortx = 0, orty = 0;
			normalized = new double[ornek_sayi * (sinif_sayi + 2)];
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j++) {
				normalized[j] = ornekler[j];
			}
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi + 2)) {
				ssx += ornekler[j];
				ssy += ornekler[j + 1];
			}
			ssx /= ornek_sayi;
			ssy /= ornek_sayi;
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi + 2)) {
				normalized[j] = pow((ornekler[j] - ssx), 2);
				normalized[j + 1] = pow((ornekler[j + 1] - ssy), 2);
			}
			ssx = 0;
			ssy = 0;
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi + 2)) {
				ssx += normalized[j];
				ssy += normalized[j + 1];
			}
			ssx = sqrt(ssx / ornek_sayi);
			ssy = sqrt(ssy / ornek_sayi);
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi + 2)) {
				ortx += ornekler[j];
				orty += ornekler[j + 1];
			}
			ortx /= ornek_sayi;
			orty /= ornek_sayi;
			for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi + 2)) {
				normalized[j] = (ornekler[j] - ortx) / ssx;
				normalized[j + 1] = (ornekler[j + 1] - orty) / ssy;
			}
			pictureBox1->CreateGraphics()->Clear(Color::DimGray);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			ornekciz(normalized);
			if (cizildi)
				Dogruciz(normalized,ws);
		}
		else {
			MessageBox::Show("Normalize edilecek örnek yok.");
			NormalizeCheck->Checked = false;
		}
	}
	else {
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
		ornekciz(ornekler);
		if (cizildi)
			Dogruciz(ornekler,ws);
	}
}

private: System::Void ZoomTrack_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (NormalizeCheck->Checked && ogrenildi) {
		double *zoomlu_dogrular, *zoomlu_ornekler;
		int p = 0;
		zoomlu_dogrular = new double[sinif_sayi * 3];
		zoomlu_ornekler = new double[ornek_sayi*(sinif_sayi + 2)];
		for (int j = 0; j < sinif_sayi * 3; j++) {
			if (j % 3 == 2)
				zoomlu_dogrular[j] = ws[j] * ZoomTrack->Value;
			else
				zoomlu_dogrular[j] = ws[j];

		}
		for (int j = 0; j < ornek_sayi*(sinif_sayi + 2); j++) {
			if (j % (sinif_sayi + 2) == 0 || j % (sinif_sayi + 2) == 1)
				zoomlu_ornekler[j] = normalized[j] * ZoomTrack->Value;
			else
				zoomlu_ornekler[j] = normalized[j];
		}
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		Dogruciz(zoomlu_ornekler, zoomlu_dogrular);
		delete zoomlu_ornekler, zoomlu_dogrular;
	}
	else {
		ZoomTrack->Value = 1;
		MessageBox::Show("Normalizeli öðrenme yaptýktan sonra zoom yapabilirsiniz!");
	}
}

private: System::Void HataPayiNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	hata_payi = double(HataPayiNumeric->Value);
}

private: System::Void ClearButton_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	delete renk;
	delete ornekler;
	delete ws;
	renk = new int[3];
	renk[0] = 25; renk[1] = 25; renk[2] = 112;
	secilen_sinif = 1;
	ornekler = new double[3];
	ornek_sayi = 0;
	cizildi = false;
	SinifSayiNumeric->Value = 1;
	ws = new double[sinif_sayi * 3];;
	iterationlabel->Text = "";
	ZoomTrack->Value = 1;
	NormalizeCheck->Checked = false;
	HataPayiNumeric->Value = 0;
	pictureBox1->CreateGraphics()->Clear(Color::DimGray);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
}

private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm::Close();
}

private: System::Void MyForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	delete ornekler; delete renk; delete ws, delete normalized;
}



private: void Dogruciz(double *cizilecek_ornekler,double *cizilecek_dogrular) {
	cizildi = true;
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
	for (int j = 0; j < sinif_sayi * 3; j+=3) {
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::FromArgb(renk[j], renk[j + 1], renk[j + 2]), 1.5f), 0, (pictureBox1->Height / 2 - ((-cizilecek_dogrular[j + 2] * bias - (cizilecek_dogrular[j] * -(pictureBox1->Width / 2))) / cizilecek_dogrular[j + 1])), pictureBox1->Width, (pictureBox1->Height / 2 - ((-cizilecek_dogrular[j + 2] * bias - (cizilecek_dogrular[j] * pictureBox1->Width / 2)) / cizilecek_dogrular[j + 1])));
	}
	ornekciz(cizilecek_ornekler);
}

private: void ornekekle(double *yeniorn) {
	int k = 0;
	double *temp = new double[(ornek_sayi-1)*(sinif_sayi + 2)];
	for (int j = 0; j < (ornek_sayi - 1) * (sinif_sayi + 2); j++) {
		temp[j] = ornekler[j];
	}
	delete ornekler;
	ornekler = new double[(ornek_sayi)*(sinif_sayi + 2)];
	for (int j = 0; j < (ornek_sayi - 1) * (sinif_sayi + 2); j++) {
		ornekler[j] = temp[j];
	}
	delete temp;
	for (int j = (ornek_sayi - 1) * (sinif_sayi + 2); j < (ornek_sayi) * (sinif_sayi + 2); j++) {
		ornekler[j] = yeniorn[k];
		k++;
	}
}

private: void ornekciz(double *cizilen) {
	for (int j = 0; j < ornek_sayi * (sinif_sayi + 2); j += (sinif_sayi+2)) {
		float x1 = (cizilen[j]) + (pictureBox1->Width / 2);
		float x2 = (pictureBox1->Height / 2) - (cizilen[j + 1]);
		int renkbul = 0;
		for (int k = j + 2; k < (j + sinif_sayi + 2); k++) {
			if (cizilen[k] == 1) {
				pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::FromArgb(renk[renkbul * 3], renk[renkbul * 3 + 1], renk[renkbul * 3 + 2]), 1.5f), (x1 - 2), x2, (x1 + 2), x2);
				pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::FromArgb(renk[renkbul * 3], renk[renkbul * 3 + 1], renk[renkbul * 3 + 2]), 1.5f), (x1), (x2 - 2), (x1), (x2 + 2));
				break;
			}
			renkbul++;
		}
	}
}

};
}
