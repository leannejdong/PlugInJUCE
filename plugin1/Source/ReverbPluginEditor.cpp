#include "ReverbPluginEditor.h"

ReverbPluginEditor::ReverbPluginEditor(AudioProcessor& processor)
    : AudioProcessorEditor(&processor)
    , mDryWetSlider(Slider::RotaryHorizontalVerticalDrag, Slider::TextBoxBelow)
    , mSliderAttachment(processor.getParameters(), "dry_wet", mDryWetSlider)
{
    addAndMakeVisible(mDryWetSlider);
    setSize(400, 300);
}

void ReverbPluginEditor::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));
}

void ReverbPluginEditor::resized()
{
    mDryWetSlider.setBounds(10, 10, 100, 100);
}
