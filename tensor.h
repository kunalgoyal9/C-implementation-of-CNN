#include "point.h"

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
			data = new T[other.size.x *other.size.y *other.size.z];
			memcpy(this->data, other.data, other.size.x*other.size.y*other.size.z*sizeof(T));
			this->size = other.size;
		}
		
		tensor<T> operator+(tensor<T>& other){
			assert(other.size == size);
			tensor<T> copy(other);
			for(int i=0; i<size.x*size.y*size.z; i++){
				copy.data[i] += this->data[i];
			}
			return copy;
		}
		
		tensor<T> operator-(tensor<T>& other){
			assert(other.size == size);
			tensor<T> copy(other);
			for(int i=0; i<size.x*size.y*size.z; i++){
				copy.data[i] -= this->data[i];
			}
			return copy;
		}
		
		void operator=(const tensor<T>& other){
			data = new T[other.size.x *other.size.y *other.size.z];
			memcpy(data,
			 other.data, 
			 other.size.x*other.size.y*other.size.z*sizeof(T)
			 );
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
		
		~tensor()
		{
			delete[] data;
		}

};

static void print_tensor( tensor<float>& data )
{
	int mx = data.size.x;
	int my = data.size.y;
	int mz = data.size.z;

	for ( int z = 0; z < mz; z++ )
	{
		printf( "[Dim%d]\n", z );
		for ( int y = 0; y < my; y++ )
		{
			for ( int x = 0; x < mx; x++ )
			{
				printf( "%.2f \t", (float)data.get( x, y, z ) );
			}
			printf( "\n" );
		}
	}
}

static tensor<float> to_tensor( std::vector<std::vector<std::vector<float>>> data )
{
	int z = data.size();
	int y = data[0].size();
	int x = data[0][0].size();


	tensor<float> t( x, y, z );

	for ( int i = 0; i < x; i++ )
		for ( int j = 0; j < y; j++ )
			for ( int k = 0; k < z; k++ )
				t( i, j, k ) = data[k][j][i];
	return t;
}
