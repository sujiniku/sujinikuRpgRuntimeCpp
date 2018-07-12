#pragma once

extern "C" {
#include <windows.h>
}


namespace sujinikuRpgRuntimeCpp {



	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		static int mode_scene = 1;
		int selecting_menu = 1;
		int menu_tate_on = 1;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			// �O���[�o���ϐ��̂���


		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(1, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(622, 438);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &MyForm::panel1_PreviewKeyDown);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(624, 442);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}



			 static String^ drawString4 = "temp";

	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {


		// Create solid brush.
		SolidBrush^ blueBrush = gcnew SolidBrush(Color::Azure); // �R�}���h�w�i�F
		// Azure�͐F���B�N���E�h�Ƃ͖��֌W�B

		SolidBrush^ pinkBrush = gcnew SolidBrush(Color::Pink); // �J�[�\���F�B

		int x3 = 145;
		int y3 = 140;
		int width3 = 150 ; //110
		int height3 = 150;

		e->Graphics->FillRectangle(blueBrush, x3, y3, width3, height3);


		// �I�����j���[�F�̕\���͔w�i�摜�ɏ㏑���Ƃ��ď����B
		int x2 = 145;
		int y2 = 140+50 *( selecting_menu - 1 );
		int width2 = 22*5; //110
		int height2 = 40;

		if (menu_tate_on == 1){
		
			// Fill rectangle to screen.
			e->Graphics->FillRectangle(pinkBrush, x2, y2, width2, height2);
		}









		// ���ʐݒ�
		// String^ CursolString = "��"; // �J�[�\���̑�p

		// �t�H���g�iMS�S�V�b�N��Arial�Ȃǁj�ƃu���V�i��������F�Ȃǎw��j�̃I�u�W�F�N�g�쐬�B
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);


		// �ȏ�A�S��ʂ̋��ʐݒ�


		if (mode_scene == 1) { // �����I�[�v�j���O�Ȃ�E�E�E�B

			// �������`�����߂̃I�u�W�F�N�g�쐬�B
			String^ drawString1 = "�͂��߂���";

			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawPoint1 = PointF(150.0F, 150.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawString1, drawFont, drawBrush, drawPoint1);


			// Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image�^�Ő錾�B��������_��
			// e->Graphics->DrawImage (mapchip_image, 225 + 32, 140 + 32, 32, 32);



			// �������`�����߂̃I�u�W�F�N�g�쐬�B
			String^ drawString2 = "�Â�����";



			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawPoint2 = PointF(150.0F, 200.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawString2, drawFont, drawBrush, drawPoint2);



			// �������`�����߂̃I�u�W�F�N�g�쐬�B
			String^ drawString3 = "�����";



			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawPoint3 = PointF(150.0F, 250.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawString3, drawFont, drawBrush, drawPoint3);




			// �������`�����߂̃I�u�W�F�N�g�쐬�B



			if (selecting_menu == 1) {

				drawString4 = "�u�͂��߂���v��I��";
				// drawString1::Backcolor = Pink;

			}
			else if (selecting_menu == 2) {

				drawString4 = "�u�Â�����v��I��";
			}
			else if (selecting_menu == 3) {

				drawString4 = "�u�����v��I��";
			}
			else {
				drawString4 = "�u�����v��I��";
			}

		}


		if (mode_scene == 2) { // ����New Game�Ȃ�E�E�E�B
			drawString4 = "���l�u�����A�E�҂�A�悭�� ���Ă��ꂽ�B�v";


		}



		// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
		PointF drawPoint4 = PointF(100.0F, 300.0F); // F�͕��������_

		// ���ۂɕ�������o�͂��閽�߁B
		e->Graphics->DrawString(drawString4, drawFont, drawBrush, drawPoint4);


		







	}

	private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {




		if (mode_scene == 1){ // �����I�[�v�j���O�V�[���Ȃ�

		// selecting_menu �� 1 �ȏォ�� 3 �ȉ��ɂ���B
		if (selecting_menu > 3) {
			selecting_menu = 3;
		}

		if (selecting_menu < 1) {
			selecting_menu = 1;
		}


		// ���L�[�i�㉺�̂݁j�������ꂽ��J�[�\�����㉺�Ɉړ�
		if ( e->KeyData == Keys::Up || e->KeyData == Keys::Down)
		{
			switch (e->KeyData)
			{
				// �����ꂽ���L�[�ɉ����āA�ړ�����W����

			case Keys::Up:
				// MessageBox::Show("��L�[��������܂����B");
				selecting_menu = selecting_menu - 1;
				break;
			case Keys::Down:
				// MessageBox::Show("���L�[��������܂����B");
				selecting_menu = selecting_menu + 1;
				break;
			}

			
			if (selecting_menu > 3) { // 3�ȏ��3�ɂ���
				selecting_menu = 3;
			}
			else if (selecting_menu < 1) { // 1�ȉ���1�ɂ���
				selecting_menu = 1;
			}






			if (selecting_menu == 1) {

				String^ drawString4 = "�u�͂��߂���v��I��";



			}
			else if (selecting_menu == 2) {

				String^ drawString4 = "�u�Â�����v��I��";
			}
			else if (selecting_menu == 3) {

				String^ drawString4 = "�u�����v��I��";
			}
			else {
				String^ drawString4 = "�u�����v��I��";
			}


			panel1->Invalidate();

		}// �I�[�v�j���O��̉�ʂɈڍs
		if (e->KeyData == Keys::Z )
		{
			if (selecting_menu == 1) {
				mode_scene = 2;
				menu_tate_on = 0;
				drawString4 = "�Q�[�����ŏ�����J�n";
			}
			else if (selecting_menu == 2) {

				drawString4 = "�Z�[�u��ʂ��J���܂��i�H�����j";
			}
			else if (selecting_menu == 3) {
				drawString4 = "�Q�[�����I���܂�";
				Close();
			}
			else {
				drawString4 = "�Q�[�����I���܂�";
			}
		}


		if (mode_scene == 2) {
			String^ drawString4 = "���l�u�����A�E�҂�A�悭�� ���Ă��ꂽ�B�v";
			
			panel1->Invalidate();
		}
			// MessageBox::Show("�L�[�����̏I���B"); // �f�o�b�O�p���b�Z�[�W














		}
	}
	}

; }