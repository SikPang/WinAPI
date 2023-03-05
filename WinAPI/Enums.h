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
		Enemy,
		Player,
		Bullet,
		Test,
		Effect,
		UI,
		Size = 16
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