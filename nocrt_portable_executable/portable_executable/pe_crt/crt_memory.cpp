#include "crt_memory.hpp"

#include <intrin.h>

void portable_executable::pe_crt::memcpy(void* destination, const void* source, pe_crt::size_t size)
{
	__movsb(static_cast<pe_crt::uint8_t*>(destination), static_cast<const pe_crt::uint8_t*>(source), size);
}

void portable_executable::pe_crt::memset(void* destination, pe_crt::uint8_t value, pe_crt::size_t size)
{
	__stosb(static_cast<pe_crt::uint8_t*>(destination), value, size);
}