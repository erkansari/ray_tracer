#ifndef VEC3_H
#define VEC3_H

#include <math.h>

template <typename T>
class Vec3
{
private:
	T x;
	T y;
	T z;
public:
	Vec3();
	Vec3(const Vec3<T> &vec3);
	Vec3(T x, T y, T z);
	void normalize();
	T dot(Vec3 vec3) const;
	Vec3<T> cross(Vec3 vec3) const;
	void setX(T x);
	T getX() const;
	void setY(T y);
	T getY() const;
	void setZ(T z);
	T getZ() const;
	Vec3 operator - () const;
	Vec3 operator + (const Vec3 &vec3) const;
	Vec3 operator - (const Vec3 &vec3) const;
	Vec3 operator * (const T factor) const;
	Vec3 operator + (const T term) const;
};

template <typename T>
Vec3<T>::Vec3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template <typename T>
Vec3<T>::Vec3(const Vec3<T> &vec3)
{
	this->x = vec3.x;
	this->y = vec3.y;
	this->z = vec3.z;
}

template <typename T>
Vec3<T>::Vec3(T x, T y, T z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template <typename T>
void Vec3<T>::normalize()
{
	T length = sqrt(x * x + y * y + z * z);
	if(length > 0){
		x /= length;
		y /= length;
		z /= length;
	}
}

template <typename T>
T Vec3<T>::dot(Vec3 vec3) const
{
	T result = x * vec3.x + y * vec3.y + z * vec3.z;
	return result;
}

template <typename T>
Vec3<T> Vec3<T>::cross(Vec3 vec3) const
{
	return Vec3<T>(this->y * vec3.z - this->z * vec3.y, this->z * vec3.x - this->x * vec3.z, this->x * vec3.y - this->y * vec3.x);
}

template <typename T>
void Vec3<T>::setX(T x)
{
	this->x = x;
}

template <typename T>
T Vec3<T>::getX() const
{
	return this->x;
}

template <typename T>
void Vec3<T>::setY(T y)
{
	this->y = y;
}

template <typename T>
T Vec3<T>::getY() const
{
	return this->y;
}

template <typename T>
void Vec3<T>::setZ(T z)
{
	this->z = z;
}

template <typename T>
T Vec3<T>::getZ() const
{
	return this->z;
}

template <typename T>
Vec3<T> Vec3<T>::operator - () const
{
	return Vec3(-this->x, -this->y, -this->z);
}

template <typename T>
Vec3<T> Vec3<T>::operator + (const Vec3 &vec3) const
{
	return Vec3(this->x + vec3.getX(), this->y + vec3.getY(),this->z + vec3.getZ());
}

template <typename T>
Vec3<T> Vec3<T>::operator - (const Vec3 &vec3) const
{
	return Vec3(this->x - vec3.getX(), this->y - vec3.getY(),this->z - vec3.getZ());
}

template <typename T>
Vec3<T> Vec3<T>::operator * (const T factor) const
{
	return Vec3(this->x * factor, this->y * factor,this->z * factor);
}

template <typename T>
Vec3<T> Vec3<T>::operator + (const T term) const
{
	return Vec3(this->x + term, this->y + term,this->z + term);
}

#endif