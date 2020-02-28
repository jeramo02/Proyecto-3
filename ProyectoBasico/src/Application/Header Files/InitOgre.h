//
// Copyright (c) 2007-2011, 'Madmarx' from the ogre3D forums (ogre3D.org).
// All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of its author nor the names of its contributors
//       may be used to endorse or promote products derived from this software
//       without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ------------------------------------------------------------------------------//
// ------------------------------------------------------------------------------//

// Here is exactly the same as the previous tutorial, but I have reorganized it a bit.
// Things are separated between a class that does the initialisation,
// and a main() that makes the application run.
// If you don't understand what a class is, or what #ifndef means, you should learn C++ first :-).
#ifndef SIMPLEOGREINIT_H
#define SIMPLEOGREINIT_H

#include <memory>

// Here I do a forward declaration. Check a C++ lesson if you want to know more on this subject.
// Basically, I just declare some classes I want to use only as a pointer or reference in the .h,
// it makes compilation faster, among many other benefits.
// Then I will still have to do the include corresponding to these classes in the .cpp file.
namespace Ogre {
	class RenderWindow;
	class RenderSystem;
	class Root;
	class FileSystemLayer;
	//class String;
}

namespace OgreEasy {
	/// This class contains a function that help to initialise Ogre3d in one go.
	class SimpleOgreInit {
	private:
		// These functions will prevent the user and the class to creates copies of the original object.
		SimpleOgreInit(const SimpleOgreInit& s);
		SimpleOgreInit& operator=(const SimpleOgreInit& s);

		// Metodos para iniciar Ogre
		void createRoot();
		void setup();
		bool oneTimeConfig();

		// Metodos para cargar los recursos
		void locateResources();
		void loadResources();

	public:
		// The constructor does nothing but initialisation to NULL or empty values.
		SimpleOgreInit();
		~SimpleOgreInit();

		///\brief  This function will create 1 ogre root and 1 window and store them in its members mRoot and mWindow.
		///\return false if an error occurs, true otherwise.
		void initOgre();

	public:
		// I put the member in public because there is no need to put them private in these tutorials.
		// It will allow very simple access to these useful members.
		std::auto_ptr<Ogre::Root> mRoot;
		///\brief the window created in the initOgre(). NULL otherwise.
		Ogre::RenderWindow* mWindow;

		//-----------Carga de datos-------------
		// File system abstraction layer
		Ogre::FileSystemLayer* mFSLayer = nullptr;

		// Variable para hacer las rutas relativas al directorio de la soluci�n
		//Ogre::String mSolutionPath;
	};
}

#endif