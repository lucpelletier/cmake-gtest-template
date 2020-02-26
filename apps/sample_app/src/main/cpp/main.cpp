#include "sample_app/app_main.h"

int main(int argc, char **argv)
{
    return sample_app::Main({ argv, argv + argc });
}
