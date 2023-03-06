#pragma once

#include <string>
#include <Windows.h>
#include "Enums.h"

namespace ks
{
	class Entity
	{
	private:
		std::wstring	name;
		UINT64			id;

	public:
		Entity();
		virtual ~Entity();

	public:
		void			SetName(const std::wstring& name) { this->name = name; }
		std::wstring&	GetName() { return name; }
		void			SetID(UINT64 id) { this->id = id; }
		UINT64			GetID() { return id; }
	};
}