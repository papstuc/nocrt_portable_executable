#include <Windows.h>

#include "portable_executable/image.hpp"

int main()
{
	HMODULE user32 = LoadLibrary(L"user32");

	if (!user32)
	{
		return EXIT_FAILURE;
	}

	auto in_memory_image = reinterpret_cast<const portable_executable::image_t*>(user32);

	if (!in_memory_image)
	{
		return EXIT_FAILURE;
	}

	// user32!GetWindowBorders
	portable_executable::pe_crt::uint8_t* pattern = in_memory_image->signature_scan("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 41 8B F1");

	if (!pattern)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}