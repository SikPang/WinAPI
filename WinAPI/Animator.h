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
			// startEvent = func; �� �Լ� �Ҵ�
			void	operator=(std::function<void()> func)
			{
				event = std::move(func);
			}

			// startEvent(); �� �Ҵ�� �Լ� ȣ��
			void	operator()()
			{
				if (event)
					event();
			}

			// �Լ� ������, <void���� �Ű����� ����>
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