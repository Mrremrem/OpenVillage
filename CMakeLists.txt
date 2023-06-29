cmake_minimum_required(VERSION 3.22)
project(OpenVillage)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenVillage main.cpp Player.cpp 
                WindowManager.cpp ResourceManager.h Directions.h SpriteSheet.cpp 
                Animation.cpp Map.cpp Tile.cpp TileManager.cpp GameManager.cpp HomeVillage.cpp 
                DebugLog.cpp TextBox.cpp FontContainer.cpp CollisionBox.cpp 
                EntityManager.cpp Sign.cpp Entity.cpp)

target_compile_options(OpenVillage PRIVATE -g)

target_link_libraries(OpenVillage PRIVATE sfml-graphics sfml-window sfml-system)