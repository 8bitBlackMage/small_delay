CMAKE_MINIMUM_REQUIRED(VERSION 3.22)


project(Small_Delay)

add_subdirectory(JUCE)

juce_add_plugin(${PROJECT_NAME}
    VERSION 0.0.0.1
    PLUGIN_MANUFACTURER_CODE 8BBM
    PLUGIN_CODE 8BDL
    FORMATS Standalone AU VST3
    PRODUCT_NAME "small delay"

    COMPANY_NAME 8BitBlackmage

    COPY_PLUGIN_AFTER_BUILD TRUE)

target_sources( 
    ${PROJECT_NAME}
    PRIVATE
    src/PluginEditor.cpp
    src/PluginProcessor.cpp)

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_utils
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)

# integrate Catch 2 into project 

add_subdirectory(catch2)

add_executable(tests 
    src/tests/test.cpp)

target_link_libraries( 
    tests
    PRIVATE 
    Catch2::Catch2WithMain
    juce::juce_audio_utils
    juce::juce_data_structures)

include(CTest)
include(Catch)

catch_discover_tests(tests)