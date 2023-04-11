#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class ReverbPluginEditor: public AudioProcessorEditor
{
    public:
    ReverbPluginEditor(AudioProcessor& processor);

    void paint(Graphics& g) override;
    void resized() override;

    private:
    AudioProcessorValueTreeState::SliderAttachment mSliderAttachment;
    Slider mDryWetSlider;

};
