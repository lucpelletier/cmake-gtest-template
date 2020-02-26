#include "sample_app/app_main.h"

#include <iostream>

#include "sample_lib/sample.h"

namespace sample_app
{
int Main(const std::vector<std::string_view>& args)
{
    if(args.size() != 3)
    {
        std::cout << "Usage: " << args[0].data() << " number number\n";
        return -1;
    }
    std::cout << "Total is "
              << sample_lib::SampleFunction(strtol(args[1].data(), NULL, 10), strtol(args[2].data(), NULL, 10)) << "\n";
    return 0;
}
}  // namespace sample_app
