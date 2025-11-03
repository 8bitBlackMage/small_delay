#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    juce::Label  delayTimeLabel;
    juce::Label  delayFeedbackLabel;
    juce::Slider delayMixSlider;

    juce::Slider delayTimeSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment delayTimeAttachment;

   

    juce::Slider delayFeedbackSlider;
    juce::AudioProcessorValueTreeState::SliderAttachment delayFeedbackAttachment;


    juce::AudioProcessorValueTreeState::SliderAttachment delayMixAttachment;


    juce::Label  delayMixLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
