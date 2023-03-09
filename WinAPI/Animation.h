#pragma once

#include <vector>
#include "Image.h"
#include "Entity.h"
#include "ks_Math.h"

namespace ks
{
	// 전방 선언, 헤더 상호 참조 방지
	class Animator;

	class Animation : public Entity
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

	private:
		Animator* animator;
		Image* sheetImage;
		std::vector<Sprite> spriteSheet;
		std::wstring animationName;
		double time;
		bool isComplete;
		int spriteIndex;

	public:
		Animation();
		~Animation();

	public:
		void Initialize();
		void Update();
		void Render(HDC hdc);
		void Create(Image* sheet, Vector2 leftTop, UINT col, UINT row, UINT spriteLength, Vector2 offset, float duration);
		void Reset();

		bool IsComplete() { return isComplete; }
		void SetAnimator(Animator* animator) { this->animator = animator; }
		void SetAnimationName(const std::wstring& name) { animationName = name; }
		std::wstring& GetAnimationName() { return animationName; }
	};
}
