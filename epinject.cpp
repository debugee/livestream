#include <windows.h>
#include <Shlwapi.h>
#include <tchar.h>
#include "injectlib.h"
#include "charset.h"

int wmain(int argc, const wchar_t **argv)
{
#ifndef NDEBUG
	MessageBox(NULL, _T("epinject"), NULL, MB_OK);
#endif
	if (argc != 3) {
		printf("epinject.exe app_full_path dll_full_path\n");
		return 0;
	}
	std::string app;
	std::string dll;
	charset::u16ToU8Str(argv[1], app);
	charset::u16ToU8Str(argv[2], dll);
	epInjectDll(app,
		"",
		"",
		dll);

    return 0;
}

