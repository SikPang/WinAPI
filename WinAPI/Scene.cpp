#include "Scene.h"
#include "SceneManager.h"

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
		SceneManager::SetActiveScene(this);
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

	void Scene::Destroy()
	{
		for (Layer& layer : layers)
		{
			std::vector<GameObject*>& gameObjects = layer.GetGameObjects();

			for (std::vector<GameObject*>::iterator iter = gameObjects.begin(); iter != gameObjects.end(); )
			{
				if ((*iter)->GetState() == GameObject::e_State::Death)
				{
					delete (*iter);
					*iter = nullptr;
					iter = gameObjects.erase(iter);
				}
				else
					++iter;
			}
		}
	}

	void Scene::AddGameObject(GameObject* newObject, e_LayerType layer)
	{
		layers[(UINT)layer].AddGameObject(newObject);
	}

	std::vector<GameObject*>& Scene::GetGameObjects(e_LayerType layer)
	{
		return layers[(UINT)layer].GetGameObjects();
	}

	void Scene::OnEnter()
	{

	}

	void Scene::OnExit()
	{

	}
}