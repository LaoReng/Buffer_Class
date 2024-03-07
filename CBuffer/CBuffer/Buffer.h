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

// 缓冲区类
class Buffer
	:public std::string
{
public:
	Buffer(size_t size = 0)
		:std::string(size, '\0')
	{}
	Buffer(void* data, size_t size)
		:std::string(size, '\0')
	{
		if (data != NULL) {
			memcpy((void*)c_str(), data, size);
		}
	}
	Buffer(const char* str)
		:std::string(str)
	{}
	Buffer(const Buffer& buf)
		:std::string(buf.c_str())
	{}
	virtual ~Buffer() {
		clear();
		std::string::~basic_string();
	}
	// 设置缓冲区数据
	void SetData(const void* data, size_t size) {
		clear();
		resize(size);
		if (data != NULL) {
			memcpy((char*)c_str(), data, size);
		}
	}
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

