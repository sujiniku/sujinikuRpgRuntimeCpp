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

		static int p_count ; //test

		static int mode_scene ;
		static int selecting_menu ;
		static int menu_tate_on ;
		static int cursol_stop ;
		static int your_money ;
		static int nin_i  ;

		static String^ drawString4 = "temp1"; // ��b����1�s��
		static String^ drawString5 = "temp2"; // ��b����2�s��
		static String^ drawString6 = "temp3"; // ��b����3�s��


		static int game_event1_end ;
		static int game_event2_end ;

		static int game_event1_end_dummuy ;


		static int key_nokori ;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			// �O���[�o���ϐ��̂���



			int p_count = 0; //test

			mode_scene=1;
			selecting_menu=1;
			menu_tate_on=1;
			cursol_stop=0;
			your_money=0;
			nin_i=0;

			String^ drawString4 = "temp1"; // ��b����1�s��
			String^ drawString5 = "temp2"; // ��b����2�s��
			String^ drawString6 = "temp3"; // ��b����3�s��


			game_event1_end=0;
			game_event2_end=0;

			game_event1_end_dummuy=0;


			static int key_nokori=0;







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





	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {


		// Create solid brush.
		SolidBrush^ blueBrush = gcnew SolidBrush(Color::Azure); // �R�}���h�w�i�F
		// Azure�͐F���B�N���E�h�Ƃ͖��֌W�B

		SolidBrush^ pinkBrush = gcnew SolidBrush(Color::Pink); // �J�[�\���F�B

		int x3 = 145;
		int y3 = 140;
		int width3 = 150; //110
		int height3 = 150;

		if (mode_scene == 1) {
			e->Graphics->FillRectangle(blueBrush, x3, y3, width3, height3);

		}



		// �I�����j���[�F�̕\���͔w�i�摜�ɏ㏑���Ƃ��ď����B
		int x2 = 145;
		int y2 = 140 + 50 * (selecting_menu - 1);
		int width2 = 22 * 5; //110
		int height2 = 40;

		if (menu_tate_on == 1) {

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


			switch (selecting_menu)	{
				// �����ꂽ���L�[�ɉ����āA�ړ�����W����

			case 1:
				drawString4 = "�u�͂��߂���v��I��" + p_count.ToString();
				// drawString1::Backcolor = Pink;
				break;
			case 2:
				drawString4 = "�u�Â�����v��I��" + p_count.ToString();
				break;
			case 3:
				drawString4 = "�u�����v��I��" + p_count.ToString();
				break;
			}



	

			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawPoint4 = PointF(100.0F, 300.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawString4, drawFont, drawBrush, drawPoint4);


			PointF drawPoint5 = PointF(100.0F, 350.0F); // F�͕��������_
			//e->Graphics->DrawString(drawString5, drawFont, drawBrush, drawPoint4);

			PointF drawPoint6 = PointF(100.0F, 390.0F); // F�͕��������_
			//e->Graphics->DrawString(drawString6, drawFont, drawBrush, drawPoint4);

		}


		if (mode_scene == 2) { // ����New Game�Ȃ�E�E�E�B
			int x4 = 80;
			int y4 = 280;
			int width4 = 410;
			int height4 = 150;

			e->Graphics->FillRectangle(blueBrush, x4, y4, width4, height4);




			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawPoint4 = PointF(100.0F, 300.0F); // F�͕��������_

														// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawString4, drawFont, drawBrush, drawPoint4);


			PointF drawPoint5 = PointF(100.0F, 350.0F); // F�͕��������_
			e->Graphics->DrawString(drawString5, drawFont, drawBrush, drawPoint5);

			PointF drawPoint6 = PointF(100.0F, 390.0F); // F�͕��������_
			e->Graphics->DrawString(drawString6, drawFont, drawBrush, drawPoint6);

		}



		if (mode_scene == 3) { // ���b�Z�[�W�̃E�B���h�E������
			

		}




	}

	private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		// P�������ꂽ�� p_count ��1�A�b�v // �f�o�b�O�p
		if (e->KeyData == Keys::P)
		{
			p_count = p_count + 1; // p�������񐔂̃J�E���g�ɐ����B
			panel1->Invalidate();
		}


		if (mode_scene == 1) { // �����I�[�v�j���O�V�[���Ȃ�

		// selecting_menu �� 1 �ȏォ�� 3 �ȉ��ɂ���B
			if (selecting_menu > 3) {
				selecting_menu = 3;

			}

			if (selecting_menu < 1) {
				selecting_menu = 1;
			}


			// ���L�[�i�㉺�̂݁j�������ꂽ��J�[�\�����㉺�Ɉړ�
			if (e->KeyData == Keys::Up || e->KeyData == Keys::Down)
			{
				switch (e->KeyData)
				{
					// �����ꂽ���L�[�ɉ����āA�ړ�����W����

				case Keys::Up:

					selecting_menu = selecting_menu - 1;
					break;
				case Keys::Down:

					selecting_menu = selecting_menu + 1;
					break;
				}


				if (1 < selecting_menu || selecting_menu < 3) {
					cursol_stop = 0;
				}



				if (selecting_menu > 3) { // 3�ȏ��3�ɂ���
					selecting_menu = 3;
					cursol_stop = 1;
				}
				else if (selecting_menu < 1) { // 1�ȉ���1�ɂ���
					selecting_menu = 1;
					cursol_stop = 1;
				}



				switch (selecting_menu)
				{
					// �����ꂽ���L�[�ɉ����āA�ړ�����W����

				case 1:
					drawString4 = "�u�͂��߂���v��I��";
					break;
				case 2:
					drawString4 = "�u�Â�����v��I��";
					break;
				case 3:
					drawString4 = "�u�����v��I��";
					break;
				}



				if (cursol_stop != 1) {
					panel1->Invalidate();
				}

			}

			

			// �I�[�v�j���O��̉�ʂɈڍs


			if (e->KeyData == Keys::Z) {



				switch (selecting_menu)
				{
					// �����ꂽ���L�[�ɉ����āA�ړ�����W����

				case 1:
					mode_scene = 2;
					menu_tate_on = 0;
					drawString4 = "�Q�[�����ŏ�����J�n";
					drawString5 = "���[�h�F" + mode_scene.ToString();
					break;
				case 2:
					drawString4 = "�Z�[�u��ʂ��J���܂��i�H�����j";
					break;
				case 3:
					drawString4 = "�ݒ��ʂł��i�H�����j";
					break;
				case 4:
					drawString4 = "�Q�[�����I���܂�";
					Close();
					break;
				}




				panel1->Invalidate();
			}



			if (cursol_stop != 1) {
				panel1->Invalidate();
			}

		}

			
		if (mode_scene == 2) {
			if (game_event1_end != 1) {
					
					game_event1_end = 1;
					drawString4 = "���l�u�����A�E�҂�A�悭�� ���Ă��ꂽ�BGT" + game_event1_end.ToString() ;
					drawString5 = "���Ȃ��ɁA��100�A�������Ă����悤�B�v" + your_money.ToString() ;
					drawString6 = "�i����{�^���������Ă��������jP" + p_count.ToString();;
					
					panel1->Invalidate();
					game_event1_end_dummuy = 1;
					key_nokori = 0;
					// e->KeyData = Keys::Escape;

				}


			if (game_event1_end == 1 && game_event2_end == 0 && key_nokori > 0 && e->KeyData == Keys::Z) {

				//if (game_event2_end != 1) {

				drawString4 = "���A415�s�ɂ���B";

	
				drawString4 = "���Ȃ��͋�100����ɓ��ꂽ�BG_Fflag" + game_event1_end.ToString();
				drawString5 = "�i����{�^���������Ă��������j";
				drawString6 = "";
				panel1->Invalidate();

				your_money = your_money + 100;
				game_event2_end = 1;

				key_nokori = 0;

				//mode_scene = 3; //�����Ń��[�h�J�ڂ���ƁA�u��100����ɓ��ꂽ�v�̍s���\������Ȃ��Ȃ��Ă��܂��I
			}


					
			if (game_event2_end == 1 && key_nokori >0 && e->KeyData == Keys::Z) {

						//if (game_event2_end != 1) {

						drawString4 = "���A415�s�ɂ���B";

						//if (e->KeyData == Keys::Z) {
	

						key_nokori = 0;

						mode_scene = 3; //�����Ń��[�h�J�ڂ���ƁA�u��100����ɓ��ꂽ�v�̍s���\������Ȃ��Ȃ��Ă��܂��I

						//}


				}







				panel1->Invalidate();


				key_nokori = 1;

				nin_i = nin_i + 1;
		}
		// MessageBox::Show("�L�[�����̏I���B"); // �f�o�b�O�p���b�Z�[�W
	}
	
}

; }