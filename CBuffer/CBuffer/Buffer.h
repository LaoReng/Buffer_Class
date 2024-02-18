#pragma once
#include <string>

#ifdef _MSC_VER
// Windows
#include <Windows.h>
#elif __GNUC__
// Linux
typedef unsigned char BYTE;
#else
// Other
typedef unsigned char BYTE;
#endif // _MSC_VER


class Buffer
	:public std::string
{
public:
	Buffer()
		:std::string()
	{}
	Buffer(const char* str)
		:std::string(str)
	{}
	Buffer(const Buffer& buf)
		:std::string(buf.c_str())
	{}
	Buffer& operator=(const Buffer& buf) {
		if (this != &buf) {
			std::string::operator=(buf.c_str());
		}
		return *this;
	}
	Buffer& operator=(const char* str) {
		std::string::operator=(str);
		return *this;
	}
	Buffer& operator=(const std::string& str) {
		std::string::operator=(str);
		return *this;
	}
	operator char* () {
		return (char*)c_str();
	}
	operator const char* () const {
		return c_str();
	}
	operator BYTE* () {
		return (BYTE*)c_str();
	}
	operator const BYTE* ()const {
		return (const BYTE*)c_str();
	}
};

