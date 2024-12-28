#include <Windows.h>

#include "portable_executable/image.hpp"

int main()
{
	HMODULE ntdll = LoadLibrary(L"ntdll");

	if (!ntdll)
	{
		return EXIT_FAILURE;
	}

	auto in_memory_image = reinterpret_cast<const portable_executable::image_t*>(ntdll);

	if (!in_memory_image)
	{
		return EXIT_FAILURE;
	}

	portable_executable::pe_crt::uint8_t* nt_shutdown_system = in_memory_image->find_export("NtShutdownSystem");

	return EXIT_SUCCESS;
}