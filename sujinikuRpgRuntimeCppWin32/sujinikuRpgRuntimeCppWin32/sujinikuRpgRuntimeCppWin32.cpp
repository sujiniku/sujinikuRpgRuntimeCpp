// sujinikuRpgRuntimeCppWin32.cpp: アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "sujinikuRpgRuntimeCppWin32.h"

#define MAX_LOADSTRING 100
#define MAX_LENGTH 256 // 要素数に注意 

// グローバル変数:
HINSTANCE hInst;                                // 現在のインターフェイス
WCHAR szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
WCHAR szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名


TCHAR p[MAX_LENGTH] = TEXT("はじめから");


static int p_count; //test

static int mode_scene = 1;
static int selecting_menu = 1;
static int menu_tate_on = 0;
static int cursol_stop;
static int your_money =0;
static int nin_i;


static TCHAR drawTalkString1[MAX_LENGTH] = TEXT("temp1"); // 会話欄の1行目
static TCHAR drawTalkString2[MAX_LENGTH] = TEXT("temp2"); // 会話欄の2行目
static TCHAR drawTalkString3[MAX_LENGTH] = TEXT("temp3"); // 会話欄の3行目


static int game_event1_end;
static int game_event2_end;

static int game_event1_end_dummuy;


static int key_nokori = 1;




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



int maptable[7][10] = {
	{ 1,1,1,1,1,1,1,1,1,1 }, //0 x
{ 1,0,0,0,0,0,0,0,0,1 }, //1
{ 1,0,0,0,0,0,0,0,0,1 }, //2
{ 1,0,0,0,0,0,0,0,0,1 }, //3
{ 1,0,0,0,0,0,0,0,0,1 }, //4
{ 1,0,0,0,0,0,0,0,0,1 }, //5
{ 1,1,1,1,1,1,1,1,1,1 }  //6
};







// このコード モジュールに含まれる関数の宣言を転送します:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。




    // グローバル文字列を初期化しています。
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SUJINIKURPGRUNTIMECPPWIN32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // アプリケーションの初期化を実行します:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SUJINIKURPGRUNTIMECPPWIN32));

    MSG msg;

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  関数: MyRegisterClass()
//
//  目的: ウィンドウ クラスを登録します。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SUJINIKURPGRUNTIMECPPWIN32));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SUJINIKURPGRUNTIMECPPWIN32);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   関数: InitInstance(HINSTANCE, int)
//
//   目的: インスタンス ハンドルを保存して、メイン ウィンドウを作成します。
//
//   コメント:
//
//        この関数で、グローバル変数でインスタンス ハンドルを保存し、
//        メイン プログラム ウィンドウを作成および表示します。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // グローバル変数にインスタンス処理を格納します。

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW ^WS_THICKFRAME,
      CW_USEDEFAULT, 0, 640,480 , nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  関数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的:    メイン ウィンドウのメッセージを処理します。
