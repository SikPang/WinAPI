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
		Effect,
		UI,
		Size
	};

	enum class e_ComponentType
	{
		Transform,
		Collider,
		SpriteRenderer,
		Animator,
		Audio,
		Size
	};
}