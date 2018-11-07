#include<bits/stdc++.h>
#include"point.h"

using namespace std;

//template for tensor
template<class T>
class tensor{
	public:
		tdsize size;
		T *data;
		
		tensor(){
			this->nx = this->ny = this->nz = 0;
			data = new T[0];
		}
		
		tensor(int nx_, int ny_, int nz_){
			this->size.x = nx_;
			this->size.y = ny_;
			this->size.z = nz_;
			this->data = new T[nx_*ny_*nz_]; 
		}
		
		tensor(const tensor& other){
			memcpy(data, other.data, other.size.x*other.size.y*other.size.z);
			this->size = other.size;
		}
		
		tensor<T> operator+(const tensor<T>& other){
			assert(other.size == size);
			tensor<T> copy(other);
			for(int i=0; i<size.x*size.y*size.z; i++){
				copy.data[i] += this->data[i];
			}
			return copy;
		}
		
		tensor<T> operator-(const tensor<T>& other){
			assert(other.size == size);
			tensor<T> copy(other);
			for(int i=0; i<size.x*size.y*size.z; i++){
				copy.data[i] -= this->data[i];
			}
			return copy;
		}
		
		void operator=(const tensor<T>& other){
			data = other.data;
			size = other.size; 
		}
		
		T& operator()(int x_, int y_, int z_){
			return this->get(x_, y_, z_);
		}
		
		T& get(int _x, int _y, int _z){
			assert( _x >= 0 && _y >= 0 && _z >= 0 );
			assert( _x < size.x && _y < size.y && _z < size.z );
			
			return data[
			_z * (size.x * size.y) +
				_y * (size.x) +
				_x
			];
		}
		
		void copy_from( std::vector<std::vector<std::vector<T>>> data )
		{
			int z = data.size();
			int y = data[0].size();
			int x = data[0][0].size();

			for ( int i = 0; i < x; i++ )
				for ( int j = 0; j < y; j++ )
					for ( int k = 0; k < z; k++ )
						get( i, j, k ) = data[k][j][i];
		}
		
		~tensor_t()
		{
			delete[] data;
		}

};

int main(){
	tensor<float> t(2,2,1);
	for(int i=0; i<t.size.x*t.size.y*t.size.z; i++){
		t.data[i] = 10;
	}
	tensor<float> tt(2,2,1);
	
	tt = tt + t;
	cout<<tt.data[0];
	//tensor<float> tt(t);
	
	
	//cout<<t.data[1];
	return 0;
}
