#pragma once

namespace ks
{
	enum class e_SceneType
	{
		Title,
		Play,
		Ending,
		Size
	};

	enum class e_LayerType
	{
		BG,
		Monster,
		Player,
		Bullet,
		Effect,
		UI,
		Size
	};

	enum class e_ComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Collider,
		Audio,
		Size
	};
}