#include "Image.h"
#include "Application.h"
#include "ks_Resources.h"

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

	Image* Image::Create(const std::wstring& name, UINT width, UINT height)
	{
		if (width == 0 || height == 0)
			return nullptr;

		Image* image = Resources::Find<Image>(name);
		if (image != nullptr)
			return image;

		image = new Image();
		HDC mainHDC = application.GetHdc();

		image->bitmap = CreateCompatibleBitmap(mainHDC, width, height);
		image->hdc = CreateCompatibleDC(mainHDC);
		image->width = width;
		image->height = height;
		image->SetKey(name);
		
		Resources::Insert<Image>(name, image);

		DeleteObject((HBITMAP)SelectObject(image->hdc, image->bitmap));

		return image;
	}
}