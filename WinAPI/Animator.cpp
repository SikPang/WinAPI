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
		for (auto animation : animations)
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
	
	}
	
	void Animator::Render(HDC hdc)
	{
	
	}
	
	void Animator::Release()
	{
	
	}

	void Animator::CreateAnimation(const std::wstring& name, Image* sheet, Vector2 leftTop, UINT coulmn, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{

	}

	void Animator::CreateAnimations()
	{

	}

	void Animator::Play(const std::wstring& name, bool loop)
	{

	}

	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		return nullptr;
	}

	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		return nullptr;
	}
}