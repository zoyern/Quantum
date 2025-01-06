cmake_minimum_required(VERSION 3.10)
project(baseops)

# Définir le standard C++
set(CMAKE_CXX_STANDARD 17)

# Rechercher Vulkan et SDL2
find_package(Vulkan REQUIRED glslc glslangValidator)
find_package(SDL2 REQUIRED)
find_package(Eigen3 REQUIRED)

# Vérifier si le répertoire QPP existe
if(EXISTS ${CMAKE_SOURCE_DIR}/../libs/qpp/include)
    include_directories(
		${CMAKE_SOURCE_DIR}/../libs/qpp/include
		${CMAKE_SOURCE_DIR}/../libs/qpp/qasmtools/include
	)
    message("| libs/qpp included !")
endif()

# Ajouter les répertoires d'inclusion
include_directories(
    ${Vulkan_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/../build/includes
)

# Rechercher tous les fichiers source
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/../src/*.cpp)
message(STATUS "SOURCES trouvés : ${SOURCES}")

# Création de l'exécutable
add_executable(baseops ${SOURCES})

# Définir les propriétés de sortie
set_target_properties(baseops PROPERTIES OUTPUT_NAME ${CMAKE_SOURCE_DIR}/../quantum)

# Lier les bibliothèques nécessaires
target_link_libraries(baseops Vulkan::Vulkan ${SDL2_LIBRARIES} Eigen3::Eigen )
