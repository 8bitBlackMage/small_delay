#include <catch2/catch_test_macros.hpp>
#include "../dsp/DelayUnit.h"

TEST_CASE("Delay Unit created") {
    Delay DelayUnit;

    REQUIRE(DelayUnit.getDelayTimeInSamples() == 44100);
}

TEST_CASE("Supports multiple Block Sizes")
{
    Delay DelayUnit;

    REQUIRE(DelayUnit.getDelayTimeInSamples() == 44100);

    DelayUnit.prepareToPlay(48000.0);

    REQUIRE(DelayUnit.getDelayTimeInSamples() == 48000);
}


TEST_CASE("Read and Write into Delay")
{
    Delay DelayUnit;

    DelayUnit.setDelayTimeInSamples(2);

    DelayUnit.writeSample(1.0f);
    DelayUnit.writeSample(0.5f);
    REQUIRE(DelayUnit.readSample() == 1.0f);
    DelayUnit.writeSample(0.0f);
    REQUIRE(DelayUnit.readSample() == 0.5f);
}


