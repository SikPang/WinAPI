#pragma once

#include <map>
#include <string>
#include <Windows.h>

namespace ks
{
	// 추상 클래스
	class Resource
	{
	private:
		std::wstring	key;
		std::wstring	path;

	public:
		Resource();
		virtual ~Resource();

	public:
		// 순수 가상 함수
		virtual HRESULT		Load(const std::wstring& path) = 0;
		const std::wstring&	GetKey() { return key; }
		const std::wstring& GetPath() { return path; }
		void				SetKey(std::wstring key) { this->key = key; }
		void				SetPath(std::wstring key) { this->path = path; }
	};
}