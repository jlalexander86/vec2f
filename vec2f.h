#ifndef _VEC2F_H
#define _VEC2F_H


#include <cmath>
#ifndef M_PI
	#define M_PI (3.14159)
#endif

class vec2f {
public:
	float x, y;

	vec2f() : x(0), y(0) {}
	vec2f(float x, float y) { this->x = x; this->y = y; }
	vec2f(const vec2f& v) { x = v.x; y = v.y; }

	vec2f& operator=(const vec2f& v) { x = v.x; y = v.y; return *this; }
	vec2f operator+(const vec2f& v) { return vec2f(x + v.x, y + v.y); }
	vec2f& operator+=(const vec2f& v) { x += v.x; y += v.y; return *this; }
	vec2f operator-(const vec2f& v) { return vec2f(x - v.x, y - v.y); }
	vec2f& operator-=(const vec2f& v) { x -= v.x; y -= v.y; return *this; }
	vec2f operator*(float f) { return vec2f(x * f, y * f); }
	vec2f& operator*=(float f) { x *= f; y *= f; return *this; }
	vec2f operator/(float f) { return vec2f(x / f, y / f); }
	vec2f& operator/=(float f) { x /= f; y /= f; return *this; }
	
	float length() { return (float)sqrt(x*x+y*y); }

	bool operator<(vec2f& v) { return length() < v.length(); }
	bool operator<(float f) { return length() < f; }
	bool operator<=(vec2f& v) { return length() <= v.length(); }
	bool operator<=(float f) { return length() <= f; }
	bool operator>(vec2f& v) { return length() > v.length(); }
	bool operator>(float f) { return length() > f; }
	bool operator>=(vec2f& v) { return length() >= v.length(); }
	bool operator>=(float f) { return length() >= f; }
	bool operator==(vec2f& v) { return (x == v.x) && (y == v.y); }
	bool operator==(float f) { return length() == f; }

	void normalize() {
		float l = length();
		if (l == 0.0f || l == 1.0f) return;
		x = x/l; y = y/l;
	}
	vec2f normalized() {
		float l = length();
		if (l == 0.0f || l == 1.0f) return vec2f(x,y);
		return vec2f(x/l, y/l);
	}
	float dot(vec2f& v) { return x * v.x + y * v.y; }
	float distance(vec2f& v) { 
		return vec2f(v.x - x, v.y - y).length();
	}
	void ortho() {
		set(y, -x);
	}
	
	void set(float x, float y) { this->x = x; this->y = y; }
};

#endif