
#include<bits/stdc++.h>
#include"tensor.h"
using namespace std;

struct relu_layer_t
{
	layer_type type = layer_type::relu;
	tensor_t<float> grads_in;
	tensor_t<float> in;
	tensor_t<float> out;

	relu_layer_t( tdsize in_size )
		:
		in( in_size.x, in_size.y, in_size.z ),
		out( in_size.x, in_size.y, in_size.z ),
		grads_in( in_size.x, in_size.y, in_size.z )
	{
	}


	void activate( tensor_t<float>& in )
	{
		this->in = in;
		activate();
	}

	void activate()
	{
		for ( int i = 0; i < in.size.x; i++ )
			for ( int j = 0; j < in.size.y; j++ )
				for ( int z = 0; z < in.size.z; z++ )
				{
					float v = in( i, j, z );
					if ( v < 0 )
						v = 0;
					out( i, j, z ) = v;
				}

	}
};
