#pragma once
#include <math.h>
namespace Calisma {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	

	/// <summary>
	/// MyForm için özet
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		double bias = 1, c = 1, lamda = 1, hata_payi, *ornekler, *ws, *normalized;
		int ornek_sayi = 0, b = 0, r = 0;
		bool cizildi = false, ogrenildi = false;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  Menu;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  learningMethodsToolStripMenuItem;

	private: System::Windows::Forms::CheckBox^  Normalize;


	private: System::Windows::Forms::Label^  iterationLabel;

	private: System::Windows::Forms::ToolStripMenuItem^  discreteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  continuousToolStripMenuItem;
	private: System::Windows::Forms::NumericUpDown^  HataPayiNumeric;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::TrackBar^  ZoomTrack;
	private: System::Windows::Forms::Label^  ZoomLabel;

	private: System::Windows::Forms::Button^  button3;

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
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::Button^  button1;
			 

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->learningMethodsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->discreteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continuousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Normalize = (gcnew System::Windows::Forms::CheckBox());
			this->iterationLabel = (gcnew System::Windows::Forms::Label());
			this->HataPayiNumeric = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->ZoomTrack = (gcnew System::Windows::Forms::TrackBar());
			this->ZoomLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HataPayiNumeric))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomTrack))->BeginInit();
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
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->radioButton1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->radioButton1->Location = System::Drawing::Point(508, 51);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(119, 26);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Blue Object";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->radioButton2->ForeColor = System::Drawing::Color::DarkRed;
			this->radioButton2->Location = System::Drawing::Point(508, 83);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(112, 26);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->Text = L"Red Object";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(429, 135);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 37);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Random";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button1_MouseClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->label1->ForeColor = System::Drawing::Color::MidnightBlue;
			this->label1->Location = System::Drawing::Point(426, 354);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Blue Object Count: 0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->label2->ForeColor = System::Drawing::Color::DarkRed;
			this->label2->Location = System::Drawing::Point(426, 383);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(136, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Red Object Count: 0";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->Menu });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(715, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// Menu
			// 
			this->Menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->learningMethodsToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(50, 20);
			this->Menu->Text = L"Menu";
			// 
			// learningMethodsToolStripMenuItem
			// 
			this->learningMethodsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->discreteToolStripMenuItem,
					this->continuousToolStripMenuItem
			});
			this->learningMethodsToolStripMenuItem->Name = L"learningMethodsToolStripMenuItem";
			this->learningMethodsToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->learningMethodsToolStripMenuItem->Text = L"Learning Methods";
			// 
			// discreteToolStripMenuItem
			// 
			this->discreteToolStripMenuItem->Name = L"discreteToolStripMenuItem";
			this->discreteToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->discreteToolStripMenuItem->Text = L"Discrete";
			this->discreteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::discreteToolStripMenuItem_Click);
			// 
			// continuousToolStripMenuItem
			// 
			this->continuousToolStripMenuItem->Name = L"continuousToolStripMenuItem";
			this->continuousToolStripMenuItem->Size = System::Drawing::Size(136, 22);
			this->continuousToolStripMenuItem->Text = L"Continuous";
			this->continuousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::continuousToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(170, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->TextDirection = System::Windows::Forms::ToolStripTextDirection::Horizontal;
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->button3->Location = System::Drawing::Point(584, 135);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(119, 37);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Clear";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::button3_MouseClick);
			// 
			// Normalize
			// 
			this->Normalize->AutoSize = true;
			this->Normalize->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Normalize->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->Normalize->Location = System::Drawing::Point(525, 241);
			this->Normalize->Name = L"Normalize";
			this->Normalize->Size = System::Drawing::Size(95, 22);
			this->Normalize->TabIndex = 10;
			this->Normalize->Text = L"Normalize";
			this->Normalize->UseVisualStyleBackColor = true;
			this->Normalize->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Normalize_CheckedChanged);
			// 
			// iterationLabel
			// 
			this->iterationLabel->AutoSize = true;
			this->iterationLabel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->iterationLabel->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 11.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->iterationLabel->Location = System::Drawing::Point(426, 410);
			this->iterationLabel->Name = L"iterationLabel";
			this->iterationLabel->Size = System::Drawing::Size(90, 17);
			this->iterationLabel->TabIndex = 13;
			this->iterationLabel->Text = L"Iterations: 0";
			// 
			// HataPayiNumeric
			// 
			this->HataPayiNumeric->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HataPayiNumeric->Cursor = System::Windows::Forms::Cursors::Hand;
			this->HataPayiNumeric->DecimalPlaces = 2;
			this->HataPayiNumeric->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->HataPayiNumeric->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 131072 });
			this->HataPayiNumeric->Location = System::Drawing::Point(584, 197);
			this->HataPayiNumeric->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->HataPayiNumeric->Name = L"HataPayiNumeric";
			this->HataPayiNumeric->Size = System::Drawing::Size(48, 20);
			this->HataPayiNumeric->TabIndex = 14;
			this->HataPayiNumeric->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->HataPayiNumeric->ValueChanged += gcnew System::EventHandler(this, &MyForm::HataPayiNumeric_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(457, 197);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(116, 18);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Error Tolerance:";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->ZoomTrack, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->ZoomLabel, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(460, 269);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 42.30769F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 57.69231F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(206, 64);
			this->tableLayoutPanel2->TabIndex = 16;
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
			this->ClientSize = System::Drawing::Size(715, 556);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->HataPayiNumeric);
			this->Controls->Add(this->iterationLabel);
			this->Controls->Add(this->Normalize);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"YSA";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->HataPayiNumeric))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ZoomTrack))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		e->Graphics->DrawLine(gcnew Pen(Color::Black,1.5f), pictureBox1->Width/2, 0, pictureBox1->Width / 2, pictureBox1->Height);
		e->Graphics->DrawLine(gcnew Pen(Color::Black,1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height/2);
		ornekler = new double[(ornek_sayi + 1)*3];
	}
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Pen^ pen;
		ornek_sayi++;
		if (radioButton1->Checked) {
			pen = gcnew Pen(Color::MidnightBlue, 1.5f);
			if (ornek_sayi == 1) {
				ornekler[0] = e->X - (pictureBox1->Width / 2);
				ornekler[1] = ((pictureBox1->Height / 2) - e->Y);
				ornekler[2] = 1;
				b++;
				label1->Text = "Blue Object Count: " + b.ToString();
			}
			else {
				double cs[3];
				cs[0] = e->X - (pictureBox1->Width / 2);
				cs[1] = ((pictureBox1->Height / 2) - e->Y);
				cs[2] = 1;
				ornekekle(cs);
				b++;
				label1->Text = "Blue Object Count: " + b.ToString();

			}
		}
		else if (radioButton2->Checked) {
			pen = gcnew Pen(Color::DarkRed, 1.5f);
			if (ornek_sayi == 1) {
				ornekler[0] = e->X - (pictureBox1->Width / 2);
				ornekler[1] = ((pictureBox1->Height / 2) - e->Y);
				ornekler[2] = -1;
				r++;
				label2->Text = "Red Object Count: " + r.ToString();

			}
			else {
				double cs[3];
				cs[0] = e->X - (pictureBox1->Width / 2);
				cs[1] = ((pictureBox1->Height / 2) - e->Y);
				cs[2] = -1;
				ornekekle(cs);
				r++;
				label2->Text = "Red Object Count: " + r.ToString();

			}
			
		}

		pictureBox1->CreateGraphics()->DrawLine(pen, e->X - 2, e->Y, e->X + 2, e->Y);
		pictureBox1->CreateGraphics()->DrawLine(pen, e->X, e->Y - 2, e->X, e->Y + 2);
	}
