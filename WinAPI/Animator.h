#pragma once

#include <map>
#include <functional>
#include "Component.h"
#include "Animation.h"
#include "Image.h"

namespace ks
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			// startEvent = func; 로 함수 할당
			void	operator=(std::function<void()> func)
			{
				event = std::move(func);
			}

			// startEvent(); 로 할당된 함수 호출
			void	operator()()
			{
				if (event)
					event();
			}

			// 함수 포인터, <void형에 매개변수 없음>
			std::function<void()> event;
		};

		struct Events
		{
			Event	startEvent;
			Event	completeEvent;
			Event	endEvent;
		};

	private:
		std::map<std::wstring, Animation*> animations;
		std::map<std::wstring, Event*> events;
		Image* spriteSheet;
		Animation* activeAnimation;

	public:
		Animator();
		~Animator();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;

	public:
		void	CreateAnimation();
		void	CreateAnimations();
		void	Play(const std::wstring& name, bool loop);
		Animation* FindAnimation(const std::wstring& name);
		Events* FindEvents(const std::wstring& name);
		std::function<void>& GetStartEvent(const std::wstring& name);
		std::function<void>& GetCompleteEvent(const std::wstring& name);
		std::function<void>& GetEndEvent(const std::wstring& name);
	};
}
