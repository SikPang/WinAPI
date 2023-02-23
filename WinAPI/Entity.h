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

	public:
		Entity();
		virtual ~Entity();

		void			SetName(const std::wstring& name) { this->name = name; }
		std::wstring&	GetName() { return name; }
	};
}