#include "MyForm.h"

#include <windows.h>

using namespace sujinikuRpgRuntimeCpp;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew MyForm());

	MessageBox::Show("ゲームを終了しています・・・");
	return 0;
} 