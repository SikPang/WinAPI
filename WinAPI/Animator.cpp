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
		for (auto& animation : animations)
		{
			delete animation.second;
			animation.second = nullptr;
		}

		for (auto& events : this->events)
		{
			delete events.second;
			events.second = nullptr;
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

			if (activeAnimation->IsComplete())
			{
				Animator::Events* events = FindEvents(activeAnimation->GetName());
				if (events != nullptr)
					events->completeEvent();

				if (isLoop)
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
		newAnimation->SetAnimationName(name);
		newAnimation->SetAnimator(this);

		animations.insert(std::make_pair(name, newAnimation));
		Events* events = new Events();
		this->events.insert(std::make_pair(name, events));
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
		if (activeAnimation != nullptr)
		{
			Animator::Events* prevEvents = FindEvents(activeAnimation->GetName());
			if (prevEvents != nullptr)
				prevEvents->endEvent();
		}

		activeAnimation = FindAnimation(name);
		activeAnimation->Reset();
		isLoop = loop;

		Animator::Events* curEvents = FindEvents(activeAnimation->GetName());
		if (curEvents != nullptr)
			curEvents->startEvent();
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
		std::map<std::wstring, Events*>::iterator iter = events.find(name);

		if (iter == events.end())
			return nullptr;

		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events = FindEvents(animation->GetAnimationName());
		return events->startEvent.event;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events = FindEvents(animation->GetAnimationName());
		return events->completeEvent.event;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events = FindEvents(animation->GetAnimationName());
		return events->endEvent.event;
	}
}