private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Random^ random = gcnew Random();
	ws = new double[3];
	for (int j = 0; j < 3; j++) {
		ws[j] = random->NextDouble();
		if (j % 3 == 0) {
			ws[j] = random->Next(-1, 1) == -1 ? ws[j] * (-1) : ws[j];
		}
	}
	int a1 = random->Next(-1, 1);
	pictureBox1->CreateGraphics()->Clear(Color::DimGray);
	if (Normalize->Checked)
		Dogruciz(normalized, ws);
	else
		Dogruciz(ornekler, ws);
}

private: System::Void button3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if(ornekler)
		delete ornekler;
	if (normalized)
		delete normalized;
	if (ws)
	ws = nullptr;
	r = 0;
	b = 0;
	ornek_sayi = 0;
	cizildi = false;
	ogrenildi = false;
	Normalize->Checked = false;
	HataPayiNumeric->Value = 0;
	ZoomTrack->Value = 1;
	label1->Text = "Blue Object Count: " + (b.ToString());
	label2->Text = "Red Object Count: " + (r.ToString());
	pictureBox1->CreateGraphics()->Clear(Color::DimGray);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
	pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	delete ornekler, normalized, ws;
	MyForm::Close();
}
private: void Dogruciz(double *cizilecek_ornekler,double *cizilecek_dogru) {
	cizildi = true;
	if (cizilecek_dogru[0] == 0) {
		if (cizilecek_dogru[1] != 0) {
			double y1 = -cizilecek_dogru[2] * bias / cizilecek_dogru[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, -(y1 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekciz(cizilecek_ornekler);
		}
	}
	else {
		if (cizilecek_dogru[1] == 0) {
			double x1 = -cizilecek_dogru[2] * bias / cizilecek_dogru[0];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), x1 + pictureBox1->Width / 2, 0, x1 + pictureBox1->Width / 2, pictureBox1->Height);
			ornekciz(cizilecek_ornekler);
		}
		else {
			double y1 = (-cizilecek_dogru[2] * bias - (cizilecek_dogru[0] * pictureBox1->Width / 2)) / cizilecek_dogru[1];
			double y2 = (-cizilecek_dogru[2] * bias - (cizilecek_dogru[0] * -(pictureBox1->Width / 2))) / cizilecek_dogru[1];
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, -(y2 - pictureBox1->Height / 2), pictureBox1->Width, -(y1 - pictureBox1->Height / 2));
			ornekciz(cizilecek_ornekler);
		}
	}
}

