#pragma once

namespace Task88 {

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
		static int MyPaint = 1;
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(857, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(857, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(839, 599);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 623);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyPaint = 1;
		pictureBox1->Invalidate();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyPaint = -1;
		pictureBox1->Invalidate();

	}
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		switch (MyPaint)
		{
		case 0:
			return; //ничего не делать
		case -1:
			e->Graphics->Clear(Color::LemonChiffon); // стереть
			MyPaint = 0;
			break;
		case 1:
			// здесь надо добавить собственно рисование
			int PenWidth = 3; // ширина пера
			Pen^ blackPen = gcnew Pen(Color::Black, PenWidth);
			SolidBrush^ redBrush = gcnew SolidBrush(Color::Red);
			// Задаем координаты концов отрезка
			int x1 = 0;
			int y1 = 0;
			int x2 = 100;
			
				int y2 = 100;
			// Рисуем линию
			e->Graphics->DrawLine(blackPen, x1, y1, x2, y2);
			// Create location and size of rectangle.
			int x = 200;
			int y = 100;
			int width = 60;
			int height = 60;
			// Рисуем и закрашиваем прямоугольник.
			e->Graphics->DrawRectangle(blackPen, x, y, width, height);
			e->Graphics->FillRectangle(redBrush, x + (PenWidth + 1) / 2,
				y + (PenWidth + 1) / 2, width - PenWidth, height - PenWidth);
			// Рисуем контур эллипса и отдельно закрашенный эллипс.
			y = 200;
			e->Graphics->DrawEllipse(blackPen, x, y, width, height);
			e->Graphics->FillEllipse(redBrush, x, y + 100, width, height);
			// Закрашиваем одиночный пиксель.
			e->Graphics->FillRectangle(redBrush, 110, 110, 1, 1);

			break;
		}
	}
	};
}
