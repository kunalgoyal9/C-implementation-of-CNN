#include<bits/stdc++.h>
//#include"point.h"
#include"tensor.h"


using namespace std;




int main(){
	tensor<float> t(2,2,2);
	for(int i=0; i<t.size.x*t.size.y*t.size.z; i++){
		t.data[i] = 10;
	}
	tensor<float> tt(2,2,2);
	
	//cout<<(tt.size == t.size);
	
	//tensor<float> tt(t);
	
	tt = t;
	tt = tt-t;
	print_tensor(tt);
	//cout<<t.data[1];
	return 0;
}
