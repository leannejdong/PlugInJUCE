# PlugInJUCE

This is a cmake JUCE7 template used for most projects.

The `PluginProcessor.{cpp,h}` lay out the folundation for building audio plugin in JUCE. It is where we write algorithms (DSP etc).
It handles the changes we make to audio and backend, and the communication between the plugin and the host application.

The `PluginEditor.{cpp,h}` take care of creating the UI of the plugin. It is derived from `AudioProcessorEditor` which contains a collection
of UI elements that allow the user to interact with the plugin. Some common UI elements are sliders, buttons, labels, text boxes and meters. These elements can be created and customized using JUCE's extensive set of GUI components and layout classes.

In the `PluginEditor` ctor, one typically create and initialize UI elements for the plugin. One may also register any listeners or callbacks that hangle user interaction with the UI elements. For instance, we may have a slider control the cutoff frequency of a lowpass filder, we might create the slider in the `PluginEditor` ctor, sets it range and default value , and register a listener that updates the filter's cutoff freq whenever the slider value changes.

The `PluginEditor` class can also be used to handle drawing and painting of custom UI elements, such as waveform displays or spectrum analyzers. To this end, one can override the `paint()` method and use JUCE's graphics classes to draw your custom elements onto the UI.

Once a plugin created, pass it to a daw.