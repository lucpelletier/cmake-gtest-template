#include "sample_app/app_main.h"
#include "gmock/gmock.h"

namespace
{
struct SampleAppTest : testing::Test
{
  public:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(SampleAppTest, AppMain__when_given_valid_arguments__succeeds)
{
    // given
    const char* argv[] = { "foo.exe", "1", "2" };
    auto argc = static_cast<int>(sizeof(argv) / sizeof(argv[0]));

    // when
    auto retval = SampleApp_Main(argc, argv);

    // then
    EXPECT_THAT(retval, testing::Eq(0));
}

}  // namespace
