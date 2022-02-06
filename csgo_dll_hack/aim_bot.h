#pragma once

#define PI 3.14159265359

struct Target_t
{
	float dist_3d;
	Vector3 angles;

	Target_t(Vector3* src, Vector3* dst);
	Target_t& operator=(Target_t tar);
	float Calc3DDistance(Vector3* src, Vector3* dst);
};

void AimBot();
void CalcAngles(Vector3* src, Vector3* dst, Vector3* angles);