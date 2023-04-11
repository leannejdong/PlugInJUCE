cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(MyJUCEPlugin VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the JUCE library
add_subdirectory(juce)

# Add the plugin source files
juce_add_plugin(MyJUCEPlugin
    PLUGIN_MANUFACTURER "MyCompany"
    PLUGIN_DESCRIPTION "My JUCE Plugin"
    PLUGIN_NAME "MyJUCEPlugin")

# Set the plugin source files
target_sources(MyJUCEPlugin PRIVATE
    # List your plugin source files here
    Source/PluginProcessor.cpp
    Source/PluginEditor.cpp
    Source/ReverbPluginEditor.cpp)

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

