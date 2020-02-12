#include "sample_lib/sample.h"
#include "gmock/gmock.h"

namespace
{
struct SampleLibTest : testing::Test
{
  public:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(SampleLibTest, SampleFunction__returns_sum_of_arguments)
{
    // given
    int a = 2;
    int b = 4;

    // when
    auto retval = SampleFunction(a, b);

    // then
    EXPECT_THAT(retval, testing::Eq(6));
}

}  // namespace
