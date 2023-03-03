#include <map>
#include <vector>
#include <filesystem>
#include "Image.h"
#include "Animator.h"
#include "ks_Resources.h"

namespace ks
{
	Animator::Animator()
		: Component(e_ComponentType::Animator)
		, activeAnimation(nullptr)
		, spriteSheet(nullptr)
		, isLoop(false)
	{

	}

	Animator::~Animator()
	{
		for (auto &animation : animations)
		{
			delete animation.second;
			animation.second = nullptr;
		}
	}
	
	void Animator::Initialize()
	{
	
	}
	
	void Animator::Update()
	{
		if (activeAnimation)
		{
			activeAnimation->Update();

			if (isLoop && activeAnimation->IsComplete())
			{
				activeAnimation->Reset();
			}
		}
	}
	
	void Animator::Render(HDC hdc)
	{
		if (activeAnimation)
		{
			activeAnimation->Render(hdc);
		}
	}
	
	void Animator::Release()
	{
	
	}

	void Animator::CreateAnimation(const std::wstring& name, Image* sheet, Vector2 leftTop, UINT col, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		Animation* newAnimation = FindAnimation(name);

		if (newAnimation != nullptr)
			return;

		newAnimation = new Animation();
		newAnimation->Create(sheet, leftTop, col, row, spriteLength, offset, duration);
		newAnimation->SetName(name);
		newAnimation->SetAnimator(this);

		animations.insert(std::make_pair(name, newAnimation));
	}

	void Animator::CreateAnimations(const std::wstring& path, Vector2 offset, float duration)
	{
		UINT	width = 0;
		UINT	height = 0;
		UINT	fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<Image*> images = {};
		for (auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = path + L"\\" + fileName;

			if (p.path().extension() == L".png")
				continue;

			Image* image = Resources::Load<Image>(fileName, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
				width = image->GetWidth();
			if (height < image->GetHeight())
				height = image->GetHeight();
			++fileCount;
		}

		std::wstring key = (std::wstring)fs.parent_path().filename() + (std::wstring)fs.filename();

		spriteSheet = Image::Create(key, width * fileCount, height);

		int index = 0;
		for (Image* image : images)
		{
			int centerX = (width - image->GetWidth()) / 2;
			int centerY = height - image->GetHeight();

			BitBlt(spriteSheet->GetHdc(), width * index + centerX, centerY, image->GetWidth(), image->GetHeight(), image->GetHdc(), 0, 0, SRCCOPY);
			++index;
		}

		CreateAnimation(key, spriteSheet, Vector2::Zero, index, 1, index, offset, duration);
	}

	void Animator::Play(const std::wstring& name, bool loop)
	{
		activeAnimation = FindAnimation(name);
		isLoop = loop;
	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter = animations.find(name);

		if (iter == animations.end())
			return nullptr;
		else
			return iter->second;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		return nullptr;
	}
}