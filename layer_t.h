#include "types.h"
#include "tensor.h"

struct layer_t
{
	layer_type type;
	tensor_t<float> grads_in;
	tensor_t<float> in;
	tensor_t<float> out;
};