private: void ornekekle(double *cs) {

	double *temp = new double[(ornek_sayi - 1) * 3];
	for (int j = 0; j < (ornek_sayi - 1) * 3; j++) {
		temp[j] = ornekler[j];

	}
	ornekler = new double[ornek_sayi * 3];
	for (int j = 0; j < (ornek_sayi - 1) * 3; j++) {
		ornekler[j] = temp[j];
	}
	delete temp;
	ornekler[(ornek_sayi - 1) * 3] = cs[0];
	ornekler[(ornek_sayi - 1) * 3 + 1] = cs[1];
	ornekler[(3 * ornek_sayi - 1)] = cs[2];

}


private: void ornekciz(double *cizilen) {
	for (int j = 0; j < ornek_sayi * 3; j += 3) {
		float x1 = (cizilen[j]) + (pictureBox1->Width / 2);
		float x2 = -((cizilen[j + 1]) - (pictureBox1->Height / 2));
		if (cizilen[j + 2] == 1) {
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::MidnightBlue, 1.5f), float(x1 - 2), x2, (x1 + 2), x2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::MidnightBlue, 1.5f), (x1), (x2 - 2), (x1), (x2 + 2));
		}
		else {
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::DarkRed, 1.5f), (x1 - 2), x2, (x1 + 2), x2);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::DarkRed, 1.5f), (x1), (x2 - 2), (x1), (x2 + 2));
		}

	}
}
private: System::Void discreteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ornek_sayi == 0) {
		MessageBox::Show("Alýnmýþ örnek yok");
	}
	else if (!(ws)) {
		MessageBox::Show("Referans doðru yok");
	}
	bool error = true;
	int iterations = 0;
	while (error) {
		error = false;
		double output;
		for (int j = 0; j < ornek_sayi * 3; j += 3) {
			if (Normalize->Checked) {
				ogrenildi = false;
				output = (ws[0] * normalized[j] + (ws[1] * normalized[j + 1]) + (ws[2] * bias)) > 0 ? 1 : (-1);
				if ((ornekler[j + 2] - output != 0)) {
					error = true;
					ws[0] = ws[0] + c * ((normalized[j + 2]) - output) * (normalized[j]) / 2;
					ws[1] = ws[1] + c * ((normalized[j + 2]) - output) * (normalized[j + 1]) / 2;
					ws[2] = ws[2] + c * ((normalized[j + 2]) - output) * bias / 2;
				}
			}
			else {
				output = (ws[0] * ornekler[j] + (ws[1] * ornekler[j + 1]) + (ws[2] * bias)) > 0 ? 1 : (-1);
				if ((ornekler[j + 2] - output != 0)) {
					error = true;
					ws[0] = ws[0] + c * ((ornekler[j + 2]) - output) * (ornekler[j]) / 2;
					ws[1] = ws[1] + c * ((ornekler[j + 2]) - output) * (ornekler[j + 1]) / 2;
					ws[2] = ws[2] + c * ((ornekler[j + 2]) - output) * bias / 2;
				}
			}
		}
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		if (Normalize->Checked)
			Dogruciz(normalized,ws);
		else
			Dogruciz(ornekler,ws);
		iterations++;
	}
	if (Normalize->Checked)
		ogrenildi = true;
	iterationLabel->Text = "Iterations: " + iterations.ToString();
}
private: System::Void continuousToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (ornek_sayi == 0) {
		MessageBox::Show("Alýnmýþ örnek yok");
	}
	else if (!(ws)) {
		MessageBox::Show("Referans doðru yok");
	}
	else if (HataPayiNumeric->Value == 0)
		MessageBox::Show("Hata payý belirleyiniz!");
	else if (!Normalize->Checked) {
		if (MessageBox::Show("Örnekleri normalize etmeden devam etmek istiyor musunuz?", "Uyarý", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == ::System::Windows::Forms::DialogResult::Yes) {
			double error;
			int iterations = 0;
			do {
				error = 0;
				double output;
				for (int j = 0; j < 3 * ornek_sayi; j += 3) {
					output = (2 / (1 + exp(-lamda * (ws[0] * ornekler[j] + (ws[1] * ornekler[j + 1]) + (ws[2] * bias))))) - 1;
					ws[0] += c * ((ornekler[j + 2]) - output) * (ornekler[j]);
					ws[1] += c * ((ornekler[j + 2]) - output) * (ornekler[j + 1]);
					ws[2] += c * ((ornekler[j + 2]) - output) * bias;
					error += pow((ornekler[j + 2] - output), 2) / 2;
				}
				pictureBox1->CreateGraphics()->Clear(Color::DimGray);
				Dogruciz(ornekler, ws);
				iterations++;
			} while (error > hata_payi);
			iterationLabel->Text = "Iterations: " + iterations.ToString();
		}
	}
	else if (Normalize->Checked) {
		ogrenildi = false;
		double error;
		int iterations = 0;
		do {
			error = 0;
			double output;
			for (int j = 0; j < 3 * ornek_sayi; j += 3) {
				output = (2 / (1 + exp(-lamda * (ws[0] * normalized[j] + (ws[1] * normalized[j + 1]) + (ws[2] * bias))))) - 1;
				ws[0] += c * ((normalized[j + 2]) - output) * ((pow(normalized[j + 2], 2) - pow(output, 2)) / 2) * (normalized[j]);
				ws[1] += c * ((normalized[j + 2]) - output) * ((pow(normalized[j + 2], 2) - pow(output, 2)) / 2) * (normalized[j + 1]);
				ws[2] += c * ((normalized[j + 2]) - output) * ((pow(normalized[j + 2], 2) - pow(output, 2)) / 2) * bias;
				error += pow((normalized[j + 2] - output), 2) / 2;
			}
			pictureBox1->CreateGraphics()->Clear(Color::DimGray);
			Dogruciz(normalized, ws);
			iterations++;
		} while (error > hata_payi);
		ogrenildi = true;
		iterationLabel->Text = "Iterations: " + iterations.ToString();
	}
}

