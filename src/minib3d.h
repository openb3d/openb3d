/*
 *  iminib3d.h
 *  iminib3d
 *
 *  Created by Simon Harrison.
 *  Copyright Si Design. All rights reserved.
 *
 */

// iMiniB3D v0.3
// -------------

// iMiniB3D Terms of Use
// ---------------------

// You are free to use iMiniB3D as you wish.

// iMiniB3D Info
// ------------- 

// You will more than likely need a good grasp of C++ to use iMiniB3D effectively.
// There's no iMiniB3D-specific documentation bar what you're reading at the moment.
// Please see the header files for a list of available functions.
// There's mostly the same functions available as in MiniB3D for BlitzMax, with a few differences here and there. See 'MiniB3D -> iMiniB3D Differences' below.
// See the Blitz3D online manual at www.blitzbasic.com for Blitz3D documentation (which MiniB3D and iMiniB3D is based on)

// iMiniB3D is objected-oriented. There's no procedural interface available like there is for MiniB3D.
// So instead of PositionEntity(entity,x,y,z), you must always use entity->PositionEntity(x,y,z).
// For the 'Create' commands, static functions are used, e.g. Mesh* mesh=Mesh::CreateMesh(), Sprite* sprite=Sprite::CreateSprite()

// Please feel free to email me at si@si-design.co.uk about anything. I will try to help if possible.

// Getting Started
// ---------------

// First of all, make sure you have Xcode installed and the iPhone SDK. Xcode can be found on your Mac OS X install disc. The iPhone SDK can be downloaded from the Apple developer website.
// Load the iminib3d/iminib3d.xcode project file.

// You will need to build the iMiniB3D lib before you can run any programs. There are two ways of doing this:
// a) Select iMiniB3D from the 'Active Target' drop down box in the top left-hand corner. Click the 'Build' icon. OR:
// b) Right-click the 'iminib3d' node which is nested in the 'Target' node in the 'Groups & Files' tree-menu to the left, and select 'Build "iminib3d"' from the pop-up menu.
// Note you will bave to build iminib3d for each different build mode - either debug or release, and either simulator or device, giving a total of four combinations.
// Change the build debug/release mode by using the 'Active Build Configuation' drop down box at the top.
// Change the simulator/device mode by using the 'Project' -> 'Set Active SDK' Xcode menu bar option.

// Once you have built iMiniB3D, you can build and run the other programs. Select a target from the 'Active Target' drop down box, and click the 'Build and Go' icon.

// Creating a New App
// ------------------

// Creating a new app can be a bit tricky. Follow the stages and steps below to do so.
// Note: If in the instructions below it says to 'right click' but you are only using a one button mouse, then hold down the ctrl key and press the left mouse button intead.
// Note: A group doesn't equal a folder! Xcode uses it's own internal groups to organise everything, which are shown as folder icons in the 'Groups & Files' tree menu to the left.
// These don't necessarily equate to the same folder layout on your hard drive, however. Something to keep in mind.

// Stage 1. New Target
// 1. Create a new target. Do this by right clicking the top 'iminib3d' project node in the 'Groups & Files' tree menu to the left, and selecting 'Add' -> 'New Target' from the pop-up menu.
// 2. Select 'iPhone OS' -> 'Application' and click 'Next'. Enter a target name and click 'Finish'.
// 3. Now you need to add to the list of linked libraries. Click the plus icon in the bottom left-hand corner, underneath the 'Linked Libraries' box.
// 4. Expand the list of available libraries by clicking the down arrows.
// 5. Add the following libraries - you can select multiple libraries at once by holding down the Apple key.
// libiminib3d.a
// CoreFoundation.framework
// CoreGraphics.framework
// Foundation.framework
// OpenGLES.framework
// Quartzcore.framework
// UIKit.framework
// 6. Close the window.
// 7. The newly created target will appear in the tree menu. It will be nested within the 'Targets' node.
// 8. If you wish to change the target's linked libraries and other targets in future, right-click the target node, and select 'Get Info' from the pop-up menu.

