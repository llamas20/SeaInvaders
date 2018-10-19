#include <SDL2/SDL.h>
#include <stdio.h>

const int WIDTH= 958;
const int HEIGHT= 536;

// Checks to see if all of the conditions for opening a window are ture
bool init();

// Checks to see if visuals are included
bool media();

// Exits the window
void close();

SDL_Window* window = NULL;

SDL_Surface* screenSurface = NULL;

SDL_Surface* startscreen = NULL;

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

    startscreen = SDL_LoadBMP("starting_screen.bmp");

     if (startscreen == NULL){
       printf("Unable to load pcture %s! Error: %s\n", SDL_GetError() );
       success = false;
     }
   return success;
  }


  void close(){
    SDL_FreeSurface(startscreen);
    startscreen = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();

 

  }

  int main(int argc, char* args[]){

  // Makes sure that all of the startig requirments are met, else returs errors	  
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

	while(!quit){
	  while( SDL_PollEvent( &e ) != 0 ){
	 // checks for when the quit button is clicked, then exits out of the window 
         if (e.type == SDL_QUIT){
	      quit = true;
	}
      }                      
	  SDL_BlitSurface( startscreen, NULL, screenSurface, NULL );                                                 
	  SDL_UpdateWindowSurface( window );
	}
      }
    }
    close();
    return 0;
  }
