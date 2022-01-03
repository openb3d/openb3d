/*
 *  terrain.cpp
 *  minib3d
 *
 *
 */

#ifdef linux
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <GL/glext.h>
#endif
#ifdef WIN32
#include <gl\GLee.h>
#endif



#include "global.h"
#include "entity.h"
#include "camera.h"
#include "brush.h"
#include "terrain.h"

#include "stb_image.h"
#include "string_helper.h"
#include "file.h"
#include "tree.h"


int Terrain::triangleindex;

Line Ray;
float radius;




MeshInfo* Terrain::mesh_info;
list<Terrain*> Terrain::terrain_list;

Terrain* Terrain::CopyEntity(Entity* parent_ent){}


Terrain* Terrain::CreateTerrain(int tsize, Entity* parent_ent){

	if(parent_ent==NULL) parent_ent=Global::root_ent;
	Terrain* terr=new Terrain;

	for (int i = 0; i<= ROAM_LMAX; i++){
		terr->level2dzsize[i] = 0;
	}		
        int lmax=tsize/100+10;
	if (lmax>=ROAM_LMAX) lmax=ROAM_LMAX;

	for (int i = 0; i<= lmax; i++){
		terr->level2dzsize[i] = (float)tsize/2048 / sqrt((float)(1 << i));	// <-------------terrain detail here
	}		



	//terr->brush=new brush;
	mesh_info=C_NewMeshInfo();
	terr->c_col_tree=C_CreateColTree(mesh_info);
	C_DeleteMeshInfo(mesh_info);
	terr->AddParent(*parent_ent);
	terrain_list.push_back(terr);
	if (tsize!=0){
		terr->size=tsize;
		terr->vsize=30;
		terr->height=new float[(tsize+1)*(tsize+1)];
	}

	return terr;
	
}

