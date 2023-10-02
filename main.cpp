

#include <Open3D/Open3D.h>
#include <Open3D/core/CUDAUtils.h>


void AssignNew(open3d::core::Tensor& testTensor) {
	testTensor = open3d::core::Tensor::Zeros({ 100,3 }, open3d::core::Dtype::Float32, open3d::core::Device("CUDA:0"));
}


int main() {

	std::cout << "Start" << std::endl;

	open3d::PrintOpen3DVersion();

	open3d::core::Tensor testTensor;
	AssignNew(testTensor);

	open3d::core::cuda::ReleaseCache();

	std::cout << "Finished program" << std::endl;

	return 0;
}