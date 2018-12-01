#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>


// The height and width of the window
const int WIDTH= 1000;
const int HEIGHT= 1000;

enum KeyPressSurfaces
  {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
  };

// Returns true is proper starting conditions are met
bool init();

// Returns true if the media needed is loaded properly
bool media();

// Closes the window
void close();

// Loads images
SDL_Surface* loadSurface(std::string path);

//images and keypresses
SDL_Surface* keyPress[KEY_PRESS_SURFACE_TOTAL];

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Surface* startscreen = NULL;

SDL_Surface* curSurface = NULL;

SDL_Surface* exitOut = NULL;


bool init(){
  bool success = true;

  if (SDL_Init (SDL_INIT_VIDEO)<0){
    success = false;
    printf("SDL could not be iniliazed, ERROR: %s\n",
	   SDL_GetError());
  }
  else {
    window = SDL_CreateWindow("Space Invaders", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL) {
      printf("SDL could not be iniliazed, ERROR: %s\n",SDL_GetError());
      success = false;
    }
    else { screenSurface = SDL_GetWindowSurface(window);
  }
  }
    return success;
}

  bool media(){
    bool success = true;

    keyPress[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("startingScreen.bmp");

     if (keyPress[KEY_PRESS_SURFACE_DEFAULT]== NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
     }

//loads the image when up arrow is pressed
keyPress[KEY_PRESS_SURFACE_UP] = loadSurface("secondScreen.bmp");

if (keyPress[KEY_PRESS_SURFACE_UP]== NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
}

//loads the image when the down arrow is pressed
keyPress[KEY_PRESS_SURFACE_DOWN] = loadSurface("secondScreen.bmp");

if (keyPress[KEY_PRESS_SURFACE_DOWN]== NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
 }

// loads the imahe when the left arrow is pressed
keyPress[KEY_PRESS_SURFACE_LEFT] = loadSurface("secondScreen.bmp");

if (keyPress[KEY_PRESS_SURFACE_LEFT]== NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
}
// loads the image when the right arrow is pressed
keyPress[KEY_PRESS_SURFACE_RIGHT] = loadSurface("secondScreen.bmp");
if (keyPress[KEY_PRESS_SURFACE_RIGHT]== NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false; }

   return success;
  }


  void close(){
//deallocates the surface
    for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; ++i){
 SDL_FreeSurface (keyPress [i]);
 keyPress[i] = NULL;
}

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
  }

SDL_Surface* loadSurface(std::string path){
SDL_Surface* loadedSur = SDL_LoadBMP(path.c_str());
if (loadedSur == NULL ){
printf( "Unable to load image %s!");
}
return loadedSur;
}



  int main(int argc, char* args[]){
    // Checks if all requirments are met
    if(!init() ){
    printf("Failed to initialized!\n" );
    }
    else {
      if (!media() ){
	printf("Failed to load media \n" );
      }
      else{
	bool quit = false;

	SDL_Event e;

        curSurface = keyPress[KEY_PRESS_SURFACE_DEFAULT];

	while(!quit){
	  while( SDL_PollEvent( &e ) != 0 ){
	    if (e.type == SDL_QUIT){
	      quit = true;
	}
        else if(e.type == SDL_KEYDOWN){
switch (e.key.keysym.sym){
//checks if the up has been pressed
      case SDLK_UP: curSurface = keyPress[KEY_PRESS_SURFACE_UP];
       break;

//checks if the down has been pressed
case SDLK_DOWN: curSurface = keyPress[KEY_PRESS_SURFACE_DOWN];
       break;

//checks if the right has been pressed
case SDLK_RIGHT: curSurface = keyPress[KEY_PRESS_SURFACE_RIGHT];
       break;

//checks if the left has been pressed
case SDLK_LEFT: curSurface = keyPress[KEY_PRESS_SURFACE_LEFT];
       break;

default:
curSurface = keyPress[KEY_PRESS_SURFACE_DEFAULT];
break;
}
}

      }
	  SDL_BlitSurface( curSurface, NULL, screenSurface, NULL );
	  SDL_UpdateWindowSurface( window );
	}
      }
    }
    close();
    return 0;
  }

