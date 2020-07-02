#pragma once
#include "Input.h"
#include "About.h"
#include "Browse.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <windows.h>
namespace Архимед {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Сводка для Grafik
	/// </summary>
	public ref class Grafik : public System::Windows::Forms::Form
	{
	public:
		Grafik(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Grafik()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::ComboBox^ comboBox1;



	private: System::Windows::Forms::Timer^ timer1;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ вводПараметровToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ нарисоватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ оПрограммеToolStripMenuItem1;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;


	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;

	private: System::Windows::Forms::ToolStripMenuItem^ описаниеПрограммыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сайтToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox1;






	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Grafik::typeid));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->вводПараметровToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->нарисоватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->оПрограммеToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->описаниеПрограммыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сайтToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1->SuspendLayout();
			this->toolStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Спираль Архимеда", L"Спираль Ферма" });
			this->comboBox1->Location = System::Drawing::Point(832, 84);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(251, 28);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->Text = L"график";
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Grafik::Timer1_Tick);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(832, 174);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(235, 20);
			this->label1->TabIndex = 7;
			this->label1->Text = L"расстояние между витками = ";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(832, 208);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(147, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"начальный угол = ";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(832, 241);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"конечный угол = ";
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"быстро", L"средне", L"медленно", L"без анимации" });
			this->comboBox2->Location = System::Drawing::Point(832, 131);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(251, 28);
			this->comboBox2->TabIndex = 10;
			this->comboBox2->Text = L"анимация";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Ivory;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->вводПараметровToolStripMenuItem,
					this->нарисоватьToolStripMenuItem, this->оПрограммеToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1099, 33);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// вводПараметровToolStripMenuItem
			// 
			this->вводПараметровToolStripMenuItem->Name = L"вводПараметровToolStripMenuItem";
			this->вводПараметровToolStripMenuItem->Size = System::Drawing::Size(174, 29);
			this->вводПараметровToolStripMenuItem->Text = L"Ввод параметров";
			this->вводПараметровToolStripMenuItem->Click += gcnew System::EventHandler(this, &Grafik::ВводПараметровToolStripMenuItem_Click);
			// 
			// нарисоватьToolStripMenuItem
			// 
			this->нарисоватьToolStripMenuItem->Name = L"нарисоватьToolStripMenuItem";
			this->нарисоватьToolStripMenuItem->Size = System::Drawing::Size(125, 29);
			this->нарисоватьToolStripMenuItem->Text = L"Нарисовать";
			this->нарисоватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Grafik::НарисоватьToolStripMenuItem_Click);
			// 
			// оПрограммеToolStripMenuItem
			// 
			this->оПрограммеToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->оПрограммеToolStripMenuItem1,
					this->описаниеПрограммыToolStripMenuItem, this->сайтToolStripMenuItem
			});
			this->оПрограммеToolStripMenuItem->Name = L"оПрограммеToolStripMenuItem";
			this->оПрограммеToolStripMenuItem->Size = System::Drawing::Size(97, 29);
			this->оПрограммеToolStripMenuItem->Text = L"Справка";
			// 
			// оПрограммеToolStripMenuItem1
			// 
			this->оПрограммеToolStripMenuItem1->Name = L"оПрограммеToolStripMenuItem1";
			this->оПрограммеToolStripMenuItem1->Size = System::Drawing::Size(297, 34);
			this->оПрограммеToolStripMenuItem1->Text = L"О программе";
			this->оПрограммеToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Grafik::ОПрограммеToolStripMenuItem1_Click);
			// 
			// описаниеПрограммыToolStripMenuItem
			// 
			this->описаниеПрограммыToolStripMenuItem->Name = L"описаниеПрограммыToolStripMenuItem";
			this->описаниеПрограммыToolStripMenuItem->Size = System::Drawing::Size(297, 34);
			this->описаниеПрограммыToolStripMenuItem->Text = L"Описание программы";
			this->описаниеПрограммыToolStripMenuItem->Click += gcnew System::EventHandler(this, &Grafik::ОписаниеПрограммыToolStripMenuItem_Click_1);
			// 
			// сайтToolStripMenuItem
			// 
			this->сайтToolStripMenuItem->Name = L"сайтToolStripMenuItem";
			this->сайтToolStripMenuItem->Size = System::Drawing::Size(297, 34);
			this->сайтToolStripMenuItem->Text = L"Сайт";
			this->сайтToolStripMenuItem->Click += gcnew System::EventHandler(this, &Grafik::СайтToolStripMenuItem_Click);
			// 
			// toolStrip1
			// 
			this->toolStrip1->BackColor = System::Drawing::Color::Bisque;
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripButton1,
					this->toolStripButton4
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 33);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(1099, 33);
			this->toolStrip1->TabIndex = 12;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(34, 28);
			this->toolStripButton1->Text = L"Ввод параметров";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Grafik::ВводПараметровToolStripMenuItem_Click);
			// 
			// toolStripButton4
			// 
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(34, 28);
			this->toolStripButton4->Text = L"Stop";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Grafik::ToolStripButton4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(12, 84);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(800, 800);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// Grafik
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PeachPuff;
			this->ClientSize = System::Drawing::Size(1099, 903);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Grafik";
			this->Text = L"Grafik";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int a = 0;//расстояние между витками
		int f1 = 0;//начальный угол
		int f2 = 0;//конечный угол
		double i;//угол
		double k;//коэффициент для спирали Архимеда
		int flag;//флаг для таймера
		double step;//шаг
		Bitmap^ bmp;//холст
		Graphics^ coordinate;//круг с осями
		Graphics^ graph;//прямая спираль
		Graphics^ graph_reverse;//обратная спираль
		Pen^ pen;//чёрный карандаш
		Pen^ pen_gr;//розовый карандаш
		private: void Draw() {
			bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			coordinate = Graphics::FromImage(bmp);
			graph = Graphics::FromImage(bmp);
			graph_reverse = Graphics::FromImage(bmp);
			pen = gcnew Pen(Color::Black, 4);
			pen_gr = gcnew Pen(Color::DeepPink, 4);
			pictureBox1->Image = bmp;
			coordinate->DrawLine(pen, 0, pictureBox1->Height/2, pictureBox1->Width, pictureBox1->Height / 2);
			coordinate->DrawLine(pen, pictureBox1->Width / 2, 0, pictureBox1->Width / 2, pictureBox1->Height);
			coordinate->DrawEllipse(pen, 2,2, pictureBox1->Width-4, pictureBox1->Height-4);
		}
