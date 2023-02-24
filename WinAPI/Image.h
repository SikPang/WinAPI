#pragma once
#include "ks_Resource.h"


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
		HRESULT	Load(const std::wstring& path) override;
		HBITMAP	GetBitmap() { return bitmap; }
		HDC		GetHdc() { return hdc; }
		UINT	GetWitdh() { return width; }
		UINT	GetHeight() { return height; }
	};
}
