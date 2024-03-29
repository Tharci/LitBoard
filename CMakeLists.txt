cmake_minimum_required(VERSION 3.17)
project(LitBoard)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type not specified: Use Release by default")
endif (NOT CMAKE_BUILD_TYPE)

include_directories(./)
include_directories(./external/include)
include_directories(./component)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-O2")
endif()

if (WIN32)
    add_compile_definitions(CURL_STATICLIB)

    if (CMAKE_BUILD_TYPE STREQUAL "Release")
        link_directories(./external/bin/Release)
        add_link_options(/LTCG)
    elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
        link_directories(./external/bin/Debug)
    else ()
        message(FATAL_ERROR "Build type must be either \"Debug\" or \"Release\".")
    endif ()


else ()
    link_directories(/usr/lib)
endif ()

add_executable(LitBoard main.cpp main.cpp LitBoardDriver.cpp LitBoardDriver.h component/Component.cpp component/Component.h ConfigHandler.cpp ConfigHandler.h component/LiveWeather.cpp component/LiveWeather.h component/AudioVisualizer.cpp component/AudioVisualizer.h KeyboardHandler.cpp KeyboardHandler.h component/MessageHandler.cpp component/MessageHandler.h component/AppIntegration.cpp component/AppIntegration.h component/ServerHandler.cpp component/ServerHandler.h component/StateHandler.cpp component/StateHandler.h component/NotificationHandler.cpp component/NotificationHandler.h Config.h HIDDevice.cpp HIDDevice.h component/CyclicComponent.cpp component/CyclicComponent.h component/AudioClientProvider.cpp component/AudioClientProvider.h credentials.h)

if (WIN32)
    target_link_libraries(LitBoard hidapi setupapi libcurl Crypt32 ws2_32 winmm wldap32 Psapi)
else ()
    target_link_libraries(LitBoard libhidapi-hidraw.so libcurl.so pthread)
endif ()
