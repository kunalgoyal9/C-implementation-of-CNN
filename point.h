#include<bits/stdc++.h>
// point having x,y,z dimensions

struct point{
	int x,y,z;
	
	bool operator==(point& other){
		if(this->x == other.x and this->y == other.y and this->z == other.z)	{
			return true;
		}
		else return false;
	}
	
	void operator=(point other){
		x = other.x, y = other.y, z = other.z;
	}
};

// size of a tensor
using tdsize = point;