// Stage 2. New Folder/Files
// 1. Right-click the 'iminib3d' project node at the top of the 'Groups & Files' tree menu, and select 'Add' -> 'Existing Files' from the pop-up menu.
// 2. Select 'New Folder', and enter a folder name that matches your target name. Click 'Create', then click 'Add'.
// 3. Make sure the 'Copy items into destination group's folder (if needed)' checkbox is not ticked, and make sure the 'Recursively create groups for any added folders' checkbox is ticked.
// 4. In the 'Add to Targets' box, make sure your new target is ticked, and no others. Click 'Add'.
// 5. Your new group should now appear in the tree menu, underneath the 'iminib3d' project node.
// 6. Right-click the new group node, and select 'Add' -> 'New File' from the pop-up menu.
// 7. Choose the 'Mac OS X' -> 'C and C++' -> 'C++ File' option and click 'Next'.
// 8. Enter 'game.mm' as your file name. Make sure the 'Also create "game.h"' checkbox is ticked, and make sure the correct target is ticked in the 'Targets:" box. Click 'Finish'.
// 9. Your new files are now created and available in the tree menu, nested within your group node.

// Stage 3. Adding Necessary Source Files and Code
// 1. Using the 'Groups & Files' tree menu to navigate between source code files, copy and paste the contents of 'game.h' and 'game.mm' from the 'empty' group to your newly created 'game.h' amd 'game.mm' files in your own group.
// 2. These files contain the bare minimum code needed to run an iminib3d app - a Game class, with Init, Run and End functions.
// 3. There are three other source code files you need to add to your target - these are the three .m/.mm files in the 'Game' group which provide all the necessary Objective-C and Apple code to get your app up and running.
// 4. To add these to your target, select them all (using the Apple key to multi-select), and drag them into your target's 'Compile Sources' sub-group in the tree menu. You will need to expand your target's node first.

// Stage 4. Adding the MainWindow.xib File
// 1. Your new app is nearly set up. You now just need to add the MainWindow.xib file to your target, which contains information about your window view. Without it, nothing will be displayed on screen.
// 2. To do this, select your target node in the 'Groups & Files' tree menu. Expand the node so you can see the three sub-groups - 'Copy Bundle Resources', 'Compile Sources' and 'Link Binary with Libraries'.
// 3. Now drag the 'MainWindow.xib' node which should be directly above the 'Targets' node, and move it on top of your target's 'Copy Bundle Resources' group. It will then be copied there.
// 4. That's it! You should now be able to build and run your app. Select your new target in the 'Active Target' drop down box in the top left-hand corner and select the 'Build and Go' icon. All going well, it should build and run correctly.
// 5. If you get a 'no executable file' exists error or similar, just try changing the release/debug mode, and try again.

// Stage 5. Adding Resources
// 1. Resources are the media files that your game will load.
// 2. Add a resources group for your app. To do this, right click the 'Resources' group node in the 'Groups & Files' tree menu, and select 'Add -> Existing Files' from the pop-up menu. Select your app's folder and click 'Add'.
// 3. Make sure the 'Copy items into destination group's folder (if needed)' checkbox is not ticked, and make sure the 'Recursively create groups for any added folders' checkbox is ticked.
// 4. In the 'Add to Targets' box, make sure your new target is ticked, and no others. Click 'Add'.
// 5. Your new group should now appear in the tree menu, nested within the 'resources' group node.
// 6. Now, to add media files to your app,  right-click on your new resources group node, and select 'Add' -> 'Existing Files' from the pop-up menu.
// 7. Select your media files from the file view, using the Apple key to select more than one at once. Click 'Add'.
// 8. Make sure the 'Copy items into destination group's folder (if needed)' checkbox is ticked, and make sure that your target is ticked in the 'Add to Targets' box, and no others. Click 'Add'.
// 9. The media files will now be copied into the folder your created earlier, and in the tree menu, will be shown in your resources group, and in your target's 'Copy Bundle Resources' group.
// 10. You can now load your media files.

// Building an App on Your Own Device
// ----------------------------------

// By default iMiniB3D is set up to build apps on my own device. To build apps on your own device, assuming your device is correctly set up with a provisioning profile, follow these steps:

// Stage 1. Editing the Project Settings for Future Apps (new apps will inherit these settings)
// 1. Right-click the 'iminib3d' project icon in the 'Groups and Files' tree menu and select 'Get Info' from the pop-up menu.
// 2. Click the 'Build' tab and make sure 'All Configurations' is selected from the top-left drop-down menu.
// 3. Scroll down to the 'Code Signing' section, then for the 'Code Signing Identity' setting, change the left-hand side setting to 'Any iPhone OS Device' and the right-hand side value to your developer identity.

