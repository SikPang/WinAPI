#pragma once

#include <string>

namespace
{
	class Entity
	{
	private:
		std::wstring	name;

	public:
		Entity();
		virtual ~Entity();

		void			SetName(std::wstring& name) { this->name = name; }
		std::wstring&	GetName() { return name; }
	};
}