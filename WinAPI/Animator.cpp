#include <map>
#include "Animator.h"

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

	void Animator::CreateAnimations()
	{

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