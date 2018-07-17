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
	/// MyForm の概要
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

		static String^ drawTalkString1 = "temp1"; // 会話欄の1行目
		static String^ drawTalkString2 = "temp2"; // 会話欄の2行目
		static String^ drawTalkString3 = "temp3"; // 会話欄の3行目


		static int game_event1_end ;
		static int game_event2_end ;

		static int game_event1_end_dummuy ;


		static int key_nokori ;




		static int chx;
		static int chy;

		static int saisyo_x = 3;
		static int saisyo_y = 4;

		// マップのサイズの変数
		static int map_x_size = 10;
		static int map_y_size = 7;



		// 進行先の壁判定のアルゴリズム用の変数
		static int desti_x; // 進行先の壁判定のためのx座標変数
		static int desti_y; // 進行先の壁判定のためのx座標変数


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//

			// グローバル変数のつもり



			int p_count = 0; //test

			mode_scene = 1;
			selecting_menu = 1;
			menu_tate_on = 1;
			cursol_stop = 0;
			your_money = 0;
			nin_i = 0;

			String^ drawTalkString1 = "temp1"; // 会話欄の1行目
			String^ drawTalkString2 = "temp2"; // 会話欄の2行目
			String^ drawTalkString3 = "temp3"; // 会話欄の3行目


			game_event1_end = 0;
			game_event2_end = 0;

			game_event1_end_dummuy = 0;


			static int key_nokori = 0;



			chx = saisyo_x;
			chy = saisyo_y;



		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
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
		SolidBrush^ blueBrush = gcnew SolidBrush(Color::Azure); // コマンド背景色
		// Azureは色名。クラウドとは無関係。

		SolidBrush^ pinkBrush = gcnew SolidBrush(Color::Pink); // カーソル色。

		// OPコマンドメニューウィンドウ（青色の背景色）の描画など
		if (mode_scene == 1) {
			int OPmenuWindow_x = 145;
			int OPmenuWindow_y = 140;
			int OPmenuWindow_width = 150;
			int OPmenuWindow_height = 150;

			e->Graphics->FillRectangle(blueBrush, OPmenuWindow_x, OPmenuWindow_y, OPmenuWindow_width, OPmenuWindow_height);
		}

		// 選択メニューのカーソル色の表示は背景画像に上書きとして処理。
		if (menu_tate_on == 1) {
			int Cursol_x = 145;
			int Cursol_y = 140 + 50 * (selecting_menu - 1);
			int Cursol_width = 22 * 5; // 110
			int Cursol_height = 40;
			
			// Fill rectangle to screen.
			e->Graphics->FillRectangle(pinkBrush, Cursol_x, Cursol_y, Cursol_width, Cursol_height);
		}


		// 共通設定
		// String^ CursolString = "⊃"; // カーソルの代用 // 没になった案。リサイクルするかもしれないので残しとく。

		// フォント（MSゴシックやArialなど）とブラシ（線太さや色など指定）のオブジェクト作成。
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);


		// 以上、全画面の共通設定


		if (mode_scene == 1) { // もしオープニングなら・・・。 // switch文には、しない。長いと、編集しづらくなるので。
														// Visual C++ の場合、Switich文だとローカル変数が使いづらくなる。
			// 文字列を描くためのオブジェクト作成。
			String^ drawOP_MenuString1 = "はじめから";

			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawOP_MenuPoint1 = PointF(150.0F, 150.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawOP_MenuString1, drawFont, drawBrush, drawOP_MenuPoint1);
			

			// 文字列"つづきから"を描くためのオブジェクト。
			String^ drawOP_MenuString2 = "つづきから";
			PointF drawOP_MenuPoint2 = PointF(150.0F, 200.0F); // Fは浮動小数点
			e->Graphics->DrawString(drawOP_MenuString2, drawFont, drawBrush, drawOP_MenuPoint2);
			

			// 文字列"おわり"を描くためのオブジェクト。
			String^ drawOP_MenuString3 = "おわり";
			PointF drawOP_MenuPoint3 = PointF(150.0F, 250.0F); // Fは浮動小数点
			e->Graphics->DrawString(drawOP_MenuString3, drawFont, drawBrush, drawOP_MenuPoint3);


			switch (selecting_menu)	{ // 押された矢印キーに応じて、選択中の内容を表示座標を代入
				case 1:
					drawTalkString1 = "「はじめから」を選択中" + p_count.ToString();
					// drawOP_MenuString1::Backcolor = Pink;
					break;
				case 2:
					drawTalkString1 = "「つづきから」を選択中" + p_count.ToString();
					break;
				case 3:
					drawTalkString1 = "「おわる」を選択中" + p_count.ToString();
					break;
			}

			
			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawDestination_OP = PointF(100.0F, 300.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawTalkString1, drawFont, drawBrush, drawDestination_OP);

		}


		else if (mode_scene == 2) { // もし「はじめから」なら・・・。
			
			Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image型で宣言。消したらダメ
			e->Graphics->DrawImage (mapchip_image, 225 + 32, 140 + 32, 32, 32);


			int messageWindow_x = 80;
			int messageWindow_y = 280;
			int messageWindow_width = 410;
			int messageWindow_height = 150;

			e->Graphics->FillRectangle(blueBrush, messageWindow_x, messageWindow_y, 
				messageWindow_width, messageWindow_height);

			
			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawTalkLine1_Point = PointF(100.0F, 300.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawTalkString1, drawFont, drawBrush, drawTalkLine1_Point);


			PointF drawTalkLine2_Point = PointF(100.0F, 350.0F); // Fは浮動小数点
			e->Graphics->DrawString(drawTalkString2, drawFont, drawBrush, drawTalkLine2_Point);

			PointF drawTalkLine3_Point = PointF(100.0F, 390.0F); // Fは浮動小数点
			e->Graphics->DrawString(drawTalkString3, drawFont, drawBrush, drawTalkLine3_Point);

		}

		
		if (mode_scene == 3) { // マップ移動モード

			// マップのデータ // [y.x]
			int maptable[7][10] = {
				{ 1,1,1,1,1,1,1,1,1,1 }, //0 x
				{ 1,0,0,0,0,0,0,0,0,1 }, //1
				{ 1,0,0,0,0,0,0,0,0,1 }, //2
				{ 1,0,0,0,0,0,0,0,0,1 }, //3
				{ 1,0,0,0,0,0,0,0,0,1 }, //4
				{ 1,0,0,0,0,0,0,0,0,1 }, //5
				{ 1,1,1,1,1,1,1,1,1,1 }  //6
			};


			// マップ上での主人公の画像を読み込み。こいつが移動する
			Image^ hero_mapchip = Image::FromFile("hero_dot.png ");


			Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image型で宣言。消したらダメ
			// e->Graphics->DrawImage(mapchip_image, 225 + 32, 140 + 32, 32, 32);



			// マップを描画

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

			// 主人公の位置を表示
			e->Graphics->DrawImage(hero_mapchip, 320 + (chx - saisyo_x) * 32, 270 + (chy - saisyo_y) * (32));

			// MessageBox::Show("パネル内部 \n" + chx.ToString() + "," + chy.ToString()); // デバッグ用メッセージ


		}


	}

	private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		// Pが押されたら p_count を1アップ // デバッグ用
		if (e->KeyData == Keys::P)	{
			p_count = p_count + 1; // p押した回数のカウントに成功。
			panel1->Invalidate();
		}


		if (mode_scene == 1) { // もしオープニングシーンなら

			// 初期化。 selecting_menu は 1 以上から 3 以下にする。
			if (selecting_menu > 3) {
				selecting_menu = 3;
			}

			if (selecting_menu < 1) {
				selecting_menu = 1;
			}


			// 矢印キー（上下のみ）が押されたらカーソルを上下に移動
			if (e->KeyData == Keys::Up || e->KeyData == Keys::Down){
				switch (e->KeyData)	{ // 押された矢印キーに応じて、移動先座標を代入
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


				if (selecting_menu > 3) { // 3以上は3にする
					selecting_menu = 3;
					cursol_stop = 1;
				}
				else if (selecting_menu < 1) { // 1以下は1にする
					selecting_menu = 1;
					cursol_stop = 1;
				}

				
				switch (selecting_menu) {  // 押された矢印キーに応じて、移動先座標を代入
					case 1:
						drawTalkString1 = "「はじめから」を選択中";
						break;
					case 2:
						drawTalkString1 = "「つづきから」を選択中";
						break;
					case 3:
						drawTalkString1 = "「おわる」を選択中";
						break;
				}

				if (cursol_stop != 1) {
					panel1->Invalidate();
				}

			}

						
			if (e->KeyData == Keys::Z) { // Zキーを押すとオープニング後の画面に移行

				switch (selecting_menu){ // 押された矢印キーに応じて、移動先座標を代入
					case 1:
						mode_scene = 2;
						menu_tate_on = 0;
						drawTalkString1 = "ゲームを最初から開始";
						drawTalkString2 = "モード：" + mode_scene.ToString();
						break;
					case 2:
						drawTalkString1 = "セーブ画面を開きます（工事中）";
						break;
					case 3:
						drawTalkString1 = "ゲームを終わります";
						Close();
						break;
					case 4:
						drawTalkString1 = "設定画面です（工事中）";
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
					drawTalkString1 = "王様「おお、勇者よ、よくぞ 来てくれた。GT" + game_event1_end.ToString() ;
					drawTalkString2 = "そなたに、金100、さずけてあげよう。」" + your_money.ToString() ;
					drawTalkString3 = "（決定ボタンを押してください）P" + p_count.ToString();;
					
					panel1->Invalidate();
					game_event1_end_dummuy = 1;
					key_nokori = 0;
					// e->KeyData = Keys::Escape;
				}


			if (game_event1_end == 1 && game_event2_end == 0 && key_nokori > 0 && e->KeyData == Keys::Z) {

				drawTalkString1 = "あなたは金100を手に入れた。G_Fflag" + game_event1_end.ToString();
				drawTalkString2 = "（決定ボタンを押してください）";
				drawTalkString3 = "";
				panel1->Invalidate();

				your_money = your_money + 100;
				game_event2_end = 1;

				key_nokori = 0;

				//ここでモード遷移したら駄目。遷移すると、「金100を手に入れた」の行が表示されなくなってしまう！
			}


			if (game_event2_end == 1 && key_nokori >0 && e->KeyData == Keys::Z) { // event2の終了作業。
				key_nokori = 0;
				mode_scene = 3; //ここでモード遷移すると、「金100を手に入れた」の行が表示されなくなってしまう！
			}
								
			panel1->Invalidate();
			nin_i = nin_i + 1; // 何かのカウント用。
		}
		// MessageBox::Show("キー処理の終了。"); // デバッグ用メッセージ




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


			// 進行先の座標に一時的に主人公の座標を代入
			desti_x = chx;
			desti_y = chy;


			// 矢印キーが押されたら移動判定モードに遷移
			if (e->KeyData == Keys::Right || e->KeyData == Keys::Left
				|| e->KeyData == Keys::Up || e->KeyData == Keys::Down)
			{
				switch (e->KeyData)
				{
					// 押された矢印キーに応じて、移動先予定の座標を代入
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


				//	移動可否の判定と、移動先座標の更新
				if (desti_x >= 0 && desti_x < map_x_size && desti_y >= 0 && desti_y < map_y_size)
				{
					if (maptable[desti_y][desti_x] == 1) // 進行先が壁
					{
						desti_x = chx; // 移動先の破棄
						desti_y = chy;
					}
					else if (maptable[desti_y][desti_x] != 1) // 進行先に移動可能
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