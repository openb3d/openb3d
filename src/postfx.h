#ifndef POSTFX_H
#define POSTFX_H

#include "camera.h"
#include "shadermat.h"

struct FXPass{
	Shader* ShaderFX;
	unsigned int *tex;

	int d, numColBufs;

	int width, height;

	vector<int> buffer_in_out;
	int PassLoc, PassValue;

	list<Entity*> render_list;

	FXPass(){
		numColBufs=0;
		ShaderFX=0;
		PassLoc=-1;
	}

};


class PostFX{

public:

	static list<PostFX*> fx_list;

	int vx,vy,vwidth,vheight;

	int no_passes;
	FXPass* pass;

	Camera* cam;
	unsigned int* framebuffer;
	unsigned int renderbuffer;

	PostFX(){
	};

	static PostFX* CreatePostFX(Camera* cam, int passes);
	void AddRenderTarget(int pass_no, int numColBufs, bool depth, int format=8, float scale=1.0);
	void PostFXShader(int pass_no, Shader* shader);
	void PostFXShaderPass(int pass_no, string name, int v);
	void PostFXBuffer(int pass_no, int source_pass, int index, int slot);
	void PostFXTexture(int pass_no, Texture* tex, int slot, int frame=0);
	void PostFXEntity(int pass_no, Entity* ent);
	void Render();



};

#endif