void Terrain::UpdateTerrain(){

	int fog=false;
	if (glIsEnabled(GL_FOG)==GL_TRUE) fog=true; // if fog enabled, we'll enable it again at end of each surf loop in case of fx flag disabling it
		
	glDisable(GL_ALPHA_TEST);

	if (order!=0){
		glDisable(GL_DEPTH_TEST);
		glDepthMask(GL_FALSE);
	}else{
		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
	}

	switch(brush.blend){
		case 0:
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // alpha
			break;
		case 1:
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); // alpha
			break;
		case 2:
			glBlendFunc(GL_DST_COLOR,GL_ZERO); // multiply
			break;
		case 3:
			glBlendFunc(GL_SRC_ALPHA,GL_ONE); // additive and alpha
			break;
		}
		
	float ambient_red,ambient_green,ambient_blue;

	// fx flag 1 - full bright ***todo*** disable all lights?
	if (brush.fx & 1){
		ambient_red  =1.0;
		ambient_green=1.0;
		ambient_blue =1.0;
	}else{
		ambient_red  =Global::ambient_red;
		ambient_green=Global::ambient_green;
		ambient_blue =Global::ambient_blue;
	}

	// fx flag 2 - vertex colours
	if(brush.fx&2){
			glEnable(GL_COLOR_MATERIAL);
	}else{
			glDisable(GL_COLOR_MATERIAL);
	}
		
	// fx flag 4 - flatshaded
	if(brush.fx&4){
		glShadeModel(GL_FLAT);
	}else{
		glShadeModel(GL_SMOOTH);
	}

	// fx flag 8 - disable fog
	if(brush.fx&8){
			glDisable(GL_FOG);
	}
		
	// fx flag 16 - disable backface culling
	if(brush.fx&16){
		glDisable(GL_CULL_FACE);
	}else{
		glEnable(GL_CULL_FACE);
	}

	// light + material color
		
	float ambient[]={ambient_red,ambient_green,ambient_blue};	
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambient);

	float mat_ambient[]={brush.red,brush.green,brush.blue,brush.alpha};
	float mat_diffuse[]={brush.red,brush.green,brush.blue,brush.alpha};
	float mat_specular[]={brush.shine,brush.shine,brush.shine,brush.shine};
	float mat_shininess[]={100.0}; // upto 128

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,mat_shininess);

	// textures
			
	int tex_count=0;
	tex_count=brush.no_texs;

	for(int ix=0;ix<tex_count;ix++){

		if(brush.tex[ix]){
				
			// Main brush texture takes precedent over surface brush texture
			Texture* texture=NULL;
			int tex_flags=0,tex_blend=0,tex_coords=0;
			float tex_u_scale=1.0,tex_v_scale=1.0,tex_u_pos=0.0,tex_v_pos=0.0,tex_ang=0.0;

			texture=brush.tex[ix];
			tex_flags=brush.tex[ix]->flags;
			tex_blend=brush.tex[ix]->blend;
			tex_coords=brush.tex[ix]->coords;
			tex_u_scale=brush.tex[ix]->u_scale;
			tex_v_scale=brush.tex[ix]->v_scale;
			tex_u_pos=brush.tex[ix]->u_pos;
			tex_v_pos=brush.tex[ix]->v_pos;
			tex_ang=brush.tex[ix]->angle;
			//tex_cube_mode=brush.tex[ix]->cube_mode;
			//frame=brush.tex_frame;

			glActiveTexture(GL_TEXTURE0+ix);
			glClientActiveTexture(GL_TEXTURE0+ix);

			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,texture->texture); // call before glTexParameteri

			// masked texture flag
			if(tex_flags&4){
				glEnable(GL_ALPHA_TEST);
			}else{
				glDisable(GL_ALPHA_TEST);
			}
			
			// mipmapping texture flag
			if(tex_flags&8){
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
			}else{
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			}
				
			// clamp u flag
			if(tex_flags&16){
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
			}else{						
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
			}
				
			// clamp v flag
			if(tex_flags&32){
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
			}else{
				glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			}
		
				// ***!ES***
				/*
				// spherical environment map texture flag
				if(tex_flags&64!=0){
					glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
					glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
					glEnable(GL_TEXTURE_GEN_S);
					glEnable(GL_TEXTURE_GEN_T);
				}else{
					glDisable(GL_TEXTURE_GEN_S);
					glDisable(GL_TEXTURE_GEN_T);
				}
			
				// cubic environment map texture flag
				if(tex_flags&128!=0){
	
					glEnable(GL_TEXTURE_CUBE_MAP);
					glBindTexture(GL_TEXTURE_CUBE_MAP,texture->texture.name); // call before glTexParameteri
					
					glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);
					glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
					glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_WRAP_R,GL_CLAMP_TO_EDGE);
					glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
					glTexParameteri(GL_TEXTURE_CUBE_MAP,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
					
					glEnable(GL_TEXTURE_GEN_S);
					glEnable(GL_TEXTURE_GEN_T);
					glEnable(GL_TEXTURE_GEN_R);
					//glEnable(GL_TEXTURE_GEN_Q)

					if(tex_cube_mode==1){
						glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
						glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
						glTexGeni(GL_R,GL_TEXTURE_GEN_MODE,GL_REFLECTION_MAP);
					}
					
					if(tex_cube_mode==2){
						glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_NORMAL_MAP);
						glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_NORMAL_MAP);
						glTexGeni(GL_R,GL_TEXTURE_GEN_MODE,GL_NORMAL_MAP);
					}
		
				}else{

					glDisable(GL_TEXTURE_CUBE_MAP);
					
					// only disable tex gen s and t if sphere mapping isn't using them
					if(tex_flags&64==0){
						glDisable(GL_TEXTURE_GEN_S);
						glDisable(GL_TEXTURE_GEN_T);
					}
					
					glDisable(GL_TEXTURE_GEN_R);
					//glDisable(GL_TEXTURE_GEN_Q)
	
				}
				*/
				
			switch(tex_blend){
				case 0: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
				break;
				case 1: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
				break;
				case 2: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
				//case 2 glTexEnvf(GL_TEXTURE_ENV,GL_COMBINE_RGB_EXT,GL_MODULATE);
				break;
				case 3: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_ADD);
				break;
				case 4:
					//glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_COMBINE_EXT); ***!ES***
					//glTexEnvf(GL_TEXTURE_ENV, GL_COMBINE_RGB_EXT, GL_DOT3_RGB_EXT); ***!ES***
					break;
				case 5:
					glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
					glTexEnvi(GL_TEXTURE_ENV,GL_COMBINE_RGB,GL_MODULATE);
					glTexEnvi(GL_TEXTURE_ENV,GL_RGB_SCALE,2.0);
					break;
				default: glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
			}

						
			// reset texture matrix
			glMatrixMode(GL_TEXTURE);
			glLoadIdentity();
						
			if(tex_u_pos!=0.0 || tex_v_pos!=0.0){
				glTranslatef(tex_u_pos,tex_v_pos,0.0);
			}
			if(tex_ang!=0.0){
				glRotatef(tex_ang,0.0,0.0,1.0);
			}
			if(tex_u_scale!=1.0 || tex_v_scale!=1.0){
				glScalef(tex_u_scale,tex_v_scale,1.0);
			}
	
			/* ***!ES***
			// if spheremap flag=true then flip tex
			if(tex_flags&64!=0){
				glScalef(1.0,-1.0,-1.0);
			}
				
			// if cubemap flag=true then manipulate texture matrix so that cubemap is displayed properly 
			if(tex_flags&128!=0){

				glScalef(1.0,-1.0,-1.0);
					
				// get current modelview matrix (set in last camera update)
				float mod_mat[16];
				glGetFloatv(GL_MODELVIEW_MATRIX,&mod_mat[0]);

				// get rotational inverse of current modelview matrix
				Matrix new_mat;
				new_mat.LoadIdentity();
					
				new_mat.grid[0][0] = mod_mat[0];
				new_mat.grid[1][0] = mod_mat[1];
				new_mat.grid[2][0] = mod_mat[2];

				new_mat.grid[0][1] = mod_mat[4];
				new_mat.grid[1][1] = mod_mat[5];
				new_mat.grid[2][1] = mod_mat[6];

				new_mat.grid[0][2] = mod_mat[8];
				new_mat.grid[1][2] = mod_mat[9];
				new_mat.grid[2][2] = mod_mat[10];
				
				glMultMatrixf(&new_mat.grid[0][0]);

			}
			*/
								
		}
		
	}

	// draw tris		
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glMultMatrixf(&mat.grid[0][0]);
	RecreateROAM();
	glPopMatrix();

	// disable all texture layers
	for(int ix=0;ix<tex_count;ix++){
	
		glActiveTexture(GL_TEXTURE0+ix);
		glClientActiveTexture(GL_TEXTURE0+ix);
			
		// reset texture matrix
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
			
		glDisable(GL_TEXTURE_2D);
			
		// ***!ES***
		//glDisable(GL_TEXTURE_CUBE_MAP);
		//glDisable(GL_TEXTURE_GEN_S);
		//glDisable(GL_TEXTURE_GEN_T);
		//glDisable(GL_TEXTURE_GEN_R);
	
	}

	if (fog==true){
		glEnable(GL_FOG);
	}


}

