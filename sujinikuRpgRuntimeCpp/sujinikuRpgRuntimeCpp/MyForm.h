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

		static int mode_scene = 1;
		int selecting_menu = 1;
		int menu_tate_on = 1;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//

			// グローバル変数のつもり


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
		SolidBrush^ blueBrush = gcnew SolidBrush(Color::Azure); // コマンド背景色
		// Azureは色名。クラウドとは無関係。

		SolidBrush^ pinkBrush = gcnew SolidBrush(Color::Pink); // カーソル色。

		int x3 = 145;
		int y3 = 140;
		int width3 = 150 ; //110
		int height3 = 150;

		e->Graphics->FillRectangle(blueBrush, x3, y3, width3, height3);


		// 選択メニュー色の表示は背景画像に上書きとして処理。
		int x2 = 145;
		int y2 = 140+50 *( selecting_menu - 1 );
		int width2 = 22*5; //110
		int height2 = 40;

		if (menu_tate_on == 1){
		
			// Fill rectangle to screen.
			e->Graphics->FillRectangle(pinkBrush, x2, y2, width2, height2);
		}









		// 共通設定
		// String^ CursolString = "⊃"; // カーソルの代用

		// フォント（MSゴシックやArialなど）とブラシ（線太さや色など指定）のオブジェクト作成。
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);


		// 以上、全画面の共通設定


		if (mode_scene == 1) { // もしオープニングなら・・・。

			// 文字列を描くためのオブジェクト作成。
			String^ drawString1 = "はじめから";

			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawPoint1 = PointF(150.0F, 150.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawString1, drawFont, drawBrush, drawPoint1);


			// Image^ mapchip_image = Image::FromFile("mapchip_grass.png "); // Image型で宣言。消したらダメ
			// e->Graphics->DrawImage (mapchip_image, 225 + 32, 140 + 32, 32, 32);



			// 文字列を描くためのオブジェクト作成。
			String^ drawString2 = "つづきから";



			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawPoint2 = PointF(150.0F, 200.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawString2, drawFont, drawBrush, drawPoint2);



			// 文字列を描くためのオブジェクト作成。
			String^ drawString3 = "おわり";



			// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
			PointF drawPoint3 = PointF(150.0F, 250.0F); // Fは浮動小数点

			// 実際に文字列を出力する命令。
			e->Graphics->DrawString(drawString3, drawFont, drawBrush, drawPoint3);




			// 文字列を描くためのオブジェクト作成。



			if (selecting_menu == 1) {

				drawString4 = "「はじめから」を選択中";
				// drawString1::Backcolor = Pink;

			}
			else if (selecting_menu == 2) {

				drawString4 = "「つづきから」を選択中";
			}
			else if (selecting_menu == 3) {

				drawString4 = "「おわる」を選択中";
			}
			else {
				drawString4 = "「おわる」を選択中";
			}

		}


		if (mode_scene == 2) { // もしNew Gameなら・・・。
			drawString4 = "王様「おお、勇者よ、よくぞ 来てくれた。」";


		}



		// 出力位置の座標オブジェクトを作成。座標150,150に文字画像を貼り付ける予定。
		PointF drawPoint4 = PointF(100.0F, 300.0F); // Fは浮動小数点

		// 実際に文字列を出力する命令。
		e->Graphics->DrawString(drawString4, drawFont, drawBrush, drawPoint4);


		







	}

	private: System::Void panel1_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {

	}



	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {




		if (mode_scene == 1){ // もしオープニングシーンなら

		// selecting_menu は 1 以上から 3 以下にする。
		if (selecting_menu > 3) {
			selecting_menu = 3;
		}

		if (selecting_menu < 1) {
			selecting_menu = 1;
		}


		// 矢印キー（上下のみ）が押されたらカーソルを上下に移動
		if ( e->KeyData == Keys::Up || e->KeyData == Keys::Down)
		{
			switch (e->KeyData)
			{
				// 押された矢印キーに応じて、移動先座標を代入

			case Keys::Up:
				// MessageBox::Show("上キーが押されました。");
				selecting_menu = selecting_menu - 1;
				break;
			case Keys::Down:
				// MessageBox::Show("下キーが押されました。");
				selecting_menu = selecting_menu + 1;
				break;
			}

			
			if (selecting_menu > 3) { // 3以上は3にする
				selecting_menu = 3;
			}
			else if (selecting_menu < 1) { // 1以下は1にする
				selecting_menu = 1;
			}






			if (selecting_menu == 1) {

				String^ drawString4 = "「はじめから」を選択中";



			}
			else if (selecting_menu == 2) {

				String^ drawString4 = "「つづきから」を選択中";
			}
			else if (selecting_menu == 3) {

				String^ drawString4 = "「おわる」を選択中";
			}
			else {
				String^ drawString4 = "「おわる」を選択中";
			}


			panel1->Invalidate();

		}// オープニング後の画面に移行
		if (e->KeyData == Keys::Z )
		{
			if (selecting_menu == 1) {
				mode_scene = 2;
				menu_tate_on = 0;
				drawString4 = "ゲームを最初から開始";
			}
			else if (selecting_menu == 2) {

				drawString4 = "セーブ画面を開きます（工事中）";
			}
			else if (selecting_menu == 3) {
				drawString4 = "ゲームを終わります";
				Close();
			}
			else {
				drawString4 = "ゲームを終わります";
			}
		}


		if (mode_scene == 2) {
			String^ drawString4 = "王様「おお、勇者よ、よくぞ 来てくれた。」";
			
			panel1->Invalidate();
		}
			// MessageBox::Show("キー処理の終了。"); // デバッグ用メッセージ














		}
	}
	}

; }