private: System::Void HataPayiNumeric_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	hata_payi = double(HataPayiNumeric->Value);
}
private: System::Void Normalize_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (Normalize->Checked) {
		if (ornek_sayi > 0) {
			double ssx = 0, ssy = 0, ortx = 0, orty = 0;
			normalized = new double[ornek_sayi * 3];
			for (int j = 0; j < ornek_sayi * 3; j++) {
				normalized[j] = ornekler[j];
			}
			for (int j = 0; j < ornek_sayi * 3; j += 3) {
				ssx += ornekler[j];
				ssy += ornekler[j + 1];
			}
			ssx /= ornek_sayi;
			ssy /= ornek_sayi;
			for (int j = 0; j < ornek_sayi * 3; j += 3) {
				normalized[j] = pow((ornekler[j] - ssx), 2);
				normalized[j + 1] = pow((ornekler[j + 1] - ssy), 2);
			}
			ssx = 0;
			ssy = 0;
			for (int j = 0; j < ornek_sayi * 3; j += 3) {
				ssx += normalized[j];
				ssy += normalized[j + 1];
			}
			ssx = sqrt(ssx / ornek_sayi);
			ssy = sqrt(ssy / ornek_sayi);
			for (int j = 0; j < ornek_sayi * 3; j += 3) {
				ortx += ornekler[j];
				orty += ornekler[j + 1];
			}
			ortx /= ornek_sayi;
			orty /= ornek_sayi;
			for (int j = 0; j < ornek_sayi * 3; j += 3) {
				normalized[j] = (ornekler[j] - ortx) / ssx;
				normalized[j + 1] = (ornekler[j + 1] - orty) / ssy;
			}
			pictureBox1->CreateGraphics()->Clear(Color::DimGray);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
			ornekciz(normalized);
			if (cizildi)
				Dogruciz(normalized, ws);
		}
		else {
			MessageBox::Show("Normalize edilecek örnek yok.");
			Normalize->Checked = false;
		}
	}
	else {
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
		pictureBox1->CreateGraphics()->DrawLine(gcnew Pen(Color::Black, 1.5f), 0, pictureBox1->Height / 2, pictureBox1->Width, pictureBox1->Height / 2);
		ornekciz(ornekler);
		if (cizildi)
			Dogruciz(ornekler, ws);
	}
}
private: System::Void ZoomTrack_Scroll(System::Object^  sender, System::EventArgs^  e) {
	if (Normalize->Checked && ogrenildi) {
		double *zoomlu_dogru, *zoomlu_ornekler;
		int p = 0;
		zoomlu_dogru = new double[3];
		zoomlu_ornekler = new double[ornek_sayi*3];
		for (int j = 0; j < 3; j++) {
			if (j % 3 == 2)
				zoomlu_dogru[j] = ws[j] * ZoomTrack->Value;
			else
				zoomlu_dogru[j] = ws[j];
		}
		for (int j = 0; j < ornek_sayi * 3; j++) {
			if (j % 3 == 0 || j % 3 == 1)
				zoomlu_ornekler[j] = normalized[j] * ZoomTrack->Value;
			else
				zoomlu_ornekler[j] = normalized[j];
		}
		pictureBox1->CreateGraphics()->Clear(Color::DimGray);
		Dogruciz(zoomlu_ornekler, zoomlu_dogru);
		delete zoomlu_ornekler, zoomlu_dogru;
	}
	else {
		ZoomTrack->Value = 1;
		MessageBox::Show("Normalizeli öðrenme yaptýktan sonra zoom yapabilirsiniz!");
	}
}
};
}
