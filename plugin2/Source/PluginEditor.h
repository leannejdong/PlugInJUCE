/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Plugin1AudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Plugin1AudioProcessorEditor (Plugin1AudioProcessor&);
    ~Plugin1AudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void setLookAndFeel(juce::LookAndFeel* newLookAndFeel);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Plugin1AudioProcessor& audioProcessor;
    std::unique_ptr<juce::LookAndFeel> lookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Plugin1AudioProcessorEditor)
};