// Stage 2. Editing Existing App Settings (existing iminib3d apps must be changed individually)
// 1. Right-click the individual target icon in the tree menu and select 'Get Info'.
// 2. Follow step 2 above.
// 3. Follow step 3 above.

// Hints and Tips
// --------------

// By default the OpenGL view is displayed in portrait mode
// For landscape mode, rotate your camera on the z axis by 90 degrees - e.g. cam->RotateEntity(0,0,90)
// For best camera FOV, you will need to change your camera's CameraZoom - for Portrait set it to 1.75, for landscape set it to 1.5

// MiniB3D -> iMiniB3D Differences
// -------------------------------

// + iMiniB3D features built-in support for dynamic sphere -> dynamic mesh collisions - set any destination mesh's 'dynamic' flag to true to activate. See test app for example. Don't expect miracles, however!
// - Spheremapping, cubemapping not available in iMiniB3D
// - Anim textures not supported in iMiniB3D
// ~ TextureFilter has been renamed to AddTextureFilter in iMiniB3D
// ~ CopyEntity fully copies a mesh, so there is no shared surface data like there is in Blitz3D. You now cannot use the Mesh commands to affect all copied entities that share the same surface data

// v0.3
// ----

// fixed Rnd, Rand
// tidied string helper commands, added Split
// added MeshColor, MeshRed, MeshGreen, MeshBlue, MeshAlpha and SurfaceColor, etc, commands for setting all vertex colors in a mesh/surface at once
// optimised Mesh->Render() so that less OpenGL funcitons calls are made
// fixed AddMesh - was adding duplicate triangles.
// fixed ClearWorld - didn't work
// added applicationWillTerminate method to application delegate, which calls game->End() just before program quits
// changed ReadFile/WriteFile - they now return a NULL File object is unsuccessful, rather than ending program 
// fixed Millisecs - didn't work
// fixed CopyEntity bug - meshes are now fully copied - i.e. no shared surface data.
// fixed EntityScaleY bug (non-global call returned EntityScaleX)
// added TextureFilter functions (TextureFilter renamed to AddTextureFilter)
// added recursive flag to all entity material functions
// added EntityRed, EntityGreen, EntityBlue for when you wish to set entity color components separately
// added 'sprite batch rendering' - will render all sprites using the same texture at once, using a single surface. To activate, use SpriteRenderMode sprite,2

// v0.2
// ----

// added Rnd, Rand, SeedRnd
// added CameraProject, ProjectedX/Y/Z
// reenabled vbo=true as default behaviour
// reenabled LoadMesh. LoadAnimMesh was used in place before
// added UpdateAllEntities, for faster UpdateWorld/RenderWorld - instead of iterating through every entity, only 'root' entities are iterated through (attached to hidden 'root root' entity) and their children - if an entity is hidden, that entities' children aren't iterated through
// added file write functions
// added CopyEntity
// added CreateCone
// added Tilt functions - see tilt app
// added various Touch functions
// fixed FreeEntity bug - camera wasn't being freed from camera list
// added SpriteViewModes 3,4
// fixed Instr bug
// renamed text to string_helper and helper to maths_helper
// added CountAllChildren, GetChildFromAll
// added FindEntity
// fixed FreeEntity bug
// added missing picking commands
// fixed blue ambient light bug
// added Texture::CreateTextTexture
// added EntityClass
// added mipmapping

#ifndef IMINIB3D_H
#define IMINIB3D_H

#include "global.h"
#include "entity.h"
#include "camera.h"
#include "light.h"
#include "pivot.h"
#include "bone.h"
#include "mesh.h"
#include "sprite.h"
#include "sprite_batch.h"
#include "surface.h"
#include "brush.h"
#include "texture.h"
#include "texture_filter.h"
#include "animation.h"
#include "animation_keys.h"
#include "model.h"
#include "pick.h"
#include "collision2.h"
#include "tree.h"
#include "collision.h"
#include "matrix.h"
#include "quaternion.h"
#include "geom.h"
#include "project.h"
#include "maths_helper.h"
#include "string_helper.h"
#include "file.h"
#include "bank.h"
#include "terrain.h"
//#include "misc.h"
#include "touch.h"
#include "tilt.h"
//#include "Texture2D.h"
//#include "MachTimer.h"

#include <iostream>
using namespace std;

#endif
