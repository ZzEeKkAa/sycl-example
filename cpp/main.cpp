#include <CL/sycl.hpp>

int main(int, char **)
{
  sycl::queue queue(sycl::gpu_selector_v);

  std::cout << queue.get_device().get_info<sycl::info::device::name>() << std::endl;

  queue.submit([&](sycl::handler &cgh)
               {
       sycl::stream out(1024, 256, cgh);

       cgh.single_task<class printkernel>([=] {
       out << "Hello stream!" << sycl::endl;
     } ); });

  return 0;
}
