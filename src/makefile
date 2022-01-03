CCMPILER = g++
CC=g++ -O3

OBJECTS = model.o string_helper.o surface.o bank.o bone.o brush.o collision.o entity.o geom.o global.o minib3d.o light.o matrix.o pick.o pivot.o project.o sprite.o tilt.o touch.o texture_filter.o tree.o animation.o animation_keys.o collision2.o maths_helper.o quaternion.o sprite_batch.o camera.o file.o mesh.o texture.o terrain.o stb_image.o 3ds.o collidetri.o

main:$(OBJECTS) 
ifeq ($(shell uname), Linux)
	$(CC) -shared -o libopenb3d.so $(OBJECTS)  -lGL -lGLU
else
	$(CC) -shared -o openb3d.dll $(OBJECTS)  -lGLee -lopengl32 -lglu32 -lGDI32
endif


3ds.o  : 3ds.cpp 3ds.h
	$(CC) -c 3ds.cpp -o 3ds.o

bank.o : bank.cpp bank.h
	$(CC) -c bank.cpp -o bank.o

bone.o : bone.cpp bone.h
	$(CC) -c bone.cpp -o bone.o

brush.o : brush.cpp brush.h
	$(CC) -c brush.cpp -o brush.o

camera.o : camera.cpp camera.h
	$(CC) -c camera.cpp -o camera.o

collision.o : collision.cpp collision.h
	$(CC) -c collision.cpp -o collision.o

entity.o : entity.cpp entity.h
	$(CC) -c entity.cpp -o entity.o

file.o : file.cpp file.h
	$(CC) -c file.cpp -o file.o

geom.o : geom.cpp geom.h
	$(CC) -c geom.cpp -o geom.o

global.o : global.cpp global.h
	$(CC) -c global.cpp -o global.o

minib3d.o : minib3d.cpp minib3d.h
	$(CC) -c minib3d.cpp -o minib3d.o

light.o : light.cpp light.h
	$(CC) -c light.cpp -o light.o

matrix.o : matrix.cpp matrix.h
	$(CC) -c matrix.cpp -o matrix.o

mesh.o : mesh.cpp mesh.h
	$(CC) -c mesh.cpp -o mesh.o

model.o : model.cpp model.h
	$(CC) -c model.cpp -o model.o

pick.o : pick.cpp pick.h
	$(CC) -c pick.cpp -o pick.o

pivot.o : pivot.cpp pivot.h
	$(CC) -c pivot.cpp -o pivot.o

project.o : project.cpp project.h
	$(CC) -c project.cpp -o project.o

sprite.o : sprite.cpp sprite.h
	$(CC) -c sprite.cpp -o sprite.o

surface.o : surface.cpp surface.h
	$(CC) -c surface.cpp -o surface.o

terrain.o : terrain.cpp terrain.h stb_image.c
	$(CC) -c terrain.cpp -o terrain.o

texture.o : texture.cpp texture.h stb_image.c
	$(CC) -c texture.cpp -o texture.o

tilt.o : tilt.cpp tilt.h
	$(CC) -c tilt.cpp -o tilt.o

touch.o : touch.cpp touch.h
	$(CC) -c touch.cpp -o touch.o

string_helper.o : string_helper.cpp string_helper.h
	$(CC) -c string_helper.cpp -o string_helper.o

texture_filter.o : texture_filter.cpp texture_filter.h
	$(CC) -c texture_filter.cpp -o texture_filter.o

tree.o : tree.cpp tree.h
	$(CC) -c tree.cpp -o tree.o

animation.o : animation.cpp animation.h
	$(CC) -c animation.cpp -o animation.o

animation_keys.o : animation_keys.cpp animation_keys.h
	$(CC) -c animation_keys.cpp -o animation_keys.o

collision2.o : collision2.cpp collision2.h
	$(CC) -c collision2.cpp -o collision2.o

maths_helper.o : maths_helper.cpp maths_helper.h
	$(CC) -c maths_helper.cpp -o maths_helper.o

quaternion.o : quaternion.cpp quaternion.h
	$(CC) -c quaternion.cpp -o quaternion.o

sprite_batch.o : sprite_batch.cpp sprite_batch.h
	$(CC) -c sprite_batch.cpp -o sprite_batch.o

stb_image.o	: stb_image.c
	gcc -c stb_image.c -o stb_image.o

collidetri.o	: collidetri.c
	gcc -c collidetri.c -o collidetri.o
