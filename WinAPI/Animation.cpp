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
			time = 0.0f;

			if (spriteSheet.size() <= (size_t)spriteIndex + 1)
				isComplete = true;
			else
				++spriteIndex;
		}
	}
	
	void Animation::Render(HDC hdc)
	{
		Transform* transform = animator->GetGameObject()->GetComponent<Transform>();

		TransparentBlt(hdc, transform->GetPos().x, transform->GetPos().y
			, spriteSheet[spriteIndex].size.x, spriteSheet[spriteIndex].size.y
			, sheetImage->GetHdc()
			, spriteSheet[spriteIndex].leftTop.x, spriteSheet[spriteIndex].leftTop.y
			, spriteSheet[spriteIndex].size.x, spriteSheet[spriteIndex].size.y,
			RGB(255, 0, 255));
	}
	
	void Animation::Create(Image* sheet, Vector2 leftTop, UINT col, UINT row, UINT spriteLength, Vector2 offset, float duration)
	{
		sheetImage = sheet;

		Vector2 size = Vector2::One;
		size.x = sheetImage->GetWitdh() / (float)col;
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