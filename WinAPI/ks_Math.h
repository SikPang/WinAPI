#pragma once

#include <math.h>
#define PI 3.141592

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

		Vector2& operator+(Vector2 other)
		{
			Vector2 temp;

			temp.x = this->x + other.x;
			temp.y = this->y + other.y;
			return (temp);
		}

		Vector2& operator-(Vector2 other)
		{
			Vector2 temp;

			temp.x = this->x - other.x;
			temp.y = this->y - other.y;
			return (temp);
		}

		void operator+=(Vector2& other)
		{
			this->x += other.x;
			this->y += other.y;
			return;
		}

		void operator-=(Vector2& other)
		{
			this->x -= other.x;
			this->y -= other.y;
			return;
		}

		float GetLength()
		{
			return sqrt(x * x + y * y);
		}

		Vector2& Normalize()
		{
			float length = GetLength();
			x /= length;
			y /= length;

			return *this;
		}
	};

	inline static Vector2 Rotate(Vector2 vector, float degree)
	{
		float radian = (degree / 180.f) * PI;
		
		vector.Normalize();

		float pX = vector.x * cosf(radian) - vector.y * sinf(radian);
		float pY = vector.x * sinf(radian) + vector.y * cosf(radian);
		
		return Vector2(pX, pY);
	}
}