/*
 *  terrain.h
 *  minib3d
 *
 *
 */

#ifndef TERRAIN_H
#define TERRAIN_H


#include <iostream>
#include <string>

using namespace std;

const int ROAM_LMAX = 20; 		//<-----------terrain detail here	

class Terrain : public Entity{
private:
	Matrix* tmat;
	float dradius;

public:
	static list<Terrain*> terrain_list;
	static int triangleindex;
	static MeshInfo* mesh_info;

	float size; 				//terrainsize
	float vsize; 				//terrainheight

	float level2dzsize[ROAM_LMAX+1]; 	/* Max midpoint displacement per level     */
	float* height; 				//heightmap
	float xcf,ycf,zcf; 			//used to store camera position
	Camera* eyepoint; 			//reference to camera
	MeshCollider* c_col_tree;


	static Terrain* CreateTerrain(int tsize=0, Entity* parent_ent=NULL);
	static Terrain* LoadTerrain(string filename,Entity* parent_ent=NULL);
	Terrain* CopyEntity(Entity* parent_ent=NULL);
	void UpdateTerrain();
	void RecreateROAM();
	void drawsub(int l, float v0[], float v1[], float v2[]);
	void ModifyTerrain (int x, int z, float height);
	void TreeCheck(CollisionInfo* ci);
	void col_tree_sub(int l, float v0[], float v1[], float v2[]);
	float TerrainHeight (int x, int z);
	float TerrainX (float x, float y, float z);
	float TerrainZ (float x, float y, float z);

	Terrain(){
		size=0;
	};



	


};

#endif
