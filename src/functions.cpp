// Procedural Interfaces

/*
bbdoc: Minib3d Only
about:
This command is included as MiniB3D currently does not have the same buffer commands as Blitz3D.

Use this command to copy a region of the backbuffer to a texture.

The region copied from the backbuffer will start at (0,0), and end at the texture's width and height.

Therefore if you want to copy the whole of a 3D scene to a texture, you must first resize the camera viewport to the size of 
the texture, use RenderWorld to render the camera, then use this command to copy the backbuffer to the texture.

Note that if a texture has the mipmap flag enabled (by default it does), then this command must be called for each mipmap,
otherwise the texture will appear to fade into a different, non-matching mipmap as you move away from it. A routine similar to
the one below will copy the backbuffer to each mipmap, making sure the camera viewport is the same size as the mipmap.

For i=0 Until tex.CountMipmaps()
	CameraViewport 0,0,tex.MipmapWidth(),tex.MipmapHeight()
	Renderworld
	BackBufferToTex(tex,i)
Next

It may be easier to disable the mipmap flag for the texture. To do so, use ClearTextureFilters after calling Graphics3D 
(the mipmap flag is a default filter).

If you are using this command to copy to a cubemap texture, use SetCubeFace to first select which portion of the texture you
will be copying to. Note that in MiniB3D mipmaps are not used by cubemaps, so ignore the information about mipmaps for normal 
textures above.

See the cubemap.bmx example included with MiniB3D to learn more about cubemapping.
*/

