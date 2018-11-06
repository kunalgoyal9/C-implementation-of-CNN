#include<bits/stdc++.h>

using namespace std;

template<class T>
class tensor{
	public:
		int nx,ny,nz;
		T *data;
		
		tensor(){
			this->nx = this->ny = this->nz = 0;
			data = new T[0];
		}
		
		tensor(int nx_, int ny_, int nz_){
			this->nx = nx_;
			this->ny = ny_;
			this->nz = nz_;
			this->data = new T[nx_*ny_*nz_]; 
		}
		
		
};

int main(){
	return 0;
}
