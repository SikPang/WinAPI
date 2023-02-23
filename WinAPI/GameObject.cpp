#include "GameObject.h"

namespace ks
{
    GameObject::GameObject()
    {

    }

    GameObject::~GameObject()
    {

    }

    void GameObject::Initialize()
    {
        for (Component* component : components)
        {
            if (component == nullptr)
                continue;

            component->Initialize();
        }
    }

    void GameObject::Update()
    {
        for (Component* component : components)
        {
            if (component == nullptr)
                continue;

            component->Update();
        }
    }

    void GameObject::Render(HDC hdc)
    {
        for (Component* component : components)
        {
            if (component == nullptr)
                continue;

            component->Render(hdc);
        }
    }

    void GameObject::Release()
    {
        for (Component* component : components)
        {
            if (component == nullptr)
                continue;

            component->Release();
        }
    }
}