extern "C" { 

int BufferToTex(Texture* tex,unsigned char* buffer, int frame){
	tex->BufferToTex(buffer,frame);
}

int BackBufferToTex(Texture* tex,int frame){
	tex->BackBufferToTex(frame);
}


/*
bbdoc: Minib3d Only
about:
This command is the equivalent of Blitz3D's MeshCullBox command.

It is used to set the radius of a mesh's 'cull sphere' - if the 'cull sphere' is not inside the viewing area, the mesh will not 
be rendered.

A mesh's cull radius is set automatically, therefore in most cases you will not have to use this command.

One time you may have to use it is for animated meshes where the default cull radius may not take into account all animation 
positions, resulting in the mesh being wrongly culled at extreme positions.
*/
int MeshCullRadius(Entity* ent, float radius){
//	ent->MeshCullRadius(radius);
}

// Blitz3D functions, A-Z

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AddAnimSeq">Online Help</a>
*/
int AddAnimSeq(Entity* ent,int length){
	return ent->AddAnimSeq(length);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AddMesh">Online Help</a>
*/
int AddMesh(Mesh* mesh1,Mesh* mesh2){
	mesh1->AddMesh(mesh2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AddTriangle">Online Help</a>
*/
int AddTriangle(Surface* surf,int v0,int v1,int v2){
	return surf->AddTriangle(v0,v1,v2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AddVertex">Online Help</a>
*/
int AddVertex(Surface* surf,float x, float y,float z,float u=0.0, float v=0.0,float w=0.0){
	return surf->AddVertex(x,y,z,u,v,w);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AmbientLight">Online Help</a>
*/
int AmbientLight(float r,float g,float b){
	Global::AmbientLight(r,g,b);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AntiAlias">Online Help</a>
*/
int AntiAlias(int samples){
	//Global::AntiAlias(samples);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=Animate">Online Help</a>
*/
int Animate(Entity* ent,int mode=1,float speed=1.0,int seq=0,int trans=0){
	ent->Animate(mode,speed,seq,trans);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=Animating">Online Help</a>
*/
int Animating(Entity* ent){
	if (ent->anim_mode!=0) return true;
	if (ent->anim_trans!=0) return true;
	return false;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AnimLength">Online Help</a>
*/
int AnimLength(Entity* ent){
	//return ent->AnimLength();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AnimSeq">Online Help</a>
*/
int AnimSeq(Entity* ent){
	//return ent->AnimSeq();
	return ent->anim_seq;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=AnimTime">Online Help</a>
*/
float AnimTime(Entity* ent){
	return ent->AnimTime();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushAlpha">Online Help</a>
*/
int BrushAlpha(Brush* brush, float a){
	brush->BrushAlpha(a);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushBlend">Online Help</a>
*/
int BrushBlend(Brush* brush,int blend){
	brush->BrushBlend(blend);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushColor">Online Help</a>
*/
int BrushColor(Brush* brush,float r,float g,float b){
	brush->BrushColor(r,g,b);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushFX">Online Help</a>
*/
int BrushFX(Brush* brush,int fx){
	brush->BrushFX(fx);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushShininess">Online Help</a>
*/
int BrushShininess(Brush* brush,float s){
	brush->BrushShininess(s);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=BrushTexture">Online Help</a>
*/
int BrushTexture(Brush* brush,Texture* tex,int frame=0,int index=0){
	brush->BrushTexture(tex,frame,index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraClsColor">Online Help</a>
*/
int CameraClsColor(Camera* cam, float r,float g,float b){
	cam->CameraClsColor(r,g,b);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraClsMode">Online Help</a>
*/
int CameraClsMode(Camera* cam,int cls_depth,int cls_zbuffer){
	cam->CameraClsMode(cls_depth,cls_zbuffer);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraFogColor">Online Help</a>
*/
int CameraFogColor(Camera* cam,float r,float g,float b){
	cam->CameraFogColor(r,g,b);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraFogMode">Online Help</a>
*/
int CameraFogMode(Camera* cam,int mode){
	cam->CameraFogMode(mode);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraFogRange">Online Help</a>
*/
int CameraFogRange(Camera* cam,float nnear,float nfar){
	cam->CameraFogRange(nnear,nfar);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraPick">Online Help</a>
*/
Entity* CameraPick(Camera* cam,float x,float y){
	return Pick::CameraPick(cam,x,y);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraProject">Online Help</a>
*/
int CameraProject(Camera* cam,float x,float y,float z){
	cam->CameraProject(x,y,z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraProjMode">Online Help</a>
*/
int CameraProjMode(Camera* cam,int mode){
	cam->CameraProjMode(mode);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraRange">Online Help</a>
*/
int CameraRange(Camera* cam,float nnear,float nfar){
	cam->CameraRange(nnear,nfar);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraViewport">Online Help</a>
*/
int CameraViewport(Camera* cam,int x,int y,int width,int height){
	cam->CameraViewport(x,y,width,height);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CameraZoom">Online Help</a>
*/
int CameraZoom(Camera* cam,float zoom){
	cam->CameraZoom(zoom);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ClearCollisions">Online Help</a>
int ClearCollisions(){
	Global::ClearCollisions();
}
*/
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ClearSurface">Online Help</a>
*/
int ClearSurface(Surface* surf,bool clear_verts=true,bool clear_tris=true){
	surf->ClearSurface(clear_verts,clear_tris);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ClearTextureFilters">Online Help</a>
*/
int ClearTextureFilters(){
	Texture::ClearTextureFilters();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ClearWorld">Online Help</a>
*/
int ClearWorld(bool entities=true,bool brushes=true,bool textures=true){
	Global::ClearWorld(entities,brushes,textures);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionEntity">Online Help</a>
*/
Entity* CollisionEntity(Entity* ent,int index){
	return ent->CollisionEntity(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=Collisions">Online Help</a>
*/
int Collisions(int src_no,int dest_no,int method_no,int response_no=0){
	Global::Collisions(src_no,dest_no,method_no,response_no);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionNX">Online Help</a>
*/
float CollisionNX(Entity* ent,int index){
	return ent->CollisionNX(index);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionNY">Online Help</a>
*/
float CollisionNY(Entity* ent,int index){
	return ent->CollisionNY(index);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionNZ">Online Help</a>
*/
float CollisionNZ(Entity* ent,int index){
	return ent->CollisionNZ(index);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionSurface">Online Help</a>
*/
Surface* CollisionSurface(Entity* ent,int index){
	return ent->CollisionSurface(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionTime">Online Help</a>
*/
float CollisionTime(Entity* ent,int index){
	return ent->CollisionTime(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionTriangle">Online Help</a>
*/
int CollisionTriangle(Entity* ent,int index){
	return ent->CollisionTriangle(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionX">Online Help</a>
*/
float CollisionX(Entity* ent,int index){
	return ent->CollisionX(index);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionY">Online Help</a>
*/
float CollisionY(Entity* ent,int index){
	return ent->CollisionY(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CollisionZ">Online Help</a>
*/
float CollisionZ(Entity* ent,int index){
	return ent->CollisionZ(index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CountChildren">Online Help</a>
*/
int CountChildren(Entity* ent){
	return ent->CountChildren();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CountCollisions">Online Help</a>
*/
int CountCollisions(Entity* ent){
	return ent->CountCollisions();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CopyEntity">Online Help</a>
*/
Entity* CopyEntity(Entity* ent,Entity* parent=0){
	return ent->CopyEntity(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CopyMesh">Online Help</a>
*/
Mesh* CopyMesh(Mesh* mesh,Entity* parent=0){
	return mesh->CopyMesh(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CountSurfaces">Online Help</a>
*/
int CountSurfaces(Mesh* mesh){
	return mesh->CountSurfaces();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CountTriangles">Online Help</a>
*/
int CountTriangles(Surface* surf){
	return surf->CountTriangles();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CountVertices">Online Help</a>
*/
int CountVertices(Surface* surf){
	return surf->CountVertices();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateBrush">Online Help</a>
*/
Brush* CreateBrush(float r=255.0,float g=255.0,float b=255.0){
	return Brush::CreateBrush(r,g,b);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateCamera">Online Help</a>
*/
Camera* CreateCamera(Entity* parent=0){
	return Camera::CreateCamera(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateCone">Online Help</a>
*/
Mesh* CreateCone(int segments=8,bool solid=true,Entity* parent=0){
	return Mesh::CreateCone(segments,solid,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateCylinder">Online Help</a>
*/
Mesh* CreateCylinder(int segments=8,bool solid=true,Entity* parent=0){
	return Mesh::CreateCylinder(segments,solid,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateCube">Online Help</a>
*/
Mesh* CreateCube(Entity* parent=0){
	return Mesh::CreateCube(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateMesh">Online Help</a>
*/
Mesh* CreateMesh(Entity* parent=0){
	return Mesh::CreateMesh(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateLight">Online Help</a>
*/
Light* CreateLight(int light_type=1,Entity* parent=0){
	return Light::CreateLight(light_type,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreatePivot">Online Help</a>
*/
Pivot* CreatePivot(Entity* parent=0){
	return Pivot::CreatePivot(parent);
}

Mesh* CreatePlane(int divisions=1,Entity* parent=0){
	return Mesh::CreatePlane(divisions,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateSphere">Online Help</a>
*/
Mesh* CreateSphere(int segments=8,Entity* parent=0){
	return Mesh::CreateSphere(segments,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateSprite">Online Help</a>
*/
Sprite* CreateSprite(Entity* parent=0){
	return Sprite::CreateSprite(parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateSurface">Online Help</a>
*/
Surface* CreateSurface(Mesh* mesh,Brush* brush=0){
	return mesh->CreateSurface(brush);
}

/*
*/
Terrain* CreateTerrain(int size, Entity* parent=0){
	return Terrain::CreateTerrain(size,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=CreateTexture">Online Help</a>
*/
Texture* CreateTexture(int width,int height,int flags=1,int frames=1){
	return Texture::CreateTexture(width,height,flags,frames);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=DeltaPitch">Online Help</a>
*/
float DeltaPitch(Entity* ent1,Entity* ent2){
	return ent1->DeltaPitch(ent2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=DeltaYaw">Online Help</a>
*/
float DeltaYaw(Entity* ent1,Entity* ent2){
	return ent1->DeltaYaw(ent2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityAlpha">Online Help</a>
*/
int EntityAlpha(Entity* ent,float alpha){
	ent->EntityAlpha(alpha);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityAutoFade">Online Help</a>
*/
int EntityAutoFade(Entity* ent,float near,float far){
//	ent->EntityAutoFade(near,far);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityBlend">Online Help</a>
*/
int EntityBlend(Entity* ent, int blend){
	ent->EntityBlend(blend);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityBox">Online Help</a>
*/
int EntityBox(Entity* ent,float x,float y,float z,float w,float h,float d){
	ent->EntityBox(x,y,z,w,h,d);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityClass">Online Help</a>
*/
string EntityClass(Entity* ent){
	return ent->EntityClass();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityCollided">Online Help</a>
*/
Entity* EntityCollided(Entity* ent,int type_no){
	return ent->EntityCollided(type_no);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityColor">Online Help</a>
*/
int EntityColor(Entity* ent,float red,float green,float blue){
	ent->EntityColor(red,green,blue);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityDistance">Online Help</a>
*/
float EntityDistance(Entity* ent1,Entity* ent2){
	return ent1->EntityDistance(ent2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityFX">Online Help</a>
*/
int EntityFX(Entity* ent,int fx){
	ent->EntityFX(fx);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityInView">Online Help</a>
*/
int EntityInView(Entity* ent,Camera* cam){
	return cam->EntityInView(ent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityName">Online Help</a>
*/
string EntityName(Entity* ent){
	return ent->EntityName();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityOrder">Online Help</a>
*/
int EntityOrder(Entity* ent,int order){
	ent->EntityOrder(order);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityParent">Online Help</a>
*/
int EntityParent(Entity* ent,Entity* parent_ent,bool glob=true){
	ent->EntityParent(parent_ent,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityPick">Online Help</a>
*/
Entity* EntityPick(Entity* ent,float range){
	return Pick::EntityPick(ent,range);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityPickMode">Online Help</a>
*/
int EntityPickMode(Entity* ent,int pick_mode,bool obscurer=true){
	ent->EntityPickMode(pick_mode,obscurer);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityPitch">Online Help</a>
*/
float EntityPitch(Entity* ent,bool glob=false){
	return ent->EntityPitch(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityRadius">Online Help</a>
*/
int EntityRadius(Entity* ent,float radius_x,float radius_y=0.0){
	ent->EntityRadius(radius_x,radius_y);
}
	
/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityRoll">Online Help</a>
*/
float EntityRoll(Entity* ent,bool glob=false){
	return ent->EntityRoll(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityShininess">Online Help</a>
*/
int EntityShininess(Entity* ent,float shine){
	ent->EntityShininess(shine);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityTexture">Online Help</a>
*/
int EntityTexture(Entity* ent,Texture* tex,int frame=0,int index=0){
//	Mesh*(ent).EntityTexture(Texture* tex,frame,index);
	ent->EntityTexture(tex,frame,index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityType">Online Help</a>
*/
int EntityType(Entity* ent,int type_no,bool recursive=false){
	ent->EntityType(type_no,recursive);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityVisible">Online Help</a>
*/
int EntityVisible(Entity* src_ent,Entity* dest_ent){
	return Pick::EntityVisible(src_ent,dest_ent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityX">Online Help</a>
*/
float EntityX(Entity* ent,bool glob=false){
	return ent->EntityX(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityY">Online Help</a>
*/
float EntityY(Entity* ent,bool glob=false){
	return ent->EntityY(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityYaw">Online Help</a>
*/
float EntityYaw(Entity* ent,bool glob=false){
	return ent->EntityYaw(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=EntityZ">Online Help</a>
*/
float EntityZ(Entity* ent,bool glob=false){
	return ent->EntityZ(glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ExtractAnimSeq">Online Help</a>
*/
int ExtractAnimSeq(Entity* ent,int first_frame,int last_frame,int seq=0){
	return ent->ExtractAnimSeq(first_frame,last_frame,seq);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FindChild">Online Help</a>
*/
Entity* FindChild(Entity* ent,char* child_name){
	return ent->FindChild(child_name);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FindSurface">Online Help</a>
*/
Surface* FindSurface(Mesh* mesh,Brush* brush){
//	return mesh->FindSurface(brush);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FitMesh">Online Help</a><p>
*/
Mesh* FitMesh(Mesh* mesh,float x,float y,float z,float width,float height,float depth,bool uniform=false){
	mesh->FitMesh(x,y,z,width,height,depth,uniform);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FlipMesh">Online Help</a>
*/
Mesh* FlipMesh(Mesh* mesh){
	mesh->FlipMesh();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FreeBrush">Online Help</a>
*/
int  FreeBrush(Brush* brush){
	brush->FreeBrush();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FreeEntity">Online Help</a>
*/
int FreeEntity(Entity* ent){
	ent->FreeEntity();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=FreeTexture">Online Help</a>
*/
int FreeTexture(Texture* tex){
	tex->FreeTexture();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetBrushTexture">Online Help</a>
*/
Texture* GetBrushTexture(Brush* brush,int index=0){
//	return Texture::GetBrushTexture(brush,index);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetChild">Online Help</a>
*/
Entity* GetChild(Entity* ent,int child_no){
	return ent->GetChild(child_no);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetEntityBrush">Online Help</a>
*/
Brush* GetEntityBrush(Entity* ent){
	return ent->GetEntityBrush();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetEntityType">Online Help</a>
*/
int GetEntityType(Entity* ent){
	return ent->GetEntityType();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ResetEntity">Online Help</a>
*/
float GetMatElement(Entity* ent,int row,int col){
//	ent->GetMatElement(row,col);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetParent">Online Help</a>
*/
Entity* GetParentEntity(Entity* ent){
	return ent->GetParent();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetSurface">Online Help</a>
*/
Surface* GetSurface(Mesh* mesh,int surf_no){
	return mesh->GetSurface(surf_no);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=GetSurfaceBrush">Online Help</a>
*/
Brush* GetSurfaceBrush(Surface* surf){
	return surf->GetSurfaceBrush();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=Graphics3D">Online Help</a>
*/
int Graphics3D(int width,int height,int depth=0,int mode=0,int rate=60){
	Global::Graphics(); //(width,height,depth,mode,rate);
	Global::width=width;
	Global::height=height;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=HandleSprite">Online Help</a>
*/
int HandleSprite(Sprite* sprite,float h_x,float h_y){
	sprite->HandleSprite(h_x,h_y);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=HideEntity">Online Help</a>
*/
int HideEntity(Entity* ent){
	ent->HideEntity();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LightColor">Online Help</a>
*/
int LightColor(Light* light,float red,float green,float blue){
	light->LightColor(red,green,blue);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LightConeAngles">Online Help</a>
*/
int LightConeAngles(Light* light,float inner_ang,float outer_ang){
	light->LightConeAngles(inner_ang,outer_ang);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LightRange">Online Help</a>
*/
int LightRange(Light* light,float range){
	light->LightRange(range);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LinePick">Online Help</a>
*/
Entity* LinePick(float x,float y,float z,float dx,float dy,float dz,float radius=0.0){
	return Pick::LinePick(x,y,z,dx,dy,dz,radius);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadAnimMesh">Online Help</a>
*/
Mesh* LoadAnimMesh(char* file,Entity* parent=0){
	return Mesh::LoadAnimMesh(file,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadAnimTexture">Online Help</a>
*/
Texture* LoadAnimTexture(char* file,int flags,int frame_width,int frame_height,int first_frame,int frame_count){
	return Texture::LoadAnimTexture(file,flags,frame_width,frame_height,first_frame,frame_count);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadBrush">Online Help</a>
*/
Brush* LoadBrush(char *file,int flags=1,float u_scale=1.0,float v_scale=1.0){
	return Brush::LoadBrush(file,flags,u_scale,v_scale);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadMesh">Online Help</a>
*/
Mesh* LoadMesh(char* file,Entity* parent=0){
	return Mesh::LoadMesh(file,parent);
}


Terrain* LoadTerrain(char* file,Entity* parent=0){
	return Terrain::LoadTerrain(file,parent);
}


/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadTexture">Online Help</a>
*/
Texture* LoadTexture(char* file,int flags=1){
	return Texture::LoadTexture(file,flags);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=LoadSprite">Online Help</a>
*/
Sprite* LoadSprite(char* tex_file,int tex_flag=1,Entity* parent=0){
	return Sprite::LoadSprite(tex_file,tex_flag,parent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=MeshDepth">Online Help</a>
*/
float MeshDepth(Mesh* mesh){
	return mesh->MeshDepth();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=MeshesIntersect">Online Help</a>
*/
int MeshesIntersect(Mesh* mesh1,Mesh* mesh2){
	mesh1->MeshesIntersect(mesh2);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=MeshHeight">Online Help</a>
*/
float MeshHeight(Mesh* mesh){
	return mesh->MeshHeight();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=MeshWidth">Online Help</a>
*/
float MeshWidth(Mesh* mesh){
	return mesh->MeshWidth();
}


int ModifyTerrain(Terrain* terr, int x, int z, float new_height){
	terr->ModifyTerrain ( x,  z, new_height);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=MoveEntity">Online Help</a>
*/
int MoveEntity(Entity* ent,float x,float y,float z){
	ent->MoveEntity(x,y,z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=NameEntity">Online Help</a>
*/
int NameEntity(Entity* ent,char* name){
	ent->NameEntity(name);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PaintEntity">Online Help</a>
*/
int PaintEntity(Entity* ent,Brush* brush){
//	mesh(ent)->PaintEntity(brush);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PaintMesh">Online Help</a>
*/
Mesh* PaintMesh(Mesh* mesh,Brush* brush){
	mesh->PaintMesh(brush);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PaintSurface">Online Help</a>
*/
int PaintSurface(Surface* surf,Brush* brush){
	surf->PaintSurface(brush);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedEntity">Online Help</a>
*/
Entity* PickedEntity(){
//	return TPick.PickedEntity:TEntity();
	return Pick::PickedEntity();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedNX">Online Help</a>
*/
float PickedNX(){
	return Pick::PickedNX();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedNY">Online Help</a>
*/
float PickedNY(){
	return Pick::PickedNY();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedNZ">Online Help</a>
*/
float PickedNZ(){
	return Pick::PickedNZ();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedSurface">Online Help</a>
*/
Surface* PickedSurface(){
//	return TPick.PickedSurface:TSurface()
	return Pick::PickedSurface();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedTime">Online Help</a>
*/
float PickedTime(){
	return Pick::PickedTime();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedTriangle">Online Help</a>
*/
int PickedTriangle(){
	return Pick::PickedTriangle();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedX">Online Help</a>
*/
float PickedX(){
	return Pick::PickedX();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedY">Online Help</a>
*/
float PickedY(){
	return Pick::PickedY();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PickedZ">Online Help</a>
*/
float PickedZ(){
	return Pick::PickedZ();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PointEntity">Online Help</a>
*/
int PointEntity(Entity* ent,Entity* target_ent,float roll=0){
	ent->PointEntity(target_ent,roll);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PositionEntity">Online Help</a>
*/
int PositionEntity(Entity* ent,float x,float y,float z,bool glob=false){
	ent->PositionEntity(x,y,z,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PositionMesh">Online Help</a>
*/
int PositionMesh(Mesh* mesh,float px,float py,float pz){
	mesh->PositionMesh(px,py,pz);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=PositionTexture">Online Help</a>
*/
int PositionTexture(Texture* tex,int u_pos,int v_pos){
	tex->PositionTexture(u_pos,v_pos);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ProjectedX">Online Help</a>
*/
float ProjectedX(){
    return Camera::projected_x;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ProjectedY">Online Help</a>
*/
float ProjectedY(){
    return Camera::projected_y;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ProjectedZ">Online Help</a>
*/
float ProjectedZ(){
    return Camera::projected_z;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=RenderWorld">Online Help</a>
*/
int RenderWorld(){
	Global::RenderWorld();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ResetEntity">Online Help</a>
*/
int ResetEntity(Entity* ent){
	ent->ResetEntity();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=RotateEntity">Online Help</a>
*/
int RotateEntity(Entity* ent,float x,float y,float z,bool glob=false){
	ent->RotateEntity(x,y,z,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=RotateMesh">Online Help</a>
*/
Mesh* RotateMesh(Mesh* mesh,float pitch,float yaw,float roll){
	mesh->RotateMesh(pitch,yaw,roll);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=RotateSprite">Online Help</a>
*/
int RotateSprite(Sprite* sprite,float ang){
	sprite->RotateSprite(ang);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=RotateTexture">Online Help</a>
*/
int RotateTexture(Texture* tex,float ang){
	tex->RotateTexture(ang);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ScaleEntity">Online Help</a>
*/
int ScaleEntity(Entity* ent,float x,float y,float z,bool glob=false){
	ent->ScaleEntity(x,y,z,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ScaleMesh">Online Help</a>
*/
int ScaleMesh(Mesh* mesh,float sx,float sy,float sz){
	mesh->ScaleMesh(sx,sy,sz);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ScaleSprite">Online Help</a>
*/
int ScaleSprite(Sprite* sprite,float s_x,float s_y){
	sprite->ScaleSprite(s_x,s_y);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ScaleTexture">Online Help</a>
*/
int ScaleTexture(Texture* tex,float u_scale,float v_scale){
	tex->ScaleTexture(u_scale,v_scale);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=SetAnimTime">Online Help</a>
*/
int SetAnimTime(Entity* ent,float time,int seq=0){
	ent->SetAnimTime(time,seq);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=SetCubeFace">Online Help</a>
*/
int SetCubeFace(Texture* tex,int face){
	tex->cube_face=face;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=SetCubeMode">Online Help</a>
*/
int SetCubeMode(Texture* tex,int mode){
	tex->cube_mode=mode;
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=ShowEntity">Online Help</a>
*/
int ShowEntity(Entity* ent){
	ent->ShowEntity();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=SpriteViewMode">Online Help</a>
*/
int SpriteViewMode(Sprite* sprite,int mode){
	sprite->SpriteViewMode(mode);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TerrainHeight">Online Help</a>
*/
float TerrainHeight (Terrain* terr, int x, int z){
	return terr->TerrainHeight (x, z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TerrainX">Online Help</a>
*/
float TerrainX (Terrain* terr, float x, float y, float z){
	return terr->TerrainX (x, y, z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TerrainZ">Online Help</a>
*/
float TerrainZ (Terrain* terr, float x, float y, float z){
	return terr->TerrainZ (x, y, z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureBlend">Online Help</a>
*/
int TextureBlend(Texture* tex,int blend){
	tex->TextureBlend(blend);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureCoords">Online Help</a>
*/
int TextureCoords(Texture* tex,int coords){
	tex->TextureCoords(coords);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureHeight">Online Help</a>
*/
int TextureHeight(Texture* tex){
//	return tex->TextureHeight();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureFilter">Online Help</a>
*/
int TextureFilter(char* match_text,int flags){
//	Texture::TextureFilter(match_text,flags);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureName">Online Help</a>
*/
string TextureName(Texture* tex){
	return tex->TextureName();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TextureWidth">Online Help</a>
*/
int TextureWidth(Texture* tex){
//	return tex->TextureWidth()
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormedX">Online Help</a>
*/
float TFormedX(){
	return Entity::TFormedX();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormedY">Online Help</a>
*/
float TFormedY(){
	return Entity::TFormedY();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormedZ">Online Help</a>
*/
float TFormedZ(){
	return Entity::TFormedZ();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormNormal">Online Help</a>
*/
int TFormNormal(float x,float y,float z,Entity* src_ent,Entity* dest_ent){
	Entity::TFormNormal(x,y,z,src_ent,dest_ent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormPoint">Online Help</a>
*/
int TFormPoint(float x,float y,float z,Entity* src_ent,Entity* dest_ent){
	Entity::TFormPoint(x,y,z,src_ent,dest_ent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TFormVector">Online Help</a>
*/
int TFormVector(float x,float y,float z,Entity* src_ent,Entity* dest_ent){
	Entity::TFormVector(x,y,z,src_ent,dest_ent);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TranslateEntity">Online Help</a>
*/
int TranslateEntity(Entity* ent,float x,float y,float z,bool glob=false){
	ent->TranslateEntity(x,y,z,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TriangleVertex">Online Help</a>
*/
int TriangleVertex(Surface* surf,int tri_no,int corner){
	return surf->TriangleVertex(tri_no,corner);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=TurnEntity">Online Help</a>
*/
int TurnEntity(Entity* ent,float x,float y,float z,bool glob=false){
	ent->TurnEntity(x,y,z,glob);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=UpdateNormals">Online Help</a>
*/
int UpdateNormals(Mesh* mesh){
	mesh->UpdateNormals();
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=UpdateWorld">Online Help</a>
*/
int UpdateWorld(float anim_speed=1.0){
	Global::UpdateWorld(anim_speed);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VectorPitch">Online Help</a>
*/
float VectorPitch(float vx,float vy,float vz){
//	return Vector->VectorPitch(vx,vy,vz);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VectorYaw">Online Help</a>
*/
float VectorYaw(float vx,float vy,float vz){
//	return Vector->VectorYaw(vx,vy,vz);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexAlpha">Online Help</a>
*/
float VertexAlpha(Surface* surf,int vid){
	return surf->VertexAlpha(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexBlue">Online Help</a>
*/
float VertexBlue(Surface* surf,int vid){
	return surf->VertexBlue(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexColor">Online Help</a>
*/
int VertexColor(Surface* surf,int vid,float r,float g,float b,float a=1.0){
	surf->VertexColor(vid,r,g,b,a);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexCoords">Online Help</a>
*/
void VertexCoords(Surface* surf,int vid,float x,float y,float z){
	surf->VertexCoords(vid,x,y,z);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexGreen">Online Help</a>
*/
float VertexGreen(Surface* surf,int vid){
	return surf->VertexGreen(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexNormal">Online Help</a>
*/
int VertexNormal(Surface* surf,int vid,float nx,float ny,float nz){
	surf->VertexNormal(vid,nx,ny,nz);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexNX">Online Help</a>
*/
float VertexNX(Surface* surf,int vid){
	return surf->VertexNX(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexNY">Online Help</a>
*/
float VertexNY(Surface* surf,int vid){
	return surf->VertexNY(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexNZ">Online Help</a>
*/
float VertexNZ(Surface* surf,int vid){
	return surf->VertexNZ(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexRed">Online Help</a>
*/
float VertexRed(Surface* surf,int vid){
	return surf->VertexRed(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexTexCoords">Online Help</a>
*/
int VertexTexCoords(Surface* surf,int vid,float u,float v,float w=0.0,int coord_set=0){
	surf->VertexTexCoords(vid,u,v,w,coord_set);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexU">Online Help</a>
*/
float VertexU(Surface* surf,int vid,int coord_set=0){
	return surf->VertexU(vid,coord_set);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexV">Online Help</a>
*/
float VertexV(Surface* surf,int vid,int coord_set=0){
	return surf->VertexV(vid,coord_set);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexW">Online Help</a>
*/
float VertexW(Surface* surf,int vid,int coord_set=0){
	return surf->VertexW(vid,coord_set);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexX">Online Help</a>
*/
float VertexX(Surface* surf,int vid){
	return surf->VertexX(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexY">Online Help</a>
*/
float VertexY(Surface* surf,int vid){
	return surf->VertexY(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=VertexZ">Online Help</a>
*/
float VertexZ(Surface* surf,int vid){
	return surf->VertexZ(vid);
}

/*
bbdoc: <a href="http://www.blitzbasic.com/b3ddocs/command.php?name=Wireframe">Online Help</a>
*/
int Wireframe(int enable){
	if (enable!=0) glPolygonMode(GL_FRONT,GL_LINE); else glPolygonMode(GL_FRONT,GL_FILL);
}

//' Blitz2D
/*
int Text(int x,int y,char* str){
	TBlitz2D.Text(x,y,str);
}

int BeginMax2D(){
	TBlitz2D.BeginMax2D();
}

int EndMax2D(){
	TBlitz2D.EndMax2D();
}
*/
//' ***extras***

float EntityScaleX(Entity* ent,bool glob=false){
	return ent->EntityScaleX(glob);
}

float EntityScaleY(Entity* ent,bool glob=false){
	return ent->EntityScaleY(glob);
}

float EntityScaleZ(Entity* ent,bool glob=false){
	return ent->EntityScaleZ(glob);
}

//' ***todo***

/*
Function LightMesh(mesh:TMesh,red#,green#,blue#,range#=0,light_x#=0,light_y#=0,light_z#=0)
End Function
Function MeshesIntersect(mesh1:TMesh,mesh2:TMesh)
End Function
Function CreatePlane(sub_divs=1,parent:TEntity=Null)
End Function
Function AlignToVector(vx:Float,vy:Float,vz:Float,axis,rate=1)
End Function
Function LoadAnimSeq(ent:TEntity,filename$)
End Function
Function SetAnimKey(ent:TEntity,frame,pos_key=True,rot_key=True,scale_key=True)
End Function
*/
}