void Terrain::RecreateROAM(){

	/*xcf = eyepoint->EntityX();
	ycf = eyepoint->EntityY();
	zcf = -eyepoint->EntityZ();*/

	TFormPoint(eyepoint->EntityX(), eyepoint->EntityY(), eyepoint->EntityZ(), 0, this);
	xcf = tformed_x;
	ycf = tformed_y;
	zcf = -tformed_z;

	int i;
	float v[4][3];
	
			
	v[0][0] = 0.0; 		v[0][2] = size;
	v[1][0] = size; 	v[1][2] = size;
	v[2][0] = size; 	v[2][2] = 0;
	v[3][0] = 0.0; 		v[3][2] = 0;

	// diamond radius - apply entity scale
	float rx=EntityScaleX(true);
	float ry=EntityScaleY(true);
	float rz=EntityScaleZ(true);
	if(rx>=ry && rx>=rz){
		dradius=abs(rx);
	}else if(ry>=rx && ry>=rz){
		dradius=abs(ry);
	}else{
		dradius=abs(rz);
	}


	tmat = MQ_GetMatrix(true);



/*	if(c_col_tree!=NULL){
		C_DeleteColTree(c_col_tree);
		c_col_tree=NULL;
	}
*/
	mesh_info=C_NewMeshInfo();
	triangleindex = 0;

	glBegin(GL_TRIANGLES);
			
	/* recurse on the two base triangles */
	drawsub(0, v[0], v[1], v[2]);
	drawsub(0, v[2], v[3], v[0]);

	glEnd();
/*	c_col_tree=C_CreateColTree(mesh_info);
	C_DeleteMeshInfo(mesh_info);
*/	delete tmat;


}

