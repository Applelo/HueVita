## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is
# highly recommended that you include this block for all projects.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

## Define project parameters here
# Name of the project
set(SHORT_NAME HueVita)
set(PSVITAIP  "192.168.0.15")
set(VITA3K_PATH "/Applications/Vita3K.app/Contents/MacOS/Vita3K")
project(${SHORT_NAME})
# This line adds Vita helper macros, must go after project definition in order
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "HueVita")
# Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X =
# unique string of developer and Y = a unique number for this app

set(VITA_TITLEID  "HUEV00001")
# Optional version string to show in LiveArea's more info screen
set(VITA_VERSION  "01.00")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
#-Werror -Wfatal-errors
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -fpermissive -std=gnu11 -Wall ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -fpermissive -std=c++11 -Wall ")


include_directories(
)

link_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
)

# Builds
FUNCTION(ADD_RESOURCES out_var)
    SET(result)
    FOREACH(in_f ${ARGN})
        SET(out_f "${CMAKE_CURRENT_BINARY_DIR}/${in_f}.o")
        GET_FILENAME_COMPONENT(out_dir ${out_f} DIRECTORY)
        ADD_CUSTOM_COMMAND(OUTPUT ${out_f}
                COMMAND ${CMAKE_COMMAND} -E make_directory ${out_dir}
                COMMAND ${CMAKE_LINKER} -r -b binary -o ${out_f} ${in_f}
                DEPENDS ${in_f}
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                COMMENT "Building resource ${out_f}"
                VERBATIM
                )
        LIST(APPEND result ${out_f})
    ENDFOREACH()
    SET(${out_var} "${result}" PARENT_SCOPE)
ENDFUNCTION()

#file(GLOB res_files RELATIVE
#        ${CMAKE_SOURCE_DIR}
#        )
#add_resources(huevita_res ${res_files})

add_executable(${SHORT_NAME}
       # ${huevita_res}
        src/main.cpp
        src/HueApp.cpp
        src/Api.cpp

        src/utils/Pad.cpp
        src/utils/Touch.cpp
        src/utils/IME.cpp
        src/utils/Net.cpp
        src/utils/I18n.cpp

        src/hue/Group.cpp
        src/hue/Light.cpp
        src/hue/Schedule.cpp
        src/hue/Sensor.cpp
        src/hue/Config.cpp
        src/hue/Rule.cpp
        src/hue/ResourceLink.cpp
        src/hue/Scene.cpp
)

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(${SHORT_NAME}
        crypto
        expat
        curl
        ssl
        z
        crypto
        opus

        vita2d
        SceNet_stub
        ScePgf_stub
        ScePvf_stub
        SceGxm_stub
        SceHttp_stub
        SceCtrl_stub
        SceTouch_stub
        SceNetCtl_stub
        SceAppUtil_stub
        SceDisplay_stub
        SceLibKernel_stub
        SceSysmodule_stub
        ScePower_stub
        SceCommonDialog_stub
        SceRegistryMgr_stub
        png
        jpeg
        freetype
        jansson
        z
        m
        c
)


vita_create_self(eboot.bin ${SHORT_NAME})
vita_create_vpk(${SHORT_NAME}.vpk ${VITA_TITLEID} eboot.bin
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE  sce_sys/icon0.png sce_sys/icon0.png
        sce_sys/changeinfo.xml sce_sys/changeinfo.xml
        sce_sys/livearea/pic0.png sce_sys/pic0.png
        sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
        sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
        sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml

        i18n/fr.json i18n/fr.json
        i18n/en.json i18n/en.json
)


add_custom_target(send
  COMMAND curl -T eboot.bin ftp://${PSVITAIP}:1337/ux0:/app/${VITA_TITLEID}/
  DEPENDS eboot.bin
)

add_custom_target(copy
  COMMAND cp eboot.bin F:/app/${VITA_TITLEID}/eboot.bin
  DEPENDS eboot.bin
)

add_custom_target(send_vpk
  COMMAND curl -T ${SHORT_NAME}.vpk ftp://${PSVITAIP}:1337/ux0:/data/
  DEPENDS ${SHORT_NAME}.vpk
)

add_custom_target(copy_vpk
  COMMAND cp ${SHORT_NAME}.vpk F:/data/${VITA_TITLEID}/${SHORT_NAME}.vpk
  DEPENDS ${SHORT_NAME}.vpk
)

add_custom_target(emulator
        COMMAND ${VITA3K_PATH} ${CMAKE_CURRENT_BINARY_DIR}/${SHORT_NAME}.vpk
        DEPENDS ${SHORT_NAME}.vpk
        )

