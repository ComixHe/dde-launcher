#include <gtest/gtest.h>

#define private public
#include "recentlyused.h"
#undef private

class Tst_RecentlyUsed : public testing::Test
{
public:
    void SetUp() override
    {
        m_recentlyUsed = new RecentlyUsed(nullptr);
    }

    void TearDown() override
    {

    }

public:
    RecentlyUsed* m_recentlyUsed;
};

TEST_F(Tst_RecentlyUsed, recentlyUsed_test)
{
    m_recentlyUsed->reload();
    m_recentlyUsed->clear();
}
