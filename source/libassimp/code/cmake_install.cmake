# Install script for directory: /home/foam/Downloads/assimp-master/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/foam/Downloads/assimp-master/bin/libassimp.so.5.0.1"
    "/home/foam/Downloads/assimp-master/bin/libassimp.so.5"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5.0.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so.5"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/foam/Downloads/assimp-master/bin/libassimp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libassimp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/foam/Downloads/assimp-master/code/../include/assimp/anim.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/aabb.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ai_assert.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/camera.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/color4.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/color4.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/config.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ColladaMetaData.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/commonMetaData.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/defs.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/cfileio.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/light.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/material.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/material.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/matrix3x3.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/matrix3x3.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/matrix4x4.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/matrix4x4.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/mesh.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/pbrmaterial.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/postprocess.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/quaternion.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/quaternion.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/scene.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/metadata.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/texture.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/types.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/vector2.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/vector2.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/vector3.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/vector3.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/version.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/cimport.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/importerdesc.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Importer.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/DefaultLogger.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ProgressHandler.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/IOStream.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/IOSystem.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Logger.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/LogStream.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/NullLogger.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/cexport.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Exporter.hpp"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/DefaultIOStream.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/DefaultIOSystem.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ZipArchiveIOSystem.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SceneCombiner.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/fast_atof.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/qnan.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/BaseImporter.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Hash.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/MemoryIOWrapper.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ParsingUtils.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/StreamReader.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/StreamWriter.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/StringComparison.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/StringUtils.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SGSpatialSort.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/GenericProperty.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SpatialSort.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SkeletonMeshBuilder.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SmallVector.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SmoothingGroups.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/SmoothingGroups.inl"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/StandardShapes.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/RemoveComments.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Subdivision.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Vertex.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/LineSplitter.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/TinyFormatter.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Profiler.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/LogAux.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Bitmap.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/XMLTools.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/IOStreamBuffer.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/CreateAnimMesh.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/XmlParser.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/BlobIOSystem.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/MathFunctions.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Exceptional.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Compiler/pushpack1.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Compiler/poppack1.h"
    "/home/foam/Downloads/assimp-master/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

