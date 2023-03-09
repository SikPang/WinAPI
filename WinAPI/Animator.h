#pragma once

#include <map>
#include <functional>
#include "Component.h"
#include "Animation.h"
#include "Image.h"
#include "ks_Math.h"

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
		std::map<std::wstring, Events*> events;
		Image* spriteSheet;
		Animation* activeAnimation;
		bool isLoop;

	public:
		Animator();
		~Animator();

	public:
		void	Initialize() override;
		void	Update() override;
		void	Render(HDC hdc) override;
		void	Release() override;

	public:
		void CreateAnimation(const std::wstring& name
			, Image* sheet
			, Vector2 leftTop
			, UINT col, UINT row, UINT spriteLength
			, Vector2 offset, float duration);	//�ϼ��� ��������Ʈ ��Ʈ�� �����ؼ� �ִϸ��̼� �����ϴ� �Լ�
		void	CreateAnimations(const std::wstring& path
			, Vector2 offset, float duration);	// ������ ����ִ� ��������Ʈ���� �̿��ؼ� �ִϸ��̼� �������ִ� �Լ�
		void	Play(const std::wstring& name, bool loop);
		Animation* FindAnimation(const std::wstring& name);
		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);
		bool IsComplete() { return activeAnimation->IsComplete(); }
	};
}
