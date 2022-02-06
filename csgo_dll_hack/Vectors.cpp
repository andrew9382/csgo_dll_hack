#include "pch.h"
#include "includes.h"

Vector3::Vector3()
{
	x = y = z = 0;
}

Vector3::Vector3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::ChangeValues(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3& Vector3::operator+=(Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;

	return *this;
}

Vector3& Vector3::operator=(Vector3& other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

Vector3 Vector3::operator+(Vector3& other)
{
	return { x + other.x, y + other.y, z + other.z };
}

Vector3 Vector3::operator-(Vector3& other)
{
	return { x - other.x, y - other.y, z - other.z };
}

Vector3 Vector3::operator*(float scalar)
{
	return { x * scalar, y * scalar, z * scalar };
}

void Vector3::Normalize()
{
	while (y < -180) { y += 360; }
	
	while (y > 180) { y -= 360; }

	if (x < -89) { x = -89; }
	
	if (x > 89) { x = 89; }
}