//
//  WM_COMMAND  - アプリケーション メニューの処理
//  WM_PAINT    - メイン ウィンドウの描画
//  WM_DESTROY  - 中止メッセージを表示して戻る
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 選択されたメニューの解析:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: HDC を使用する描画コードをここに追加してください...

			HPEN pen_ao;
			
			pen_ao = CreatePen (PS_SOLID, 0, RGB(210, 210, 255));
			SelectObject(hdc, pen_ao);


			HBRUSH ao_usui_1, ao_usui_2;
			ao_usui_1 = CreateSolidBrush(RGB(210, 210, 255));
			ao_usui_2 = (HBRUSH)SelectObject(hdc, ao_usui_1);
			Rectangle(hdc, 120, 150, 120+200, 150+200);


			HBRUSH brasi_buhin_1;
			brasi_buhin_1 = CreateSolidBrush(RGB(255, 180, 180));
			SelectObject(hdc, brasi_buhin_1);

			SetBkMode(hdc, TRANSPARENT);

			if (mode_scene == 1) {

				Rectangle(hdc, 150, 200+(selecting_menu -1)* 50 , 
				150 + 80, 200 + 20 + (selecting_menu - 1) * 50);
				lstrcpy(p, TEXT("はじめから"));
				TextOut(hdc, 150, 200, p, lstrlen(p));

				lstrcpy(p, TEXT("つづきから"));
				TextOut(hdc, 150, 250, p, lstrlen(p));

				lstrcpy(p, TEXT("おわる"));
				TextOut(hdc, 150, 300, p, lstrlen(p));

			}

			 
			if (mode_scene == 20) {
				HBRUSH siro1 = (HBRUSH)GetStockObject(WHITE_BRUSH);
				SelectObject(hdc, siro1);

				Rectangle(hdc, 0, 0,
					1000, 1000);

				ao_usui_2 = (HBRUSH)SelectObject(hdc, ao_usui_1);
				Rectangle(hdc, 50, 250,
					 50+ 500, 400 );

				lstrcpy(p, drawTalkString1);
				TextOut(hdc, 150, 250, p, lstrlen(p));

				lstrcpy(p, drawTalkString2);
				TextOut(hdc, 150, 300, p, lstrlen(p));

				lstrcpy(p, drawTalkString3);
				TextOut(hdc, 150, 350, p, lstrlen(p));
			}




			if (mode_scene == 30 ) {

				HBRUSH siro1 = (HBRUSH)GetStockObject(WHITE_BRUSH);
				SelectObject(hdc, siro1);

				Rectangle(hdc, 0, 0,
					1000, 1000);

				ao_usui_2 = (HBRUSH)SelectObject(hdc, ao_usui_1);
				Rectangle(hdc, 150, 250,
					50 + 500, 400);




				int maptable[7][10] = {
					{ 1,1,1,1,1,1,1,1,1,1 }, //0 x
				{ 1,0,0,0,0,0,0,0,0,1 }, //1
				{ 1,0,0,0,0,0,0,0,0,1 }, //2
				{ 1,0,0,0,0,0,0,0,0,1 }, //3
				{ 1,0,0,0,0,0,0,0,0,1 }, //4
				{ 1,0,0,0,0,0,0,0,0,1 }, //5
				{ 1,1,1,1,1,1,1,1,1,1 }  //6
				};


				static HDC hCDC;
				hCDC = CreateCompatibleDC(hdc);

				static HDC hMdc;
				HBITMAP hbmp;
		
				hbmp = (HBITMAP)LoadImage(NULL, TEXT("mudai.bmp"), IMAGE_BITMAP, 0, 0,
					LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				SelectObject(hCDC, hbmp);

				//BMP画像をファイルから読み込む
				hbmp = (HBITMAP)LoadImage(NULL, TEXT("mapchip_grass.bmp"), IMAGE_BITMAP, 0, 0,
					LR_LOADFROMFILE | LR_CREATEDIBSECTION);

				hMdc = CreateCompatibleDC(hdc);
	
				for (int x = 0; x <= 9; ++x)
				{
					for (int y = 0; y <= 6; ++y)
					{
						switch (maptable[y][x])
						{
						case (0):
							hbmp = (HBITMAP)LoadImage(NULL, TEXT("mapchip_grass.bmp"), IMAGE_BITMAP, 0, 0,
								LR_LOADFROMFILE | LR_CREATEDIBSECTION);
							break;

						case (1):
							hbmp = (HBITMAP)LoadImage(NULL, TEXT("mapchip_wall.bmp"), IMAGE_BITMAP, 0, 0,
								LR_LOADFROMFILE | LR_CREATEDIBSECTION);
							break;
						}
						SelectObject(hMdc, hbmp);
						BitBlt(hCDC, 225 + x * 32, 140 + y * 32, 32, 32, hMdc, 0, 0, SRCCOPY);
					}
				}

				//SelectObject(hdc, hbmp);
				BitBlt(hdc,0, 0, 600, 400, hCDC, 0, 0, SRCCOPY);
						
				DeleteDC(hCDC);
				DeleteDC(hMdc);
				DeleteObject(hbmp);


				//BMP画像をファイルから読み込む
				hbmp = (HBITMAP)LoadImage(NULL, TEXT("hero_dot.bmp"), IMAGE_BITMAP, 0, 0,
					LR_LOADFROMFILE | LR_CREATEDIBSECTION);
				
				hMdc = CreateCompatibleDC(hdc);
				SelectObject(hMdc, hbmp); // これを消すと、主人公ドットが表示されない。

				BitBlt(hdc, 320 + (chx - saisyo_x) * 32, 270 + (chy - saisyo_y) * (32), 170, 180, hMdc, 0, 0, SRCCOPY);
			//	StretchBlt(hdc, 10, 210, 200, 50, hMdc, 40, 10, 100, 100, SRCCOPY);

				DeleteDC(hMdc);
				DeleteObject(hbmp);


			}


            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'Z':
			//MessageBox(NULL, TEXT("Zが押されました。"), TEXT("キーテスト"), MB_OK);

			if (mode_scene == 1) {

				if (selecting_menu == 1)
				{
					MessageBox(NULL, TEXT("ゲームを開始。"), TEXT("キーテスト"), MB_OK);
					mode_scene = 20;

					chx = saisyo_x;
					chy = saisyo_y;


					lstrcpy(drawTalkString1, TEXT("王様「おお、勇者よ、よくぞ 来てくれた。"));
					lstrcpy(drawTalkString2, TEXT("そなたに、金100、さずけてあげよう。"));
					lstrcpy(drawTalkString3, TEXT("（決定ボタンを押してください）"));

					InvalidateRect(hWnd, NULL, TRUE);
					UpdateWindow(hWnd);

				}

				if (selecting_menu == 2)
				{
					MessageBox(NULL, TEXT("ゲームをロード。"), TEXT("キーテスト"), MB_OK);
				}

				if (selecting_menu == 3)
				{
					PostQuitMessage(0);
				}
			}

			if (mode_scene == 20 ) {
				if (game_event1_end != 1) {

					game_event1_end = 1;

					lstrcpy(drawTalkString1, TEXT("王様「おお、勇者よ、よくぞ 来てくれた。"));
					lstrcpy(drawTalkString2, TEXT("そなたに、金100、さずけてあげよう。"));
					lstrcpy(drawTalkString3, TEXT("（決定ボタンを押してください）"));

					key_nokori = 0;
				}

				if (game_event1_end == 1 && game_event2_end == 0 && key_nokori > 0 ) {

					//MessageBox(NULL, TEXT("あなたは金100を手に入れた。"), TEXT("キーテスト"), MB_OK);

					lstrcpy(drawTalkString1, TEXT("あなたは金100を手に入れた。"));
					lstrcpy(drawTalkString2, TEXT("（決定ボタンを押してください）"));
					lstrcpy(drawTalkString3, TEXT(""));

					InvalidateRect(hWnd, NULL, TRUE);
					UpdateWindow(hWnd);

					your_money = your_money + 100;
					game_event2_end = 1;

					key_nokori = 0;

					//ここでモード遷移したら駄目。遷移すると、「金100を手に入れた」の行が表示されなくなってしまう！
				}


				if (game_event2_end == 1 && key_nokori >0 ) { // event2の終了作業。
					key_nokori = 0;
					mode_scene = 30; //ここでモード遷移すると、「金100を手に入れた」の行が表示されなくなってしまう！
				
					//MessageBox(NULL, TEXT("これからmode30に移動する。"), TEXT("キーテスト"), MB_OK);




					InvalidateRect(hWnd, NULL, TRUE);
					UpdateWindow(hWnd);
				}




			}


			key_nokori = 1;
			break;
		case 'X':
			MessageBox(NULL, TEXT("Xが押されました。"), TEXT("キーテスト"), MB_OK);
			break;
		



		case VK_UP:
			// MessageBox(NULL, TEXT("↑が押されました。"), TEXT("キーテスト"), MB_OK);
			
			if (mode_scene == 1) {
				selecting_menu = selecting_menu - 1;

				// 初期化。 selecting_menu は 1 以上から 3 以下にする。
				if (selecting_menu > 3) {
					selecting_menu = 3;
				}

				if (selecting_menu < 1) {
					selecting_menu = 1;
				}

				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				break;
			}

			if (mode_scene == 30){
				desti_y = chy - 1;

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
					}
				}

				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				break;
			}



		case VK_DOWN:
			if (mode_scene == 1) {
				// MessageBox(NULL, TEXT("↓が押されました。"), TEXT("キーテスト"), MB_OK);
				selecting_menu = selecting_menu + 1;

				// 初期化。 selecting_menu は 1 以上から 3 以下にする。
		
				if (selecting_menu > 3) {			
					selecting_menu = 3;
				}

				if (selecting_menu < 1) {				
					selecting_menu = 1;
				}

				InvalidateRect(hWnd, NULL, TRUE);			
				UpdateWindow(hWnd);
				break;		
			}

			if (mode_scene == 30) {
				desti_y = chy + 1;
				InvalidateRect(hWnd, NULL, TRUE);

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
					}
				}

				UpdateWindow(hWnd);
				break;
			}


		case VK_RIGHT:
			if (mode_scene == 30) {
				desti_x = chx + 1;

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
					}
				}

				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				break;
			}


		case VK_LEFT:
			if (mode_scene == 30) {
				desti_x = chx - 1;

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
					}
				}

				InvalidateRect(hWnd, NULL, TRUE);
				UpdateWindow(hWnd);
				break;
			}




		}
		return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