void Terrain::drawsub(int l, float v0[], float v1[], float v2[]){

	float vc[3]; 	/* New (split) vertex */
	float ds;	/* maximum midpoint displacement */
	float dx,dy,dz;	/* difference vector */
	float rd;	/* squared sphere bound radius */
	float rc;	/* squared distance from vc To camera position */
	
	if (l < ROAM_LMAX) {
		/* compute split point of base edge */				
		vc[0] = (v0[0] + v2[0]) / 2;
		vc[2] = (v0[2] + v2[2]) / 2;
		vc[1] = height[(int)(vc[0]*size+ vc[2])] * vsize;

	
		ds = level2dzsize[l];
	
		/* compute radius of diamond bounding sphere (squared) */
		float x,y,z;
		x = vc[0];
		y = vc[1];
		z = vc[2];
		rd = 0.0;
		dx = v0[0] - x;
		dy = v0[1] - y;
		dz = v0[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		dx = v1[0] - x;
		dy = v1[1] - y;
		dz = v1[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		dx = v2[0] - x;
		dy = v2[1] - y;
		dz = v2[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		rd = sqrt(rd)*dradius;
					
		int i, m;
		m = 1;

		/*TFormPoint(vc[0],vc[1],vc[2],this,0);
		float vcx=tformed_x;
		float vcy=tformed_y;
		float vcz=tformed_z;*/

		float vcx=vc[0];
		float vcy=vc[1];
		float vcz=-vc[2];
		tmat->TransformVec(vcx, vcy, vcz, 1);

		for (int i = 0 ;i<= 5; i++){
			float d = eyepoint->frustum[i][0] * vcx + eyepoint->frustum[i][1] * vcy - eyepoint->frustum[i][2] * vcz + eyepoint->frustum[i][3];
			if (d <= -rd) return;//{ds=ds/10; break;}
			m = m << 1;
		}
	
		/* compute distance from split point To camera (squared) */
		dx = vc[0] - xcf;
		dy = vc[1] - ycf;
		dz = vc[2] - zcf;
		rc = dx*dx+dy*dy+dz*dz;
					
		/* If not error large on screen, recursively split */
		if ((ds * ds) > (rc * 0.000000003)) {/*<---------terrain detail here*/
			drawsub(l + 1, v1, vc, v0);
			drawsub(l + 1, v2, vc, v1);
			return;
		}
		
	 }
	float uv[3];

	float ax,ay,az,bx,by,bz;
	float nx,ny,nz,ns;
	ax = v1[0]-v0[0];
	ay = v1[1]-v0[1];
	az = v1[2]-v0[2];
	bx = v2[0]-v1[0];
	by = v2[1]-v1[1];
	bz = v2[2]-v1[2];
	nx = ( ay * bz ) - ( az * by );
	ny = ( az * bx ) - ( ax * bz );
	nz = ( ax * by ) - ( ay * bx );
	ns = sqrt( nx * nx + ny*ny + nz*nz );
	if (ns != 0) ns = 1;
	nx /= ns;
	ny /= ns;
	nz /= ns;


									
	uv[0]=v0[0]; uv[1]=v0[2]; uv[2]=0;
	glMultiTexCoord2f(GL_TEXTURE0, uv[0], uv[1]);
	glMultiTexCoord2f(GL_TEXTURE1, uv[0], uv[1]);
	glNormal3f(nx,ny,nz);
	glTexCoord2fv(&uv[0]);
	glVertex3fv(&v0[0]);
		
	uv[0]=v1[0]; uv[1]=v1[2]; uv[2]=0;
	glMultiTexCoord2f(GL_TEXTURE0, uv[0], uv[1]);
	glMultiTexCoord2f(GL_TEXTURE1, uv[0], uv[1]);
	glNormal3f(nx,ny,nz);
	glTexCoord2fv(&uv[0]);
	glVertex3fv(&v1[0]);
		
	uv[0]=v2[0]; uv[1]=v2[2]; uv[2]=0;
	glMultiTexCoord2f(GL_TEXTURE0, uv[0], uv[1]);
	glMultiTexCoord2f(GL_TEXTURE1, uv[0], uv[1]);
	glNormal3f(nx,ny,nz);
	glTexCoord2fv(&uv[0]);
	glVertex3fv(&v2[0]);

	//add to collisiontree
/*	C_AddVertex(mesh_info,v0[0],v0[1],-v0[2],0);
	C_AddVertex(mesh_info,v1[0],v1[1],-v1[2],0);
	C_AddVertex(mesh_info,v2[0],v2[1],-v2[2],0);
	C_AddTriangle(mesh_info, triangleindex, triangleindex*3+2, triangleindex*3+1, triangleindex*3+0, 0);
	triangleindex++;
*/	
						
}


Terrain* Terrain::LoadTerrain(string filename,Entity* parent_ent){
	//filename=Strip(filename); // get rid of path info

	if(File::ResourceFilePath(filename)==""){
		cout << "Error: Cannot Find Terrain: " << filename << endl;
		return NULL;
	}
	
	string filename_left=Left(filename,Len(filename)-4);
	string filename_right=Right(filename,3);
	
	const char* c_filename_left=filename_left.c_str();
	const char* c_filename_right=filename_right.c_str();


	unsigned char* buffer;
	
	int width,height;

	buffer=stbi_load(filename.c_str(),&width,&height,0,1);
	Terrain* terr=Terrain::CreateTerrain(width, parent_ent);


	terr->vsize=30;
	terr->size=width;
	terr->height=new float[(width+1)*(width+1)];

	for (int x=0;x<=terr->size-1;x++){
		for (int y=0;y<=terr->size-1;y++){
			terr->height[x*(int)terr->size+y]=((float)*buffer)/255.0;
			buffer++;		
		}
	}

	return terr;
}

void Terrain::ModifyTerrain (int x, int z, float new_height){
	height[x*(int)size+z]=new_height;
}

void Terrain::TreeCheck(CollisionInfo* ci){
	Ray=ci->coll_line;
	radius=ci->radius;

	TFormPoint(Ray.o.x, Ray.o.y, Ray.o.z, 0, this);
	xcf = tformed_x;
	ycf = tformed_y;
	zcf = -tformed_z;

	/*TFormVector(Ray.d.x, Ray.d.y, -Ray.d.z, 0, this);
	Ray.d.x = tformed_x;
	Ray.d.y = tformed_y;
	Ray.d.z = -tformed_z;*/


	int i;
	float v[4][3];
	
			
	v[0][0] = 0.0; 		v[0][2] = size;
	v[1][0] = size; 	v[1][2] = size;
	v[2][0] = size; 	v[2][2] = 0;
	v[3][0] = 0.0; 		v[3][2] = 0;

	// diamond radius - apply entity scale
	float rx=EntityScaleX(true);
	float ry=EntityScaleY(true);
	float rz=EntityScaleZ(true);
	if(rx>=ry && rx>=rz){
		dradius=abs(rx);
	}else if(ry>=rx && ry>=rz){
		dradius=abs(ry);
	}else{
		dradius=abs(rz);
	}


	tmat = MQ_GetMatrix(true);



	if(c_col_tree!=NULL){
		C_DeleteColTree(c_col_tree);
		c_col_tree=NULL;
	}

	mesh_info=C_NewMeshInfo();
	triangleindex = 0;

			
	/* recurse on the two base triangles */
	col_tree_sub(0, v[0], v[1], v[2]);
	col_tree_sub(0, v[2], v[3], v[0]);

	c_col_tree=C_CreateColTree(mesh_info);
	C_DeleteMeshInfo(mesh_info);
	delete tmat;



}

void Terrain::col_tree_sub(int l, float v0[], float v1[], float v2[]){

	float vc[3]; 	/* New (split) vertex */
	float ds;	/* maximum midpoint displacement */
	float dx,dy,dz;	/* difference vector */
	float rd;	/* squared sphere bound radius */
	float rc;	/* squared distance from vc To camera position */
	
	if (l < ROAM_LMAX) {
		/* compute split point of base edge */				
		vc[0] = (v0[0] + v2[0]) / 2;
		vc[2] = (v0[2] + v2[2]) / 2;
		vc[1] = height[(int)(vc[0]*size+ vc[2])] * vsize;

	
		ds = level2dzsize[l];
	
		/* compute radius of diamond bounding sphere (squared) */
		float x,y,z;
		x = vc[0];
		y = vc[1];
		z = vc[2];
		rd = 0.0;
		dx = v0[0] - x;
		dy = v0[1] - y;
		dz = v0[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		dx = v1[0] - x;
		dy = v1[1] - y;
		dz = v1[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		dx = v2[0] - x;
		dy = v2[1] - y;
		dz = v2[2] - z;
		rc = dx * dx + dy * dy + dz * dz;
		if (rc > rd) {rd = rc;}
		rd = sqrt(rd)*dradius;
					
		int i, m;
		m = 1;

		/*TFormPoint(vc[0],vc[1],vc[2],this,0);
		float vcx=tformed_x;
		float vcy=tformed_y;
		float vcz=tformed_z;*/

		float vcx=vc[0];
		float vcy=vc[1];
		float vcz=-vc[2];
		tmat->TransformVec(vcx, vcy, vcz, 1);


		/*Is triangle on the collision line?*/

		Vector Sphere;
		Sphere.x=vcx;
		Sphere.y=vcy;
		Sphere.z=vcz;
		Line dst( Sphere-Ray.o,Ray.d );

		float a=dst.d.dot(dst.d);
		if( !a ) return;
		float b=dst.o.dot(dst.d)*2;
		float c=dst.o.dot(dst.o)-rd*rd;
		float d=b*b-4*a*c;

		if (d<0) return;

	
		/* compute distance from split point To camera (squared) */
		dx = vc[0] - xcf;
		dy = vc[1] - ycf;
		dz = vc[2] - zcf;
		rc = dx*dx+dy*dy+dz*dz;
					
		/* If not error large on screen, recursively split */
		if ((ds * ds) > (rc * 0.000000003)) {/*<---------terrain detail here*/
			col_tree_sub(l + 1, v1, vc, v0);
			col_tree_sub(l + 1, v2, vc, v1);
			return;
		}
		
	 }


	//add to collisiontree
	C_AddVertex(mesh_info,v0[0],v0[1],-v0[2],0);
	C_AddVertex(mesh_info,v1[0],v1[1],-v1[2],0);
	C_AddVertex(mesh_info,v2[0],v2[1],-v2[2],0);
	C_AddTriangle(mesh_info, triangleindex, triangleindex*3+2, triangleindex*3+1, triangleindex*3+0, 0);
	triangleindex++;
}

float Terrain::TerrainHeight (int x, int z){
	return height[x*(int)size+z];
}

float Terrain::TerrainX (float x, float y, float z){
	TFormPoint(x, y, z, 0, this);
	return tformed_x;
}

float Terrain::TerrainZ (float x, float y, float z){
	TFormPoint(x, y, z, 0, this);
	return tformed_z;
}

