#include "Animation.h"
#include "Animator.h"
#include "GameObject.h"
#include "Time.h"
#include "Transform.h"

namespace ks
{
	Animation::Animation()
		: animator(nullptr)
		, sheetImage(nullptr)
		, time(0.0f)
		, isComplete(false)
		, spriteIndex(0)
	{

	}

	Animation::~Animation()
	{
	
	}
	
	void Animation::Initialize()
	{
	
	}
	
	void Animation::Update()
	{
		if (isComplete == true)
			return;

		time += Time::GetDeltaTime();
		if (spriteSheet[spriteIndex].duration < time)
		{
			time = 0.0;

			if (spriteSheet.size() <= (size_t)spriteIndex + 1)
				isComplete = true;
			else
				++spriteIndex;
		}
	}
	
	void Animation::Render(HDC hdc)
	{
		Transform* transform = animator->GetGameObject()->GetComponent<Transform>();
		Vector2 scale = transform->GetScale();
		Vector2 pos = transform->GetPos();

		// 캐릭터의 발을 기준으로 포지션을 계산
		pos += spriteSheet[spriteIndex].offset;
		pos.x -= spriteSheet[spriteIndex].size.x / 2.0f;
		pos.y -= spriteSheet[spriteIndex].size.y;

		// 크기 조정 안 됨 3,4번째 인자에 배수
		TransparentBlt(hdc
			, pos.x, pos.y
			, spriteSheet[spriteIndex].size.x * scale.x
			, spriteSheet[spriteIndex].size.y * scale.y
			, sheetImage->GetHdc()
			, spriteSheet[spriteIndex].leftTop.x
			, spriteSheet[spriteIndex].leftTop.y
			, spriteSheet[spriteIndex].size.x
			, spriteSheet[spriteIndex].size.y,
			RGB(255, 0, 255));
	}
	
	void Animation::Create(Image* sheet, Vector2 leftTop, UINT col, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		sheetImage = sheet;

		Vector2 size;
		size.x = sheetImage->GetWidth() / (float)col;
		size.y = sheetImage->GetHeight() / (float)row;

		for (int i = 0; i < spriteLength; ++i)
		{
			Sprite newSprite;

			newSprite.leftTop.x = leftTop.x + size.x * i;
			newSprite.leftTop.y = leftTop.y;
			newSprite.size = size;
			newSprite.offset = offset;
			newSprite.duration = duration;

			spriteSheet.push_back(newSprite);
		}
	}
	
	void Animation::Reset()
	{
		spriteIndex = 0;
		time = 0.0f;
		isComplete = false;
	}
}