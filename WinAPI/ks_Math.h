#pragma once

namespace ks
{
	struct Vector2
	{
		static Vector2 Down;
		static Vector2 Right;

		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(int x, int y)
			: x(x)
			, y(y)
		{

		}

		Vector2(float x, float y)
			: x(x)
			, y(y)
		{

		}

		Vector2(const Vector2&) = default;
		Vector2& operator=(const Vector2&) = default;

		Vector2(Vector2&&) = default;
		Vector2& operator=(Vector2&&) = default;

		Vector2& operator+(Vector2& instance)
		{
			Vector2 temp;

			temp.x = this->x + instance.x;
			temp.y = this->y + instance.y;
			return (temp);
		}

		Vector2& operator-(Vector2& instance)
		{
			Vector2 temp;

			temp.x = this->x - instance.x;
			temp.y = this->y - instance.y;
			return (temp);
		}

		void operator+=(Vector2& instance)
		{
			this->x += instance.x;
			this->y += instance.y;
			return;
		}

		void operator-=(Vector2& instance)
		{
			this->x -= instance.x;
			this->y -= instance.y;
			return;
		}
	};
}