private: System::Void ВводПараметровToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
			Input^ form_input = gcnew Input(a, f1, f2);
			form_input->ShowDialog();
			if (timer1->Enabled == true) {
				timer1->Enabled = false;
			}
			a = form_input->a;
			f1 = form_input->f1;
			f2 = form_input->f2;
			label1->Text = "расстояние между витками = " + Convert::ToString(a);
			label2->Text = "начальный угол = " + Convert::ToString(f1);
			label3->Text = "конечный угол = " + Convert::ToString(f2);
}
private: System::Void НарисоватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;//останавливаем таймер
	step = 1;
	i = f1;
	k = a / (2 * M_PI);
	if (comboBox2->SelectedIndex == 0 || comboBox2->SelectedIndex == 1 || comboBox2->SelectedIndex == 2) {
		if (comboBox1->SelectedIndex == 0) {
			flag = 1;
			timer1->Enabled = true;
			Draw();
		}
		if (comboBox1->SelectedIndex == 1) {
			flag = 2;
			timer1->Enabled = true;
			Draw();
		}
		switch (comboBox2->SelectedIndex) {
		case 0:
				step = 5;
			break;
		case 1:
				step = 2;
			break;
		case 2:
				step = 0.7;
			break;
		}
	}
	else if(comboBox2->SelectedIndex == 3){
		Draw();
		if (comboBox1->SelectedIndex == 0) {
			for (i; i < f2; ) {
				float f = i * M_PI / 180;
				float r = k * f;
				float x = r * cos(f);
				float y = r * sin(f);
				i += step;
				f = i * M_PI / 180;
				r = k * f;
				float x1 = r * cos(f);
				float y1 = r * sin(f);
				graph->DrawLine(pen_gr, pictureBox1->Width / 2 + x, pictureBox1->Height / 2 - y, pictureBox1->Width / 2 + x1, pictureBox1->Height / 2 - y1);
			}
			pictureBox1->Image = bmp;
		}
		else if(comboBox1->SelectedIndex == 1){
			for (i; i < f2; ) {
				float f = i * M_PI / 180;
				float r = a * sqrt(f);
				float x = r * cos(f);
				float y = r * sin(f);
				i += step;
				f = i * M_PI / 180;
				r = a * sqrt(f);
				float x1 = r * cos(f);
				float y1 = r * sin(f);
				graph->DrawLine(pen_gr, pictureBox1->Width / 2 + x, pictureBox1->Height / 2 - y, pictureBox1->Width / 2 + x1, pictureBox1->Height / 2 - y1);
				graph_reverse->DrawLine(pen_gr, pictureBox1->Width / 2 - x, pictureBox1->Height / 2 + y, pictureBox1->Width / 2 - x1, pictureBox1->Height / 2 + y1);
			}
			pictureBox1->Image = bmp;
		}
	}
}
private: System::Void ОПрограммеToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	About^ form_about = gcnew About;
	form_about->ShowDialog();
}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (i < f2) {
		if (flag == 1) {
				float f = i * M_PI / 180;
				float r = k * f;
				float x = r * cos(f);
				float y = r * sin(f);
				i += step;
			    f = i * M_PI / 180;
				r = k * f;
				float x1 = r * cos(f);
				float y1 = r * sin(f);
				graph->DrawLine(pen_gr, pictureBox1->Width/2 + x, pictureBox1->Height/2 - y, pictureBox1->Width/2 + x1, pictureBox1->Height/2 - y1);
				pictureBox1->Image = bmp;
		}
		else {
			    float f = i * M_PI / 180;
				float r = a * sqrt(f);
				float x = r * cos(f);
				float y = r * sin(f);
				i += step;
				f = i * M_PI / 180;
				r = a * sqrt(f);
				float x1 = r*cos(f);
				float y1 = r *sin(f);
				graph->DrawLine(pen_gr, pictureBox1->Width / 2 + x, pictureBox1->Height / 2 - y, pictureBox1->Width / 2 + x1, pictureBox1->Height / 2 - y1);
				graph_reverse->DrawLine(pen_gr, pictureBox1->Width / 2 - x, pictureBox1->Height / 2 + y, pictureBox1->Width / 2 - x1, pictureBox1->Height / 2 + y1);
				pictureBox1->Image = bmp;
		}
	}
	else {
		timer1->Enabled = false;
	}
}
private: System::Void ToolStripButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	timer1->Enabled = false;
}
private: System::Void ОписаниеПрограммыToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("1) Выберите один из двух графиков, который хотите нарисовать\n2) В пункте анимация выберите наличие и скорость прорисовки\n3) (Целые числа!)Нажмите на кнопку ввод парматеров и введите расстояние между витками([0, 50]), начальный([-360, 0]) и конечный([0, 1440]) углы.\n4) В разделе справка есть ссылка на сайт, на котором вы можете связаться с разработчиками");
}
private: System::Void СайтToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Browse^ site = gcnew Browse;
	site->Show();
}
};
}
