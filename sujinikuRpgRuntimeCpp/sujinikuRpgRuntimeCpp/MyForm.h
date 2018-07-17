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

		static String^ drawTalkString1 = "temp1"; // ��b����1�s��
		static String^ drawTalkString2 = "temp2"; // ��b����2�s��
		static String^ drawTalkString3 = "temp3"; // ��b����3�s��


		static int game_event1_end ;
		static int game_event2_end ;

		static int game_event1_end_dummuy ;


		static int key_nokori ;




		static int chx;
		static int chy;

		static int saisyo_x = 3;
		static int saisyo_y = 4;

		// �}�b�v�̃T�C�Y�̕ϐ�
		static int map_x_size = 10;
		static int map_y_size = 7;



		// �i�s��̕ǔ���̃A���S���Y���p�̕ϐ�
		static int desti_x; // �i�s��̕ǔ���̂��߂�x���W�ϐ�
		static int desti_y; // �i�s��̕ǔ���̂��߂�x���W�ϐ�


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//

			// �O���[�o���ϐ��̂���



			int p_count = 0; //test

			mode_scene = 1;
			selecting_menu = 1;
			menu_tate_on = 1;
			cursol_stop = 0;
			your_money = 0;
			nin_i = 0;

			String^ drawTalkString1 = "temp1"; // ��b����1�s��
			String^ drawTalkString2 = "temp2"; // ��b����2�s��
			String^ drawTalkString3 = "temp3"; // ��b����3�s��


			game_event1_end = 0;
			game_event2_end = 0;

			game_event1_end_dummuy = 0;


			static int key_nokori = 0;



			chx = saisyo_x;
			chy = saisyo_y;



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
			this->DoubleBuffered = true;
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

		this->DoubleBuffered = true;

		// Create solid brush.
		SolidBrush^ blueBrush = gcnew SolidBrush(Color::Azure); // �R�}���h�w�i�F
		// Azure�͐F���B�N���E�h�Ƃ͖��֌W�B

		SolidBrush^ pinkBrush = gcnew SolidBrush(Color::Pink); // �J�[�\���F�B

		// OP�R�}���h���j���[�E�B���h�E�i�F�̔w�i�F�j�̕`��Ȃ�
		if (mode_scene == 1) {
			int OPmenuWindow_x = 145;
			int OPmenuWindow_y = 140;
			int OPmenuWindow_width = 150;
			int OPmenuWindow_height = 150;

			e->Graphics->FillRectangle(blueBrush, OPmenuWindow_x, OPmenuWindow_y, OPmenuWindow_width, OPmenuWindow_height);
		}

		// �I�����j���[�̃J�[�\���F�̕\���͔w�i�摜�ɏ㏑���Ƃ��ď����B
		if (menu_tate_on == 1) {
			int Cursol_x = 145;
			int Cursol_y = 140 + 50 * (selecting_menu - 1);
			int Cursol_width = 22 * 5; // 110
			int Cursol_height = 40;
			
			// Fill rectangle to screen.
			e->Graphics->FillRectangle(pinkBrush, Cursol_x, Cursol_y, Cursol_width, Cursol_height);
		}


		// ���ʐݒ�
		// String^ CursolString = "��"; // �J�[�\���̑�p // �v�ɂȂ����āB���T�C�N�����邩������Ȃ��̂Ŏc���Ƃ��B

		// �t�H���g�iMS�S�V�b�N��Arial�Ȃǁj�ƃu���V�i��������F�Ȃǎw��j�̃I�u�W�F�N�g�쐬�B
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);


		// �ȏ�A�S��ʂ̋��ʐݒ�


		if (mode_scene == 1) { // �����I�[�v�j���O�Ȃ�E�E�E�B // switch���ɂ́A���Ȃ��B�����ƁA�ҏW���Â炭�Ȃ�̂ŁB
														// Visual C++ �̏ꍇ�ASwitich�����ƃ��[�J���ϐ����g���Â炭�Ȃ�B
			// �������`�����߂̃I�u�W�F�N�g�쐬�B
			String^ drawOP_MenuString1 = "�͂��߂���";

			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawOP_MenuPoint1 = PointF(150.0F, 150.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawOP_MenuString1, drawFont, drawBrush, drawOP_MenuPoint1);
			

			// ������"�Â�����"��`�����߂̃I�u�W�F�N�g�B
			String^ drawOP_MenuString2 = "�Â�����";
			PointF drawOP_MenuPoint2 = PointF(150.0F, 200.0F); // F�͕��������_
			e->Graphics->DrawString(drawOP_MenuString2, drawFont, drawBrush, drawOP_MenuPoint2);
			

			// ������"�����"��`�����߂̃I�u�W�F�N�g�B
			String^ drawOP_MenuString3 = "�����";
			PointF drawOP_MenuPoint3 = PointF(150.0F, 250.0F); // F�͕��������_
			e->Graphics->DrawString(drawOP_MenuString3, drawFont, drawBrush, drawOP_MenuPoint3);


			switch (selecting_menu)	{ // �����ꂽ���L�[�ɉ����āA�I�𒆂̓��e��\�����W����
				case 1:
					drawTalkString1 = "�u�͂��߂���v��I��" + p_count.ToString();
					// drawOP_MenuString1::Backcolor = Pink;
					break;
				case 2:
					drawTalkString1 = "�u�Â�����v��I��" + p_count.ToString();
					break;
				case 3:
					drawTalkString1 = "�u�����v��I��" + p_count.ToString();
					break;
			}

			
			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawDestination_OP = PointF(100.0F, 300.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawTalkString1, drawFont, drawBrush, drawDestination_OP);

		}


		else if (mode_scene == 2) { // �����u�͂��߂���v�Ȃ�E�E�E�B
			
			Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image�^�Ő錾�B��������_��
			e->Graphics->DrawImage (mapchip_image, 225 + 32, 140 + 32, 32, 32);


			int messageWindow_x = 80;
			int messageWindow_y = 280;
			int messageWindow_width = 410;
			int messageWindow_height = 150;

			e->Graphics->FillRectangle(blueBrush, messageWindow_x, messageWindow_y, 
				messageWindow_width, messageWindow_height);

			
			// �o�͈ʒu�̍��W�I�u�W�F�N�g���쐬�B���W150,150�ɕ����摜��\��t����\��B
			PointF drawTalkLine1_Point = PointF(100.0F, 300.0F); // F�͕��������_

			// ���ۂɕ�������o�͂��閽�߁B
			e->Graphics->DrawString(drawTalkString1, drawFont, drawBrush, drawTalkLine1_Point);


			PointF drawTalkLine2_Point = PointF(100.0F, 350.0F); // F�͕��������_
			e->Graphics->DrawString(drawTalkString2, drawFont, drawBrush, drawTalkLine2_Point);

			PointF drawTalkLine3_Point = PointF(100.0F, 390.0F); // F�͕��������_
			e->Graphics->DrawString(drawTalkString3, drawFont, drawBrush, drawTalkLine3_Point);

		}

		
		if (mode_scene == 3) { // �}�b�v�ړ����[�h

			// �}�b�v�̃f�[�^ // [y.x]
			int maptable[7][10] = {
				{ 1,1,1,1,1,1,1,1,1,1 }, //0 x
				{ 1,0,0,0,0,0,0,0,0,1 }, //1
				{ 1,0,0,0,0,0,0,0,0,1 }, //2
				{ 1,0,0,0,0,0,0,0,0,1 }, //3
				{ 1,0,0,0,0,0,0,0,0,1 }, //4
				{ 1,0,0,0,0,0,0,0,0,1 }, //5
				{ 1,1,1,1,1,1,1,1,1,1 }  //6
			};


			// �}�b�v��ł̎�l���̉摜��ǂݍ��݁B�������ړ�����
			Image^ hero_mapchip = Image::FromFile("hero_dot.png ");


			Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image�^�Ő錾�B��������_��
			// e->Graphics->DrawImage(mapchip_image, 225 + 32, 140 + 32, 32, 32);



			// �}�b�v��`��

			for (int x = 0; x <= 9; ++x)
			{
				for (int y = 0; y <= 6; ++y)
				{
					switch (maptable[y][x])
					{
					case (0):
						mapchip_image = Image::FromFile("mapchip_grass.png ");
						break;

					case (1):
						mapchip_image = Image::FromFile("mapchip_wall.png ");
						break;
					}
					e->Graphics->DrawImage(mapchip_image, 225 + x * 32, 140 + y * 32, 32, 32);

				}
			}

			// ��l���̈ʒu��\��
			e->Graphics->DrawImage(hero_mapchip, 320 + (chx - saisyo_x) * 32, 270 + (chy - saisyo_y) * (32));

			// MessageBox::Show("�p�l������ \n" + chx.ToString() + "," + chy.ToString()); // �f�o�b�O�p���b�Z�[�W


		}


	}

	private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		// P�������ꂽ�� p_count ��1�A�b�v // �f�o�b�O�p
		if (e->KeyData == Keys::P)	{
			p_count = p_count + 1; // p�������񐔂̃J�E���g�ɐ����B
			panel1->Invalidate();
		}


		if (mode_scene == 1) { // �����I�[�v�j���O�V�[���Ȃ�

			// �������B selecting_menu �� 1 �ȏォ�� 3 �ȉ��ɂ���B
			if (selecting_menu > 3) {
				selecting_menu = 3;
			}

			if (selecting_menu < 1) {
				selecting_menu = 1;
			}


			// ���L�[�i�㉺�̂݁j�������ꂽ��J�[�\�����㉺�Ɉړ�
			if (e->KeyData == Keys::Up || e->KeyData == Keys::Down){
				switch (e->KeyData)	{ // �����ꂽ���L�[�ɉ����āA�ړ�����W����
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

				
				switch (selecting_menu) {  // �����ꂽ���L�[�ɉ����āA�ړ�����W����
					case 1:
						drawTalkString1 = "�u�͂��߂���v��I��";
						break;
					case 2:
						drawTalkString1 = "�u�Â�����v��I��";
						break;
					case 3:
						drawTalkString1 = "�u�����v��I��";
						break;
				}

				if (cursol_stop != 1) {
					panel1->Invalidate();
				}

			}

						
			if (e->KeyData == Keys::Z) { // Z�L�[�������ƃI�[�v�j���O��̉�ʂɈڍs

				switch (selecting_menu){ // �����ꂽ���L�[�ɉ����āA�ړ�����W����
					case 1:
						mode_scene = 2;
						menu_tate_on = 0;
						drawTalkString1 = "�Q�[�����ŏ�����J�n";
						drawTalkString2 = "���[�h�F" + mode_scene.ToString();
						break;
					case 2:
						drawTalkString1 = "�Z�[�u��ʂ��J���܂��i�H�����j";
						break;
					case 3:
						drawTalkString1 = "�Q�[�����I���܂�";
						Close();
						break;
					case 4:
						drawTalkString1 = "�ݒ��ʂł��i�H�����j";
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
					drawTalkString1 = "���l�u�����A�E�҂�A�悭�� ���Ă��ꂽ�BGT" + game_event1_end.ToString() ;
					drawTalkString2 = "���Ȃ��ɁA��100�A�������Ă����悤�B�v" + your_money.ToString() ;
					drawTalkString3 = "�i����{�^���������Ă��������jP" + p_count.ToString();;
					
					panel1->Invalidate();
					game_event1_end_dummuy = 1;
					key_nokori = 0;
					// e->KeyData = Keys::Escape;
				}


			if (game_event1_end == 1 && game_event2_end == 0 && key_nokori > 0 && e->KeyData == Keys::Z) {

				drawTalkString1 = "���Ȃ��͋�100����ɓ��ꂽ�BG_Fflag" + game_event1_end.ToString();
				drawTalkString2 = "�i����{�^���������Ă��������j";
				drawTalkString3 = "";
				panel1->Invalidate();

				your_money = your_money + 100;
				game_event2_end = 1;

				key_nokori = 0;

				//�����Ń��[�h�J�ڂ�����ʖځB�J�ڂ���ƁA�u��100����ɓ��ꂽ�v�̍s���\������Ȃ��Ȃ��Ă��܂��I
			}


			if (game_event2_end == 1 && key_nokori >0 && e->KeyData == Keys::Z) { // event2�̏I����ƁB
				key_nokori = 0;
				mode_scene = 3; //�����Ń��[�h�J�ڂ���ƁA�u��100����ɓ��ꂽ�v�̍s���\������Ȃ��Ȃ��Ă��܂��I
			}
								
			panel1->Invalidate();
			nin_i = nin_i + 1; // �����̃J�E���g�p�B
		}
		// MessageBox::Show("�L�[�����̏I���B"); // �f�o�b�O�p���b�Z�[�W




		if (mode_scene == 3 && key_nokori > 0) {

			int maptable[7][10] = {
				{ 1,1,1,1,1,1,1,1,1,1 }, //0 x
				{ 1,0,0,0,0,0,0,0,0,1 }, //1
				{ 1,0,0,0,0,0,0,0,0,1 }, //2
				{ 1,0,0,0,0,0,0,0,0,1 }, //3
				{ 1,0,0,0,0,0,0,0,0,1 }, //4
				{ 1,0,0,0,0,0,0,0,0,1 }, //5
				{ 1,1,1,1,1,1,1,1,1,1 }  //6
			};


			// �i�s��̍��W�Ɉꎞ�I�Ɏ�l���̍��W����
			desti_x = chx;
			desti_y = chy;


			// ���L�[�������ꂽ��ړ����胂�[�h�ɑJ��
			if (e->KeyData == Keys::Right || e->KeyData == Keys::Left
				|| e->KeyData == Keys::Up || e->KeyData == Keys::Down)
			{
				switch (e->KeyData)
				{
					// �����ꂽ���L�[�ɉ����āA�ړ���\��̍��W����
					case Keys::Right:
						desti_x = chx + 1;
						break;
					case Keys::Left:
						desti_x = chx - 1;
						break;
					case Keys::Up:
						desti_y = chy - 1;
						break;
					case Keys::Down:
						desti_y = chy + 1;
						break;
				}


				//	�ړ��ۂ̔���ƁA�ړ�����W�̍X�V
				if (desti_x >= 0 && desti_x < map_x_size && desti_y >= 0 && desti_y < map_y_size)
				{
					if (maptable[desti_y][desti_x] == 1) // �i�s�悪��
					{
						desti_x = chx; // �ړ���̔j��
						desti_y = chy;
					}
					else if (maptable[desti_y][desti_x] != 1) // �i�s��Ɉړ��\
					{
						chx = desti_x;
						chy = desti_y;
						panel1->Invalidate(FALSE);
					}			
				}

				
			}




		}



		key_nokori = 1;





	}
	
}

; }