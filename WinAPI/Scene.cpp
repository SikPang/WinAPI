#include "Scene.h"

namespace ks
{
	Scene::Scene()
	{
		layers.resize((UINT)e_LayerType::Size);
	}

	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{
		for (Layer& layer : layers)
		{
			layer.Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer& layer : layers)
		{
			layer.Update();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer& layer : layers)
		{
			layer.Render(hdc);
		}
	}

	void Scene::Release()
	{
		for (Layer& layer : layers)
		{
			layer.Release();
		}
	}

	void Scene::AddGameObject(GameObject* newObject, e_LayerType layer)
	{
		layers[(UINT)layer].AddGameObject(newObject);
	}
}