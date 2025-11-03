#pragma once
#include <juce_audio_basics/juce_audio_basics.h>


/// @brief Delay unit for audio data, supports multiple channels and multiple read points.
class Delay {

    public:
        Delay(int initialDelayInSeconds = 1, 
              double initialSampleRate = 44100)
            : delaySampleRate(initialSampleRate)
            , delayTimeInSeconds(initialDelayInSeconds)
            , delayTimeInSamples(delayTimeInSeconds * initialSampleRate)
            , delayBuffer(1,  static_cast<int>(maxDelayTime * delaySampleRate))
            , writePosition(0)
        {
            
        }

        void prepareToPlay(const double sampleRate)
        {
            delaySampleRate = sampleRate;
            delayTimeInSamples = delayTimeInSeconds * sampleRate;
            delayBuffer.setSize(1,static_cast<int>(maxDelayTime *  sampleRate),false,true);
        }

        void writeSample(float sample) {
            delayBuffer.setSample(0, writePosition, sample);
            tick();
        }

        float readSample()
        {
            return delayBuffer.getSample(0, static_cast<int>(writePosition - delayTimeInSamples) );
        }
        

        void setDelayTimeInSamples(int delayTime) {
            delayTimeInSamples = delayTime;
        }

        void tick() {
            writePosition++;
        }

        inline const double getDelayTimeInSamples() {return delayTimeInSamples; }
        inline const int getNumChannels() {return delayBuffer.getNumChannels();}

    private:

    double delaySampleRate;

    const int maxDelayTime = 8;

    int delayTimeInSeconds;
    double delayTimeInSamples;
    juce::AudioBuffer<float> delayBuffer;

    int writePosition;
};

