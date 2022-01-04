;
#include <map>
#include <vector>



class ProgramObject;
class Surface;

//list<ProgramObject*> ProgramObjectList;

class ShaderObject{
	public:
	static list<ShaderObject*> ShaderObjectList;

	int ShaderObj;
	int ShaderType;				// 1 = Vert, 2 = Frag
	list<ProgramObject*> Attached;		// Shaders can be attached, or 'referenced by', more than 1 ProgramObject
	string shaderName;

	static ShaderObject* CreateVertShader(string shaderFileName);
	static ShaderObject* CreateFragShader(string shaderFileName);
	static ShaderObject* CreateVertShaderFromString(string shadercode);
	static ShaderObject* CreateFragShaderFromString(string shadercode);
	void DeleteVertShader(ShaderObject* vShader);
	void DeleteFragShader(ShaderObject* fShader);

};

class ProgramObject{
	public:
	static list<ProgramObject*> ProgramObjectList;

	int Program;		// The ProgramObject
	list<ShaderObject*> vList;	// Vertex shader list. A List of what Vert shaders are attached to this ProgramObject
	list<ShaderObject*> fList;	// Frag shader list. A List of what Frag shaders are attached to this ProgramObject
	string progName;
	
	int vertShaderCount;
	int fragShaderCount;
	
	map<string,int> TypeMap;

	static ProgramObject* Create(string name = "null");

	void Activate();
	void DeActivate();
	void RefreshTypeMap();

	// Get the Uniform Variable Location from a ProgramObject
	int GetUniLoc(string name);

	// Get the Attribute Variable Location from a ProgramObject
	int GetAttribLoc(string name);
#ifndef GLES2
	/*void SetParameter1S(int name, float v1);
	void SetParameter2S(int name, float v1, float v2);
	void SetParameter3S(int name, float v1, float v2, float v3);
	void SetParameter4S(int name, float v1, float v2, float v3, float v4);*/
#endif

	//------------------------------------------------------------
	// Int Parameter
	
	/*void SetParameter1I(int name, int v1);
	void SetParameter2I(int name, int v1, int v2);
	void SetParameter3I(int name, int v1, int v2, int v3);
	void SetParameter4I(int name, int v1, int v2, int v3, int v4);*/
	
	//----------------------------------------------------------------------------------
	// Int Vectors

	/*void SetVector1I(int name, int* v1);
	void SetVector2I(int name, int* v1);
	void SetVector3I(int name, int* v1);
	void SetVector4I(int name, int* v1);*/
				
	//-------------------------------------------------------------------------------------
	// Double Parameter ( automatically Attributes, because Uniform doubles does not exist)
	
#ifndef GLES2
	/*void SetParameter1D(int name, double v1);
	void SetParameter2D(int name, double v1, double v2); 
	void SetParameter3D(int name, double v1, double v2, double v3);
	void SetParameter4D(int name, double v1, double v2, double v3, double v4);*/
#endif

	//-------------------------------------------------------------------------------------
	//  Array Parameter
	void SetParameterArray(int name, Surface* surf, int vbo);
	void SetParameterArray(int name, vector<float>* vertices, int vbo);

	//-------------------------------------------------------------------------------------
	// Float Parameter

	/*void SetParameter1F(int name, int ParameterType, float v);
	void SetParameter2F(int name, int ParameterType, float v1, float v2);
	void SetParameter3F(int name, int ParameterType, float v1, float v2, float v3);
	void SetParameter4F(int name, int ParameterType, float v1, float v2, float v3, float v4);*/

	//---------------------------------------------------------------------------------------------------
	// Float Vectors


	/*void SetVector1F(int name, float* v1);
	void SetVector2F(int name, float* v1);
	void SetVector3F(int name, float* v1);
	void SetVector4F(int name, float* v1);*/

	//--------------------------------------------------------------------------------------------------
	// Matrices

	/*void SetMatrix2F(int name, float* m);
	void SetMatrix3F(int name, float* m);
	void SetMatrix4F(int name, float* m);*/


	//----------------------------------------------------------
	//Attach & Link a Vertex Shader Object to this ProgramObject
	//----------------------------------------------------------
	int AttachVertShader(ShaderObject* myShader);

	//------------------------------------------------------------
	//Attach & Link a Fragment Shader Object to this ProgramObject
	//------------------------------------------------------------
	int AttachFragShader(ShaderObject* myShader);

	//-------------------------------------------------------
	//Detach a VertShader:tShaderObject from a tProgramObject
	//-------------------------------------------------------
	void DetachVertShader(ShaderObject* vShader);

	//-------------------------------------------------------
	//Detach a FragShader:tShaderObject from a tProgramObject
	//-------------------------------------------------------
	void DetachFragShader(ShaderObject* fShader);

};

