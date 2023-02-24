#include "Image.h"
#include "Application.h"

namespace ks
{
	Image::Image()
		: bitmap(NULL)
		, hdc(NULL)
		, width(0)
		, height(0)
	{

	}

	Image::~Image()
	{
	
	}

	HRESULT Image::Load(const std::wstring& path)
	{
		bitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (bitmap == nullptr)
			return E_FAIL;

		BITMAP bitInfo = {};

		// 얻어온 bitmap의 정보를 bitInfo에 복사함 (HBITMAP -> BITMAP)
		GetObject(bitmap, sizeof(BITMAP), &bitInfo);

		width = bitInfo.bmWidth;
		height = bitInfo.bmHeight;

		HDC mainDC = application.GetHdc();
		hdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(hdc, bitmap);
		DeleteObject(oldBitmap);

		return S_OK;
	}
}