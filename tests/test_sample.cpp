#include <gtest/gtest.h>

extern "C" {
#include "fff.h"
}

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(int, read_sensor);

int get_temperature()
{
    return read_sensor();
}

TEST(TemperatureTest, ReturnsSensorValue)
{
    RESET_FAKE(read_sensor);

    read_sensor_fake.return_val = 25;

    EXPECT_EQ(get_temperature(), 25);
    EXPECT_EQ(read_sensor_fake.call_count, 1);
}