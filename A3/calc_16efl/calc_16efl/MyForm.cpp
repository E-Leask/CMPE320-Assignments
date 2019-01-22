#include "MyForm.h"
#include "windows.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;

typedef bool(CALLBACK* LPFNDLLFUNC1)();
HINSTANCE hDLL;               // Handle to DLL
LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
bool uReturnVal;
[STAThread]
int main(array <String^> ^ args) {
	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);
	//Form form;
	Form^ form = gcnew Form();
	Application::Run(form);

	//Insert DLL Info
	HINSTANCE hDll;

	hDll = LoadLibrary(L"GUI_DLL_16efl");
	if (NULL != hDll) {
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "Fraction");
		if (!lpfnDllFunc1)
		{
			// handle the error
			FreeLibrary(hDLL);
			return 1;
		}
		else
		{
			// call the function
			uReturnVal = lpfnDllFunc1();
			return 0;
		}
		return 0;


	}
	else{
		return 1;
	}
}

