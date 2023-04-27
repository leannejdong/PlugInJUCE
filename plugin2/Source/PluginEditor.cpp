/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Plugin1AudioProcessorEditor::Plugin1AudioProcessorEditor (Plugin1AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

Plugin1AudioProcessorEditor::~Plugin1AudioProcessorEditor()
{

  setLookAndFeel(nullptr);
}

//==============================================================================
void Plugin1AudioProcessorEditor::paint (juce::Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

  g.setColour (juce::Colours::white);
  g.setFont (15.0f);
  g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void Plugin1AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void Plugin1AudioProcessorEditor::setLookAndFeel(juce::LookAndFeel* newLookAndFeel)
{
  // lookAndFeel = std::move(newLookAndFeel);
  // setLookAndFeel(lookAndFeel.get());

    if (newLookAndFeel != nullptr)
    {
        lookAndFeel.reset(newLookAndFeel);
    }
    else
    {
        lookAndFeel.reset();
    }

}
