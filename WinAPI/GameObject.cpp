#include "GameObject.h"

namespace ks
{
    GameObject::GameObject()
        :hdc(NULL)
    {
        components.resize((UINT)e_ComponentType::Size);
        AddComponent<Transform>();
    }

    GameObject::~GameObject()
    {
        for (Component* component : components)
        {
            delete component;
        }
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