#pragma once

class Vector2
{
public:
	float x;
	float y;
};

class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();

	Vector3(float x, float y, float z);

	void ChangeValues(float x, float y, float z);

	Vector3& operator+=(Vector3& other);

	Vector3& operator=(Vector3& other);

	Vector3 operator+(Vector3& other);

	Vector3 operator-(Vector3& other);

	Vector3 operator*(float scalar);

	void Normalize();
};

class Vector4
{
public:
	float x;
	float y;
	float z;
	float w;
};