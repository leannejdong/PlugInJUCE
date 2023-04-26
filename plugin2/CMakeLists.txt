cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(MyJUCEPlugin VERSION 1.0)

### Dependency versions ###

set(LIB_JUCE_TAG "7.0.5")


### IDE Generator pre-config ###

# Xcode: Disable automatic build scheme generation globally.
#        Instead, we explicitely specify which targets require schemes.
set(CMAKE_XCODE_GENERATE_SCHEME OFF)

# IDEs:  Enable grouping of source files into folders in IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# IDEs:  Create a folder in the IDE with the JUCE Module code.
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Show all module sources in IDE projects" ON)



# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the JUCE library
add_subdirectory(JUCE)

# Set Xcode as the generator
set(CMAKE_XCODE_GENERATE_SCHEME ON)

# Set the Xcode scheme name
set(CMAKE_XCODE_SCHEME_NAME "Reverb Plugin")

# Set the Xcode scheme destination
set(CMAKE_XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY "1,2")

# Set the Xcode project settings
set(XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++17")
set(XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
set(XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "12.0")

# Add the plugin source files
juce_add_plugin(MyJUCEPlugin
PRODUCT_NAME "Reverb Plugin"
PLUGIN_MANUFACTURER_CODE "Manu"
PLUGIN_CODE "Rvrb"
FORMATS VST3 AU Standalone
IS_SYNTH FALSE
NEEDS_MIDI_INPUT FALSE
NEEDS_MIDI_OUTPUT FALSE
IS_MIDI_EFFECT FALSE
EDITOR_WANTS_KEYBOARD_FOCUS FALSE
COPY_PLUGIN_AFTER_BUILD FALSE)

# Set the plugin source files
target_sources(MyJUCEPlugin PRIVATE
    # List your plugin source files here
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp)

# Link the JUCE library to the plugin
target_link_libraries(MyJUCEPlugin PRIVATE juce::juce_audio_plugin_client)

# Set the plugin include directories
target_include_directories(MyJUCEPlugin PRIVATE
    # List your plugin include directories here
    src)

# Set the plugin output directory
set_target_properties(MyJUCEPlugin PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
### IDE Generator post-config ###

# IDEs:  Place source groups for project targets into a "Targets" folder (to reduce visual clutter).
# Xcode: Generate build schemes for project targets.
set_target_properties(${project_targets} PROPERTIES
    FOLDER "Targets"
    XCODE_GENERATE_SCHEME ON)
    
    

# Set the plugin file extensions
if(APPLE)
    set_target_properties(MyJUCEPlugin PROPERTIES
        BUNDLE TRUE
        BUNDLE_EXTENSION "plugin")
elseif(WIN32)
    set_target_properties(MyJUCEPlugin PROPERTIES
        SUFFIX ".dll")
endif()

# Set the plugin installation directory
if(UNIX AND NOT APPLE)
    set_target_properties(MyJUCEPlugin PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/lib/vst3")
    install(TARGETS MyJUCEPlugin DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/vst3")
elseif(APPLE)
    set_target_properties(MyJUCEPlugin PROPERTIES
        BUNDLE TRUE
        BUNDLE_EXTENSION "plugin"
        MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist")
    install(TARGETS MyJUCEPlugin DESTINATION "/Library/Audio/Plug-Ins/VST3")
elseif(WIN32)
    set_target_properties(MyJUCEPlugin PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_INSTALL_PREFIX}/VST3")
    install(TARGETS MyJUCEPlugin DESTINATION "${CMAKE_INSTALL_PREFIX}/VST3")
endif()

