cmake_minimum_required(VERSION 3.22)
project(OpenVillage)

set(CMAKE_CXX_STANDARD 14)

add_executable(OpenVillage main.cpp Player.cpp Player.h WindowManager.cpp WindowManager.h HomeVillage.cpp HomeVillage.h GameManager.cpp GameManager.h Map.cpp Map.h TileInfo.cpp TileInfo.h Directions.h DebugLog.cpp TextBox.cpp FontContainer.cpp CollisionBox.cpp CollisionBox.h)

target_link_libraries(OpenVillage PRIVATE sfml-graphics sfml-window sfml-system)