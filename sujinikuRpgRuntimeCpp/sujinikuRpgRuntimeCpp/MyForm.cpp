#include "MyForm.h"

#include <windows.h>

using namespace sujinikuRpgRuntimeCpp;

[STAThreadAttribute]
int main() {
	Application::Run(gcnew MyForm());

	MessageBox::Show("�Q�[�����I�����Ă��܂��E�E�E");
	return 0;
} 