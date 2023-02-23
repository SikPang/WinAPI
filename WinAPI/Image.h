#pragma once
#include "Resource.h"


namespace ks
{
	class Image : public Resource
	{
	private:
		HBITMAP	bitmap;
		HDC		hdc;
		UINT	width;
		UINT	height;

	public:
		Image();
		~Image();

	public:
		HRESULT		Load(const std::wstring& path) override;
	};
}
