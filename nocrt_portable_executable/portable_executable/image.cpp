#include "image.hpp"

#include "pe_crt/crt_string.hpp"

portable_executable::dos_header_t* portable_executable::image_t::dos_header()
{
	return &this->m_dos_header;
}

const portable_executable::dos_header_t* portable_executable::image_t::dos_header() const
{
	return &this->m_dos_header;
}

portable_executable::nt_headers_t* portable_executable::image_t::nt_headers()
{
	return this->dos_header()->nt_headers();
}

const portable_executable::nt_headers_t* portable_executable::image_t::nt_headers() const
{
	return this->dos_header()->nt_headers();
}

portable_executable::section_header_t* portable_executable::image_t::find_section(const char* name)
{
	for (auto& section : this->sections())
	{
		if (pe_crt::strstr(section.name, name))
		{
			return &section;
		}
	}

	return nullptr;
}

const portable_executable::section_header_t* portable_executable::image_t::find_section(const char* name) const
{
	for (const auto& section : this->sections())
	{
		if (pe_crt::strstr(section.name, name))
		{
			return &section;
		}
	}

	return nullptr;
}

portable_executable::pe_crt::uint8_t* portable_executable::image_t::find_export(const char* name) const
{
	for (const auto& [export_name, export_address] : this->exports())
	{
		if (pe_crt::strstr(export_name, name))
		{
			return export_address;
		}
	}

	return nullptr;
}