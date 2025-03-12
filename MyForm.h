#pragma once

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(115, 118);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(194, 438);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(193, 551);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(35, 191);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::paint1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(407, 791);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		static array<Color>^ activeColors = {
			Color::FromArgb(255, 0, 0),
			Color::FromArgb(255, 255, 0),
			Color::FromArgb(0, 255, 0)
		};

		static array<Color>^ inactiveColors = {
			Color::FromArgb(100, 0, 0),
			Color::FromArgb(100, 100, 0),
			Color::FromArgb(0, 100, 0)
		};

		System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		int activeColor;
		Random^ rand = gcnew Random();
		Graphics^ g = e->Graphics;
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

		Rectangle rect = Rectangle(20, 20, 160, 400);
		g->FillRectangle(Brushes::DarkOliveGreen, rect);
		g->DrawRectangle(Pens::Black, rect);

		activeColor = rand->Next(3);

		for (int i = 0; i < 3; i++)
		{
			Color clr = (i == activeColor) ? activeColors[i] : inactiveColors[i];
			g->FillEllipse(gcnew SolidBrush(clr), 50, 50 + i * 120, 100, 100);
			g->DrawEllipse(Pens::Black, 50, 50 + i * 120, 100, 100);
		}
	}
	private: System::Void paint1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		SolidBrush^ b = gcnew SolidBrush(Color::Gray);
		e->Graphics->FillRectangle(b, 0, 0, 200, 200);
	}
};
}
