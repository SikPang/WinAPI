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
			, Vector2 offset, float duration);	//완성된 스프라이트 시트를 지정해서 애니메이션 제작하는 함수
		void	CreateAnimations(const std::wstring& path
			, Vector2 offset, float duration);	// 폴더에 들어있는 스프라이트들을 이용해서 애니메이션 제작해주는 함수
		void	Play(const std::wstring& name, bool loop);
		Animation* FindAnimation(const std::wstring& name);
		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);
		bool IsComplete() { return activeAnimation->IsComplete(); }
	};
}
