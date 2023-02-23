#pragma once

#include "Resource.h"
#include <assert.h>

namespace ks
{
	// T가 class 객체가 될 예정
	class Resources
	{
	private:
		static std::map<std::wstring, Resource*> resources;

	public:
		static void	Initialize();

		template <typename T>
		static T* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter = resources.find(key);

			if (iter != resources.end())
				return dynamic_cast<T*>(iter->second);
			else
				return nullptr;
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Find(key);

			if (resource != nullptr)
				return resource;
			else
			{
				resource = new T();

				if (FAILED(resource->Resource::Load(path)))
				{
					assert(nullptr);
					return nullptr;
				}
				else
				{
					resource->SetKey(key);
					resource->SetPath(path);
				}

				resources.insert(str::make_pair(key, resource));

				return dynamic_cast<T*>(resource);
			}
		}
	};

	//std::map<std::wstring, Resource*> Resources::resources = {};
}
