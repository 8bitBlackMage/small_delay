#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p)
    , processorRef (p)
    , delayTimeLabel("Time Label", "Time")
    , delayFeedbackLabel("Feedback Label","Feedback")
    , delayMixLabel("Mix Label", "Mix")
{
    juce::ignoreUnused (processorRef);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    addAndMakeVisible(delayTimeSlider);
    delayTimeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    delayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,100,25);
    delayTimeSlider.setTextValueSuffix("s");    

    addAndMakeVisible(delayTimeLabel);
    delayTimeLabel.setJustificationType(juce::Justification::centred);


    addAndMakeVisible(delayFeedbackSlider);
    delayFeedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    delayFeedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,100,25);
    delayFeedbackSlider.setTextValueSuffix("%");

    addAndMakeVisible(delayFeedbackLabel);
    delayFeedbackLabel.setJustificationType(juce::Justification::centred);

    addAndMakeVisible(delayMixSlider);
    delayMixSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    delayMixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow,false,100,25);
    delayFeedbackSlider.setTextValueSuffix("%");

    addAndMakeVisible(delayMixLabel);
    delayMixLabel.setJustificationType(juce::Justification::centred);

}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void AudioPluginAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    bounds.removeFromLeft(25);
    bounds.removeFromRight(25);

    auto topLabelRow = bounds.removeFromTop(30);
    delayTimeLabel.setBounds(topLabelRow.removeFromLeft(150));
    delayFeedbackLabel.setBounds(topLabelRow.removeFromRight(150));

    auto topSliderRow = bounds.removeFromTop(150);
    delayTimeSlider.setBounds(topSliderRow.removeFromLeft(150));

    auto mixLabelBounds = topSliderRow.removeFromLeft(50).removeFromBottom(30);
    delayMixLabel.setBounds(mixLabelBounds);

    delayFeedbackSlider.setBounds(topSliderRow.removeFromRight(150));

    auto mixSliderBounds = bounds.removeFromTop(150);

    delayMixSlider.setBounds(mixSliderBounds);

}
